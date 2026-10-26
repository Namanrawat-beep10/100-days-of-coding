/*
Question 107: Find the previous greater element for every array element using brute force.
*/

#include <stdio.h>
int main(){int n; scanf("%d",&n); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); for(int i=0;i<n;i++){int ans=-1; for(int j=i-1;j>=0;j--) if(a[j]>a[i]){ans=a[j];break;} printf("%d%s",ans,i==n-1?"":", ");} return 0;}
