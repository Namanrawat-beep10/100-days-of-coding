/*
Question 114: Find the length of the longest substring without repeating characters.
*/

#include <stdio.h>
#include <string.h>
int main(){char s[1000]; fgets(s,sizeof(s),stdin); s[strcspn(s,"\n")]=0; int last[256]; for(int i=0;i<256;i++)last[i]=-1; int start=0,best=0; for(int i=0;s[i];i++){unsigned char c=s[i]; if(last[c]>=start)start=last[c]+1; last[c]=i; int len=i-start+1; if(len>best)best=len;} printf("%d",best); return 0;}
