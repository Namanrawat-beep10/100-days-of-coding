#include<stdio.h>

void sum(int x,int y){
 printf("sum of two num is:%d",x+y);
}

int main(){

int a,b;
printf("enter the value of a:.");
scanf("%d", &a);
printf("enter the value of b:.");
scanf("%d", &b);

sum(a,b);
return 0;
}
