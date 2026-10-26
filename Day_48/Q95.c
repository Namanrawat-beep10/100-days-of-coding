/*
Q95: Check if one string is a rotation of another.
*/

#include <stdio.h>
#include <string.h>
int main(){char a[250],b[250],t[500];fgets(a,sizeof(a),stdin);fgets(b,sizeof(b),stdin);a[strcspn(a,"\n")]=0;b[strcspn(b,"\n")]=0;if(strlen(a)!=strlen(b)){printf("Not rotation");return 0;}strcpy(t,a);strcat(t,a);printf(strstr(t,b)?"Rotation":"Not rotation");return 0;}
