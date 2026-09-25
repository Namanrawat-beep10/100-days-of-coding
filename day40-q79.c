/* Q79: Perform diagonal traversal of a matrix (anti-diagonals from top-left to bottom-right). */
#include <stdio.h>

int main() {
    int a[20][20],r,c,i,j,s;
    scanf("%d%d",&r,&c);
    for(i=0;i<r;i++)for(j=0;j<c;j++)scanf("%d",&a[i][j]);
    for(s=0;s<=r+c-2;s++) {
        for(i=0;i<r;i++) {
            j=s-i;
            if(j>=0&&j<c)printf("%d ",a[i][j]);
        }
    }
    return 0;
}
