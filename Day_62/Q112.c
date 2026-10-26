/*
Question 112: Find the maximum sum of a contiguous subarray using Kadane's algorithm.
*/

#include <stdio.h>
int main(){int n; scanf("%d",&n); long long x,cur,best; scanf("%lld",&x); cur=best=x; for(int i=1;i<n;i++){scanf("%lld",&x); cur=(cur+x>x)?cur+x:x; if(cur>best)best=cur;} printf("%lld",best); return 0;}
