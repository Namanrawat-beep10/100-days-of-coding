/*Q11.Write a program to input an integer and check whether it is even or odd using if–else.*/

#include<stdio.h>
int main(){

int num;

printf("Enter the value of number:.");
scanf("%d", & num);

if(num %2==0){
printf("EVEN NUM");
}
else{
printf("ODD NUM");
}

return 0;
}
