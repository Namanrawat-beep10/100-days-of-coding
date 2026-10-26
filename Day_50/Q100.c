/*
Q100: Print all sub-strings of a string.
*/

#include <stdio.h>
#include <string.h>
int main(){char s[200];fgets(s,sizeof(s),stdin);s[strcspn(s,"\n")]=0;int n=strlen(s),first=1;for(int i=0;i<n;i++)for(int len=1;i+len<=n;len++){if(!first)printf(",");for(int k=i;k<i+len;k++)putchar(s[k]);first=0;}return 0;}
