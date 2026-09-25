/*Q43.Write a program to check if a number is a strong number.*/

#include <stdio.h>

int main()
{
    int n, original, rem, i, fact, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    original = n;

    while(n > 0)
    {
        rem = n % 10;
        fact = 1;

        for(i = 1; i <= rem; i++)
            fact = fact * i;

        sum = sum + fact;
        n = n / 10;
    }

    if(sum == original)
        printf("Strong Number");
    else
        printf("Not Strong Number");

    return 0;
}
