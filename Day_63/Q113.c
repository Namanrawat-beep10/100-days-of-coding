/*
Question 113: Find the kth smallest element in an integer array.
*/

#include <stdio.h>
int main(){int n,k; scanf("%d",&n); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); scanf("%d",&k); for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++) if(a[j]<a[i]){int t=a[i];a[i]=a[j];a[j]=t;} if(k>=1&&k<=n)printf("%d",a[k-1]); return 0;}
