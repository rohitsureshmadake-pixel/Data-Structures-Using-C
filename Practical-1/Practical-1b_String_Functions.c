#include <stdio.h>
#include <string.h>
#include <ctype.h>

void strrev_c(char s[]) {
    int i=0,j=strlen(s)-1; char t;
    while(i<j) { t=s[i]; s[i++]=s[j]; s[j--]=t; }
}

int main() {
    char a[100]="Hello", b[100]="World", c[100];
    char *p;

    printf("strcmp: %d\n",strcmp(a,b));
    printf("strlen: %zu\n",strlen(a));

    strcpy(c,a);
    printf("strcpy: %s\n",c);

    strrev_c(c);
    printf("strrev: %s\n",c);

    strcpy(c,a);
    strcat(c,b);
    printf("strcat: %s\n",c);

    for(int i=0;c[i];i++) c[i]=toupper(c[i]);
    printf("strupr: %s\n",c);

    for(int i=0;c[i];i++) c[i]=tolower(c[i]);
    printf("strlwr: %s\n",c);

    p=strchr(c,'l');
    printf("strchr: %s\n",p);

    return 0;
}
