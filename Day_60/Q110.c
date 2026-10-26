/*
Question 110: Print the maximum element in each subarray/window of size k.
*/

#include <stdio.h>
int main(){int n,k; scanf("%d",&n); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); scanf("%d",&k); for(int i=0;i<=n-k;i++){int m=a[i]; for(int j=i+1;j<i+k;j++) if(a[j]>m)m=a[j]; printf("%d%s",m,i==n-k?"":" ");} return 0;}
