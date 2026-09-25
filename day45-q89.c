/* Q89: Count frequency of a given character in a string. */
#include <stdio.h>

int main() {
    char s[500],ch;
    int i=0,count=0;
    fgets(s,sizeof(s),stdin);
    scanf("%c",&ch);
    while(s[i]!='\0'&&s[i]!='\n') {
        if(s[i]==ch)count++;
        i++;
    }
    printf("%d",count);
    return 0;
}
