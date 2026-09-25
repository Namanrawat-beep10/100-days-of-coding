/* Q70: Rotate an array to the right by k positions. */
#include <stdio.h>

int main() {
    int a[100],n,k,i,j,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    scanf("%d",&k);
    if(n>0)k%=n;
    for(j=0;j<k;j++) {
        t=a[n-1];
        for(i=n-1;i>0;i--)a[i]=a[i-1];
        a[0]=t;
    }
    for(i=0;i<n;i++)printf("%d%s",a[i],i==n-1?"":" ");
    return 0;
}
