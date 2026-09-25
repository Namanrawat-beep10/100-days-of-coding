/* Q65: Search in a sorted array using binary search. */
#include <stdio.h>

int main() {
    int a[100],n,i,key,l=0,r,mid,index=-1;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    scanf("%d",&key);
    r=n-1;
    while(l<=r) {
        mid=(l+r)/2;
        if(a[mid]==key) {
            index=mid;
            break;
        }
        if(a[mid]<key)l=mid+1;
        else r=mid-1;
    }
    if(index==-1)printf("-1");
    else printf("Found at index %d",index);
    return 0;
}
