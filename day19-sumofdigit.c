/*Q38.Write a program to find the sum of digits of a number.*/

#include <stdio.h>

int main()
{
    int n, rem, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    while(n > 0)
    {
        rem = n % 10;
        sum = sum + rem;
        n = n / 10;
    }

    printf("Sum = %d", sum);

    return 0;
}
