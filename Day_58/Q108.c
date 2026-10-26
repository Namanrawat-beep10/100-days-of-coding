/*
Question 108: Print product of array except self for every position.
*/

#include <stdio.h>
int main(){int n; scanf("%d",&n); long long a[n]; for(int i=0;i<n;i++) scanf("%lld",&a[i]); for(int i=0;i<n;i++){long long p=1; for(int j=0;j<n;j++) if(i!=j) p*=a[j]; printf("%lld%s",p,i==n-1?"":" ");} return 0;}
