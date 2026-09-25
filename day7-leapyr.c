/*Q12.Write a program to input a year and check whether it is a leap year or not using conditional statements.*/


#include<stdio.h>
int main(){

int yr;
printf("Enter the value of yr:.");
scanf("%d", &yr);

if(yr %4 == 0){
printf("Leap year");
}
else{
printf("Non leap year");
}

return 0;
}
