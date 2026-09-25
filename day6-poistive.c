/*Q12 .Write a program to input an integer and check whether it is positive, negative or zero using nested if–else.*/

#include<stdio.h>
int main(){

int num;

printf("Enter the value of num:.");
scanf("%d", &num);

if(num>0){
printf("Num is positive");
}
else if(num=0){
printf("ZERO");
}
else{
printf("Num is negative");
}
return 0;
}
