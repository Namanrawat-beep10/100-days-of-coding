/* Q76: Check if a matrix is symmetric. */
#include <stdio.h>

int main() {
    int a[20][20],r,c,i,j,ok=1;
    scanf("%d%d",&r,&c);
    for(i=0;i<r;i++)for(j=0;j<c;j++)scanf("%d",&a[i][j]);
    if(r!=c)ok=0;
    else for(i=0;i<r;i++)for(j=i+1;j<c;j++)if(a[i][j]!=a[j][i])ok=0;
    printf(ok?"True":"False");
    return 0;
}
