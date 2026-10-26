/*
Question 109: Find the maximum sum among all subarrays of size k.
*/

#include <stdio.h>
int main(){int n,k; scanf("%d",&n); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); scanf("%d",&k); long long sum=0,best; for(int i=0;i<k;i++) sum+=a[i]; best=sum; for(int i=k;i<n;i++){sum+=a[i]-a[i-k]; if(sum>best) best=sum;} printf("%lld",best); return 0;}
