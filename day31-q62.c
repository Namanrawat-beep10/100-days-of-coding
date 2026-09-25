/* Q62: Reverse an array without taking extra space. */
#include <stdio.h>

int main() {
    int a[100],n,i,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n/2;i++) {
        t=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=t;
    }
    for(i=0;i<n;i++)printf("%d%s",a[i],i==n-1?"":" ");
    return 0;
}
