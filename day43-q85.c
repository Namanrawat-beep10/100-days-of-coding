/* Q85: Reverse a string. */
#include <stdio.h>

int main() {
    char s[500],t;
    int i=0,n=0;
    fgets(s,sizeof(s),stdin);
    while(s[n]!='\0'&&s[n]!='\n')n++;
    for(i=0;i<n/2;i++) {
        t=s[i];
        s[i]=s[n-1-i];
        s[n-1-i]=t;
    }
    s[n]='\0';
    printf("%s",s);
    return 0;
}
