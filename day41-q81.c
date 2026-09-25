/* Q81: Count characters in a string without using built-in length functions. */
#include <stdio.h>

int main() {
    char s[500];
    int n=0;
    if(!fgets(s,sizeof(s),stdin))return 0;
    while(s[n]!='\0'&&s[n]!='\n')n++;
    printf("%d",n);
    return 0;
}
