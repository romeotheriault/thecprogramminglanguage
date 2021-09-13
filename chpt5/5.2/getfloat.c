#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* getfloat: get next float from input into *pn */
int getfloat(float *pn)
{
    int c, sign;
    double power;
    while (isspace(c = getch())) /* skip white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);  /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 :1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    if (c == '.') {
        c = getch();
    }
    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
        power *= 10;
        //printf("pn: %f - f: %f\n", *pn, power);
    }
    *pn = sign * *pn / power;
    if (c != EOF)
        ungetch(c);
    return c;
}

int main(void)
{
    int j;
    float num;
    if ((j = getfloat(&num)) == EOF) {
        printf("End of file\n");
    } else if (j == 0) {
        printf("It's not a number\n");
    } else {
        printf("%f\n", num);
    }
}