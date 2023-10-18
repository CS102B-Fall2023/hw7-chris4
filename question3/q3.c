#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);

int main(){
        char s[50], t[50];
        scanf("%s %s", s, t);
        strend(s,t);
        if (strend(s,t) == 1){
                printf("1\n");
        }
        else {
                printf("0\n");
        }



        return 0;
}



int strend(char *s, char *t){
        s = s + (strlen(s) - strlen(t));
        for ( ; t != '\0'; t++, s++){
                if (*t == *s){
                        return 1;
                }
                else{
                        return 0;
                }
        }
        return 0;
}
