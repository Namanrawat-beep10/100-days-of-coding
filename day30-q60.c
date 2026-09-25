/* Q60: Count positive, negative, and zero elements in an array. */
#include <stdio.h>

int main() {
    int n,i,x,p=0,neg=0,z=0;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        if(x>0)p++;
        else if(x<0)neg++;
        else z++;
    }
    printf("Positive=%d, Negative=%d, Zero=%d",p,neg,z);
    return 0;
}
