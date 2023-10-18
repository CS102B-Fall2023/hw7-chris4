#include <stdio.h>
#include <ctype.h>

int getch();
void ungetch(int);

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch (int c)
{
    if (bufp >= BUFSIZE){
        printf("ungetch: too many characters\n");
    }
    else{ 
        buf[bufp++] = c;
    }
}

float getfloat(float *p)
{
    int c, sign, r;
    int d = 0;
    while (isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 :1;

    if (c == '+' || c == '-'){
        c = getch();
    }

    for (*p = 0; isdigit(c); c = getch()){
       // d++;
        *p = 10 * *p + (c - '0');
       // if ( c = '.'){
         //       d = r;
       // }
    }
        
    *p = (*p * sign) / d;

    if (c != EOF){
        ungetch(c);
    }

    return c;
}

int main(){
        int c, p;
        getfloat(p);
        printf("p = %f\n", p);

        return 0;
}

