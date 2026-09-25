/*Q7.Write a program to swap two numbers without using a third variable.*/

#include<stdio.h>
int main(){

int a,b;
printf("Enter the value of a:.");
scanf("%d", &a);
printf("Enter the value of b:.");
scanf("%d", &b);

printf("\nBefore swappping: a = %d, b= %d\n", a,b);

a=a+b;
b=a-b;
a=a-b;

printf("After swapping: a =%d, n= %d\n", a,b);

return 0;
}
