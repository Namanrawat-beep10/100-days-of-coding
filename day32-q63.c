/* Q63: Merge two arrays. */
#include <stdio.h>

int main() {
    int a[200],n,m,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    scanf("%d",&m);
    for(i=0;i<m;i++)scanf("%d",&a[n+i]);
    for(i=0;i<n+m;i++)printf("%d%s",a[i],i==n+m-1?"":" ");
    return 0;
}
