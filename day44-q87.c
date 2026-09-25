/* Q87: Count spaces, digits, and special characters in a string. */
#include <stdio.h>

int main() {
    char s[500],ch;
    int i=0,sp=0,d=0,special=0;
    fgets(s,sizeof(s),stdin);
    while((ch=s[i++])!='\0'&&ch!='\n') {
        if(ch==' ')sp++;
        else if(ch>='0'&&ch<='9')d++;
        else if(!((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')))special++;
    }
    printf("Spaces=%d, Digits=%d, Special=%d",sp,d,special);
    return 0;
}
