/* Q75: Add two matrices. */
#include <stdio.h>

int main() {
    int a[20][20],b[20][20],r,c,i,j;
    scanf("%d%d",&r,&c);
    for(i=0;i<r;i++)for(j=0;j<c;j++)scanf("%d",&a[i][j]);
    for(i=0;i<r;i++)for(j=0;j<c;j++)scanf("%d",&b[i][j]);
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++)printf("%d%s",a[i][j]+b[i][j],j==c-1?"":" ");
        printf("\n");
    }
    return 0;
}
