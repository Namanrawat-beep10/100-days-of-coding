/* Q93: Check if two strings are anagrams of each other. */
#include <stdio.h>

int main() {
    char a[500],b[500];
    int f[256]= {
        0
    }
    ,i=0,ok=1;
    fgets(a,sizeof(a),stdin);
    fgets(b,sizeof(b),stdin);
    while(a[i]!='\0'&&a[i]!='\n') {
        f[(unsigned char)a[i]]++;
        i++;
    }
    i=0;
    while(b[i]!='\0'&&b[i]!='\n') {
        f[(unsigned char)b[i]]--;
        i++;
    }
    for(i=0;i<256;i++)if(f[i]!=0) {
        ok=0;
        break;
    }
    printf(ok?"Anagrams":"Not anagrams");
    return 0;
}
