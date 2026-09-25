/* Q90: Toggle case of each character in a string. */
#include <stdio.h>

int main() {
    char s[500];
    int i=0;
    fgets(s,sizeof(s),stdin);
    while(s[i]!='\0') {
        if(s[i]>='a'&&s[i]<='z')s[i]-=32;
        else if(s[i]>='A'&&s[i]<='Z')s[i]+=32;
        i++;
    }
    printf("%s",s);
    return 0;
}
