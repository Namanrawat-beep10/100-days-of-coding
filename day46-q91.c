/* Q91: Remove all vowels from a string. */
#include <stdio.h>

int main() {
    char s[500],ch;
    int i=0;
    fgets(s,sizeof(s),stdin);
    while((ch=s[i++])!='\0') {
        if(!(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'))printf("%c",ch);
    }
    return 0;
}
