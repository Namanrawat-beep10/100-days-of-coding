/* Q84: Convert a lowercase string to uppercase without using built-in functions. */
#include <stdio.h>

int main() {
    char s[500];
    int i=0;
    fgets(s,sizeof(s),stdin);
    while(s[i]!='\0') {
        if(s[i]>='a'&&s[i]<='z')s[i]-=32;
        i++;
    }
    printf("%s",s);
    return 0;
}
