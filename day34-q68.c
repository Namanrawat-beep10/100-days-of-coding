/* Q68: Delete an element from an array (first occurrence of the given value). */
#include <stdio.h>

int main() {
    int a[100],n,i,x,pos=-1;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    scanf("%d",&x);
    for(i=0;i<n;i++)if(a[i]==x) {
        pos=i;
        break;
    }
    if(pos!=-1) {
        for(i=pos;i<n-1;i++)a[i]=a[i+1];
        n--;
    }
    for(i=0;i<n;i++)printf("%d%s",a[i],i==n-1?"":" ");
    return 0;
}
