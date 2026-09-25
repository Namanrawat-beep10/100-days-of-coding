/* Q74: Find the transpose of a matrix. */
#include <stdio.h>

int main() {
    int a[20][20],r,c,i,j;
    scanf("%d%d",&r,&c);
    for(i=0;i<r;i++)for(j=0;j<c;j++)scanf("%d",&a[i][j]);
    for(j=0;j<c;j++) {
        for(i=0;i<r;i++)printf("%d%s",a[i][j],i==r-1?"":" ");
        printf("\n");
    }
    return 0;
}
