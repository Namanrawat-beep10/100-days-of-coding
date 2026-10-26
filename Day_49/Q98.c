/*
Q98: Print initials of a name with the surname displayed in full.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){char s[500],copy[500],*w[50];int n=0;fgets(s,sizeof(s),stdin);s[strcspn(s,"\n")]=0;strcpy(copy,s);char *p=strtok(copy," ");while(p&&n<50){w[n++]=p;p=strtok(NULL," ");}for(int i=0;i<n-1;i++)printf("%c.",toupper((unsigned char)w[i][0]));if(n)printf(" %s",w[n-1]);return 0;}
