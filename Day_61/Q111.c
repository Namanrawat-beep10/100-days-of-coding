/*
Question 111: Print the first negative integer in each subarray of size k, or 0 if none.
*/

#include <stdio.h>
int main(){int n,k; scanf("%d",&n); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); scanf("%d",&k); for(int i=0;i<=n-k;i++){int ans=0; for(int j=i;j<i+k;j++) if(a[j]<0){ans=a[j];break;} printf("%d%s",ans,i==n-k?"":" ");} return 0;}
