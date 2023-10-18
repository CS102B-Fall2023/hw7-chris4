#include <stdio.h>
#include <ctype.h>
#include <math.h>

// K&R Pg. 97
int getch();
void ungetch(int);

#define BUFSIZE 100

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       // next free position in buf

int getch(void) // get a (possibly pushed back) charater
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push character back on input
{
    if (bufp >= BUFSIZE)
        printf("ungetch:too many characters\n");
    else
        buf[bufp++] = c;
}

// getint: get next integer from input into *pn
float getfloat(float *pn)
{
    int c, sign, r;
    int d =0;

    while (isspace(c = getch())) // skip white space
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); // it's not a number
        return 0;
    }
    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();

    for (*pn = 0, d = 1, r = 0; isdigit(c) || c == '.'; c = getch(), r++){
        *pn = 10 * *pn + (c - '0');

        if ( c= '.'){
        do{
        d = d * 10;
        r--;
         } while (r>0);
        }
       }

    *pn = (sign * *pn) / d ;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main()
{
    int c, pn;
    getfloat(&pn);
    printf("pn=%d\n", pn);
    return 0;
}

