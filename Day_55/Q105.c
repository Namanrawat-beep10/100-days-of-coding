/*
Question 105: Find the majority element occurring strictly more than n/2 times; print -1 if none.
*/

#include <stdio.h>
int main(){int n; scanf("%d",&n); int a[n],cand=0,count=0; for(int i=0;i<n;i++){scanf("%d",&a[i]); if(count==0){cand=a[i];count=1;} else if(a[i]==cand) count++; else count--;} count=0; for(int i=0;i<n;i++) if(a[i]==cand) count++; if(count>n/2) printf("%d",cand); else printf("-1"); return 0;}
