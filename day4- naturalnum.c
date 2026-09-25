/*Q8.Write a program to find and display the sum of the first n natural numbers.*/

#include <stdio.h>

int main(void) {
    long long n, sum;

    scanf("%lld", &n);

    sum = n * (n + 1) / 2;

    printf("Sum=%lld\n", sum);

    return 0;
}
