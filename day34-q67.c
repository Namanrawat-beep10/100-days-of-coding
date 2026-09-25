/* Q67: Insert an element in an array at a given position (0-based index). */
#include <stdio.h>

int main() {
    int a[101],n,i,x,pos;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    scanf("%d%d",&x,&pos);
    if(pos<0||pos>n)return 0;
    for(i=n;i>pos;i--)a[i]=a[i-1];
    a[pos]=x;
    n++;
    for(i=0;i<n;i++)printf("%d%s",a[i],i==n-1?"":" ");
    return 0;
}
