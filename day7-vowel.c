/*Q14.Write a program to input a character and check whether it is a vowel or consonant using if–else.*/


#include<stdio.h>
int main(){

char abet;
printf("enter the value of abet:.");
scanf(" %c",& abet);

if(abet=='a' || abet=='e' || abet=='i' || abet=='o' || abet=='u' || abet=='A' || abet=='E' || abet=='I' || abet=='O' || abet=='U'){
printf("vowel");
}
else{
printf("consonent");
}

return 0;
}
