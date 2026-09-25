/*Q4)Write a program to calculate the area and circumference of a circle given its radius.*/
#include<stdio.h>
int main(){

int a;
float area,circumference;

printf("Enter the value of a:.");
scanf("%d",&a);

area=3.14*a*a;
circumference=2*3.14*a;

printf("The area of circle is=%f", 3.14*a*a);
printf("\nThe circumference of circle is=%f", 2*3.14*a);

return 0;
}
