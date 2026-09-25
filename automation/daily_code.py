import os, re, json, subprocess, sys
from pathlib import Path
from playwright.sync_api import sync_playwright
from google import genai
from google.genai import types

URL='https://maitysoumik.github.io/basic-coding-with-c/'
ROOT=Path(__file__).resolve().parents[1]

def next_day():
    days=[]
    for p in ROOT.glob('day*-q*.c'):
        m=re.match(r'day(\d+)-q(\d+)\.c$',p.name,re.I)
        if m: days.append(int(m.group(1)))
    return max(days, default=47)+1

def fetch_text():
    with sync_playwright() as pw:
        browser=pw.chromium.launch(headless=True)
        page=browser.new_page()
        page.goto(URL, wait_until='networkidle', timeout=120000)
        text=page.locator('body').inner_text()
        browser.close()
        return text

def extract_question(text,q):
    # Locate Q<number>, then stop at the next question heading.
    pat=re.compile(rf'Q{q}\b.*?(?=\n[^\n]*Q{q+1}\b|\Z)', re.S|re.I)
    m=pat.search(text)
    if not m: raise RuntimeError(f'Could not find Q{q} on challenge page')
    block=m.group(0).strip()
    # Keep question + samples; remove obvious UI labels only.
    block=re.sub(r'\nShow Sample Test Cases\s*', '\n', block, flags=re.I)
    return block

def generate(client, day, q, question):
    prompt=f'''You are solving Day {day}, Q{q} of a beginner C programming challenge.
Return ONLY one complete C source file, no Markdown fences and no explanation.
Requirements:
- Put the exact assignment below at the top in a /* ... */ comment.
- Use standard C (C11), simple beginner-readable code, normal indentation.
- Match any shown sample input/output exactly; do not print prompts like "Enter n".
- Do not use non-standard libraries.
- End main with return 0.

ASSIGNMENT:\n{question}\n'''
    resp=client.models.generate_content(
        model=os.getenv('GEMINI_MODEL','gemini-3.8-flash'),
        contents=prompt,
        config=types.GenerateContentConfig(temperature=0.1),
    )
    code=(resp.text or '').strip()
    code=re.sub(r'^```(?:c)?\s*|\s*```$','',code,flags=re.S|re.I).strip()+"\n"
    if '#include' not in code or 'main' not in code: raise RuntimeError(f'Invalid generated code for Q{q}')
    return code

def compile_file(path):
    out=path.with_suffix('.out')
    r=subprocess.run(['gcc','-std=c11','-Wall','-Wextra','-pedantic',str(path),'-o',str(out)],capture_output=True,text=True)
    if out.exists(): out.unlink()
    if r.returncode: raise RuntimeError(f'Compilation failed for {path.name}:\n{r.stderr}')

def main():
    day=next_day()
    if day>100:
        print('Challenge already complete.'); return
    q1=day*2-1; q2=day*2
    text=fetch_text()
    questions={q1:extract_question(text,q1), q2:extract_question(text,q2)}
    client=genai.Client(api_key=os.environ['GEMINI_API_KEY'])
    created=[]
    for q in (q1,q2):
        path=ROOT/f'day{day}-q{q}.c'
        if path.exists():
            print(f'{path.name} already exists; refusing to overwrite.'); sys.exit(2)
        path.write_text(generate(client,day,q,questions[q]),encoding='utf-8',newline='\n')
        compile_file(path); created.append(path)
    print('Created:', ', '.join(p.name for p in created))

if __name__=='__main__': main()
