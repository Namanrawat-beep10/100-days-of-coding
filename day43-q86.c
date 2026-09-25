/* Q86: Check if a string is a palindrome. */
#include <stdio.h>

int main() {
    char s[500];
    int i,n=0,ok=1;
    fgets(s,sizeof(s),stdin);
    while(s[n]!='\0'&&s[n]!='\n')n++;
    for(i=0;i<n/2;i++)if(s[i]!=s[n-1-i]) {
        ok=0;
        break;
    }
    printf(ok?"Palindrome":"Not palindrome");
    return 0;
}
