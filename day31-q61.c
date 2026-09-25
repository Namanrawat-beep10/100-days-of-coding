/* Q61: Search for an element in an array using linear search. */
#include <stdio.h>

int main() {
    int a[100],n,i,key,index=-1;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    scanf("%d",&key);
    for(i=0;i<n;i++)if(a[i]==key) {
        index=i;
        break;
    }
    if(index==-1)printf("-1");
    else printf("Found at index %d",index);
    return 0;
}
