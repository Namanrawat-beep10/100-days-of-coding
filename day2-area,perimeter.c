/*Q3
Write a program to calculate the area and perimeter of a rectangle given its length and breadth.*/
#include<stdio.h>
int main(){

int a,b,area,perimeter;

printf("Enter the value of a:.");
scanf("%d", & a);
printf("Enter the value of b:.");
scanf("%d", & b);

area=a*b;
perimeter=2*(a+b);

printf("The area of two num is=%d",a*b);
printf("\nThe perimeter of two num is=%d", 2*(a+b));

return 0;
}
