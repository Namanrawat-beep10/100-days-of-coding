/* Q72: Find the sum of all elements in a matrix. */
#include <stdio.h>

int main() {
    int r,c,i,j,x,sum=0;
    scanf("%d%d",&r,&c);
    for(i=0;i<r;i++)for(j=0;j<c;j++) {
        scanf("%d",&x);
        sum+=x;
    }
    printf("%d",sum);
    return 0;
}
