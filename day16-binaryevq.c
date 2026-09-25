/*Q31.Write a program to take a number as input and print its equivalent binary representation.*/

#include <stdio.h>

int main()
{
    int n, rem, binary = 0, place = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    while(n > 0)
    {
        rem = n % 2;
        binary = binary + rem * place;
        place = place * 10;
        n = n / 2;
    }

    printf("Binary = %d", binary);

    return 0;
}
