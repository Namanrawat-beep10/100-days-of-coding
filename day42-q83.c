/* Q83: Count vowels and consonants in a string. */
#include <stdio.h>

int main() {
    char s[500],ch;
    int i=0,v=0,c=0;
    fgets(s,sizeof(s),stdin);
    while((ch=s[i++])!='\0') {
        if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')) {
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')v++;
            else c++;
        }
    }
    printf("Vowels=%d, Consonants=%d",v,c);
    return 0;
}
