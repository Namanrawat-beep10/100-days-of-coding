/* Q94: Find the longest word in a sentence. */
#include <stdio.h>

int main() {
    char s[500];
    int i=0,start=0,len=0,bestStart=0,bestLen=0;
    fgets(s,sizeof(s),stdin);
    while(1) {
        if(s[i]!=' '&&s[i]!='\n'&&s[i]!='\0') {
            if(len==0)start=i;
            len++;
        } else
        {
            if(len>bestLen) {
                bestLen=len;
                bestStart=start;
            }
            len=0;
            if(s[i]=='\0'||s[i]=='\n')break;
        }
        i++;
    }
    for(i=0;i<bestLen;i++)printf("%c",s[bestStart+i]);
    return 0;
}
