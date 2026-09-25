/* Q73: Find the sum of each row of a matrix and store it in an array. */
#include <stdio.h>

int main() {
    int a[20][20],sum[20]= {
        0
    }
    ,r,c,i,j;
    scanf("%d%d",&r,&c);
    for(i=0;i<r;i++)for(j=0;j<c;j++) {
        scanf("%d",&a[i][j]);
        sum[i]+=a[i][j];
    }
    for(i=0;i<r;i++)printf("%d%s",sum[i],i==r-1?"":" ");
    return 0;
}
