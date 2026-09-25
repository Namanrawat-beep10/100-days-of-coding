/*Q5.Write a program to convert temperature from Celsius to Fahrenheit.*/
#include<stdio.h>

int main(){

int a,b,c;

printf("Enter the value of a:.");
scanf("%d", & a);
printf("Enter the value of b:..");
scanf("%d", & b);

printf("\nBefore swapping: a = %d, b = %d\n", a,b);

c=a;
a=b;
b=c;

printf("After swappping: a =%d, b = %d\n", a,b);

return 0;
}
