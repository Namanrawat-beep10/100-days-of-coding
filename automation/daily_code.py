import os
import re
import subprocess
import time
import random
from pathlib import Path

from playwright.sync_api import sync_playwright
from google import genai
from google.genai import types


URL = "https://maitysoumik.github.io/basic-coding-with-c/"
ROOT = Path(__file__).resolve().parents[1]


def next_day():
    days = []

    for p in ROOT.glob("day*-q*.c"):
        m = re.match(r"day(\d+)-q(\d+)\.c$", p.name, re.I)

        if m:
            days.append(int(m.group(1)))

    return max(days, default=47) + 1


def fetch_text():
    with sync_playwright() as pw:
        browser = pw.chromium.launch(headless=True)

        page = browser.new_page()
        page.goto(
            URL,
            wait_until="networkidle",
            timeout=120000
        )

        text = page.locator("body").inner_text()

        browser.close()

        return text


def extract_question(text, q):
    # Find Q<number> and stop when the next question begins.
    pattern = re.compile(
        rf"Q{q}\b.*?(?=\n[^\n]*Q{q + 1}\b|\Z)",
        re.S | re.I
    )

    match = pattern.search(text)

    if not match:
        return None

    block = match.group(0).strip()

    # Remove website UI text.
    block = re.sub(
        r"\nShow Sample Test Cases\s*",
        "\n",
        block,
        flags=re.I
    )

    return block


def generate(client, day, q, question):
    prompt = f"""
You are solving Day {day}, Q{q} of a beginner C programming challenge.

Return ONLY one complete C source file.
Do not use Markdown code fences.
Do not provide an explanation outside the C program.

Requirements:
- Put the exact assignment below at the top in a C block comment.
- Use standard C11.
- Keep the solution beginner-friendly and readable.
- Use normal indentation.
- Match the sample input/output exactly.
- Do not print prompts such as "Enter a number".
- Do not use non-standard libraries.
- main() must end with return 0.

ASSIGNMENT:

{question}
"""max_attempts = 6
    for attempt in range(1, max_attempts + 1):
        try:
            print(
                f"Calling Gemini for Q{q} "
                f"(attempt {attempt}/{max_attempts})..."
            )

            response = client.models.generate_content(
                model=os.getenv(
                    "GEMINI_MODEL",
                    "gemini-3.5-flash"
                ),
                contents=prompt,
                config=types.GenerateContentConfig(
                    temperature=0.1
                ),
            )

            code = (response.text or "").strip()

            code = re.sub(
                r"^```(?:c)?\s*|\s*```$",
                "",
                code,
                flags=re.S | re.I
            ).strip()

            code += "\n"

            if "#include" not in code or "main" not in code:
                raise RuntimeError(
                    f"Gemini returned invalid C code for Q{q}"
                )

            return code

        except Exception as error:
            print(
                f"Gemini attempt {attempt} failed: {error}"
            )

            if attempt == max_attempts:
                raise

            # Increasing delay between attempts.
            wait = (2 ** attempt) + random.randint(1, 5)

            print(
                f"Temporary Gemini failure. "
                f"Retrying in {wait} seconds..."
            )

            time.sleep(wait)


def compile_file(path):
    output_file = path.with_suffix(".out")

    result = subprocess.run(
        [
            "gcc",
            "-std=c11",
            "-Wall",
            "-Wextra",
            "-pedantic",
            str(path),
            "-o",
            str(output_file),
        ],
        capture_output=True,
        text=True,
    )

    if output_file.exists():
        output_file.unlink()

    if result.returncode != 0:
        raise RuntimeError(
            f"Compilation failed for {path.name}:\n"
            f"{result.stderr}"
        )


def main():
    day = next_day()

    if day > 100:
        print("100 Days of Code challenge is already complete.")
        return

    q1 = day * 2 - 1
    q2 = day * 2

    print(f"Checking Day {day}: Q{q1} and Q{q2}")

    text = fetch_text()

    question1 = extract_question(text, q1)
    question2 = extract_question(text, q2)

    # UPES has not published today's questions yet.
    if question1 is None or question2 is None:
        print(
            f"Day {day} is not available yet. "
            f"Waiting for Q{q1} and Q{q2}."
        )
        return

    print(
        f"Day {day} found. "
        f"Generating Q{q1} and Q{q2}..."
    )

    questions = {
        q1: question1,
        q2: question2,
    }

    api_key = os.environ.get("GEMINI_API_KEY")

    if not api_key:
        raise RuntimeError(
            "GEMINI_API_KEY GitHub secret is missing."
        )

    client = genai.Client(api_key=api_key)

    created = []

    try:
        for q in (q1, q2):
            path = ROOT / f"day{day}-q{q}.c"

            if path.exists():
                raise RuntimeError(
                    f"{path.name} already exists. "
                    "Refusing to overwrite it."
                )

            print(f"Generating {path.name}...")

            code = generate(
                client,
                day,
                q,
                questions[q]
            )

            path.write_text(
                code,
                encoding="utf-8",
                newline="\n"
            )

            created.append(path)

            print(f"Compiling {path.name}...")

            compile_file(path)

            print(f"{path.name} compiled successfully.")

    except Exception:
        # Never leave half of a day's submission behind.
        for path in created:
            if path.exists():
                path.unlink()

        raise

    print()
    print(
        f"Day {day} completed successfully: "
        + ", ".join(p.name for p in created)
    )


if __name__ == "__main__":
    main()
