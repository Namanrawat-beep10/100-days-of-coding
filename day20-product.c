/*Q39.Write a program to find the product of odd digits of a number.*/

#include <stdio.h>

int main()
{
    int n, rem, product = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    while(n > 0)
    {
        rem = n % 10;

        if(rem % 2 != 0)
            product = product * rem;

        n = n / 10;
    }

    printf("Product of odd digits = %d", product);

    return 0;
}
