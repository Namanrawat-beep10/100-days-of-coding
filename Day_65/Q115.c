/*
Question 115: Check whether two lowercase strings are anagrams.
*/

#include <stdio.h>
#include <string.h>
int main(){char a[1000],b[1000]; scanf("%999s %999s",a,b); int f[26]={0}; for(int i=0;a[i];i++)f[a[i]-'a']++; for(int i=0;b[i];i++)f[b[i]-'a']--; for(int i=0;i<26;i++)if(f[i]){printf("Not Anagram");return 0;} printf("Anagram"); return 0;}
