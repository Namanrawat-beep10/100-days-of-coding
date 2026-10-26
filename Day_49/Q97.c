/*
Q97: Print the initials of a name.
*/

#include <stdio.h>
#include <ctype.h>
int main(){char s[500];fgets(s,sizeof(s),stdin);if(s[0]&&s[0]!='\n')printf("%c.",toupper((unsigned char)s[0]));for(int i=1;s[i];i++)if(s[i-1]==' '&&s[i]!=' ')printf("%c.",toupper((unsigned char)s[i]));return 0;}
