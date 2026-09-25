/*Q33.Write a program to check if a number is an Armstrong number.*/

#include <stdio.h>

int main()
{
    int n, original, rem, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    original = n;

    while(n > 0)
    {
        rem = n % 10;
        sum = sum + rem * rem * rem;
        n = n / 10;
    }

    if(sum == original)
        printf("Armstrong Number");
    else
        printf("Not Armstrong Number");

    return 0;
}
