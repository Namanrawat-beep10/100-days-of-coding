/*Q17.Write a program to find the roots of a quadratic equation and categorize them.*/
#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, d, r1, r2;

    printf("Enter coefficients a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);

    d = b * b - 4 * a * c;

    if (d > 0)
    {
        r1 = (-b + sqrt(d)) / (2 * a);
        r2 = (-b - sqrt(d)) / (2 * a);

        printf("Roots are Real and Distinct\n");
        printf("Root 1 = %.2f\n", r1);
        printf("Root 2 = %.2f\n", r2);
    }
    else if (d == 0)
    {
        r1 = -b / (2 * a);

        printf("Roots are Real and Equal\n");
        printf("Root 1 = Root 2 = %.2f\n", r1);
    }
    else
    {
        printf("Roots are Complex and Imaginary\n");
    }

    return 0;
}

