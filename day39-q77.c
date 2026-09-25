/* Q77: Check if the elements on the main diagonal of a matrix are distinct. */
#include <stdio.h>

int main() {
    int a[20][20],r,c,i,j,k,ok=1;
    scanf("%d%d",&r,&c);
    for(i=0;i<r;i++)for(j=0;j<c;j++)scanf("%d",&a[i][j]);
    k=r<c?r:c;
    for(i=0;i<k;i++)for(j=i+1;j<k;j++)if(a[i][i]==a[j][j])ok=0;
    printf(ok?"True":"False");
    return 0;
}
