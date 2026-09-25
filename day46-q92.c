/* Q92: Find the first repeating lowercase alphabet in a string. */
#include <stdio.h>

int main() {
    char s[500];
    int seen[26]= {
        0
    }
    ,i=0;
    fgets(s,sizeof(s),stdin);
    while(s[i]!='\0'&&s[i]!='\n') {
        if(s[i]>='a'&&s[i]<='z') {
            if(seen[s[i]-'a']) {
                printf("%c",s[i]);
                return 0;
            }
            seen[s[i]-'a']=1;
        }
        i++;
    }
    printf("No repeating alphabet");
    return 0;
}
