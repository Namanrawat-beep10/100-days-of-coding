
/*Write a program to input two numbers and display their sum.
Input 1:
3 4
Output 1:
Sum = 7*/
#include<stdio.h>
int main(){
 int a,b;
 int sum=0;

 printf("Enter the value of a:.");
 scanf("%d", & a);
 printf("Enter the value of b:.");
 scanf("%d", & b);

 sum=a+b;
printf("the sum of two num is=%d",a+b);

return 0;
}
