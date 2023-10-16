#include <stdio.h>
#include <string.h>

void strcat1(char *s, char *t);

int main(){
        char s[100], t[100];
        scanf("%s %s", s, t);
        strcat1(s,t);
        printf("New string: %s\n", s);

        return 0;
}

void strcat1(char *s, char *t){
        s = s + (strlen(s));
        while (*s++ = *t++);
}
