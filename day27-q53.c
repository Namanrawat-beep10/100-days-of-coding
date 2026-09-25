/* Q53: Print diamond-like pattern with 1,3,5,7,9,7,5,3,1 stars. */
#include <stdio.h>

int main() {
    int i,j;
    for(i=1;i<=5;i++) {
        for(j=1;j<=2*i-1;j++)printf("*");
        printf("\n");
    }
    for(i=4;i>=1;i--) {
        for(j=1;j<=2*i-1;j++)printf("*");
        printf("\n");
    }
    return 0;
}
