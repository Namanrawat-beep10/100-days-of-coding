/*Q6.Write a program to convert temperature from Celsius to Fahrenheit.*/

#include<stdio.h>
int main(){

int cel,fahren;

printf("Enter the value of cel:.");
scanf("%d", & cel);

fahren=(cel*9/5)+32;
printf("The temp in fahren is=%d",fahren);

return 0;
}
