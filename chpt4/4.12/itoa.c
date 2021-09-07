#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXLEN 100

/* 
int i = 0;

void itoa (int num, char snum[])
{
    int remainder = 0;
    if (num > 0) {
        remainder = num % 10;
        itoa(num / 10, snum);
        //putchar(remainder + '0');
    }
    if (i == 0 && num < 1)
        ;
    else
        snum[i++] = remainder + '0';
}

int main(void)
{
    char snum[MAXLEN];
    memset(snum, '\0', MAXLEN);
    int num = 1024;
    itoa(num, snum);
    printf("%s\n", snum);
    memset(snum, '\0', MAXLEN);
    i = 0;
    num = 99999;
    itoa(num, snum);
    printf("%s\n", snum);
    memset(snum, '\0', MAXLEN);
    i = 0;
    num = 0;
    itoa(num, snum);
    printf("%s\n", snum);
    //itoa(num);
}

*/

static void _itoa (int n, char s[], int i)
{
    static bool negative = false;
    int remainder = 0;
    static int j = 0;
    if (i == 0 && n == 0) {
        s[i] = n + '0';
        return;
    }
    if (n < 0) {
        negative = true;
        n = n * -1;
    }
    if (n > 0) {
        remainder = n % 10;
        _itoa(n / 10, s, ++i);
    } else {
        return;
    }
    if (negative == true) {
        s[j++] = '-';
        negative = false;
    }
    if (i > 0) {
        s[j++] = remainder + '0';
    }
    if (i == 1)
        j = 0;
}

void itoa (int n, char s[])
{
    int i = 0;
    _itoa(n, s, i);
}

int main (void)
{
    int n = -1230;
    char s[MAXLEN];
    memset(s, '\0', MAXLEN);
    itoa(n, s);
    printf("%s\n", s);
    n = 999889;
    memset(s, '\0', MAXLEN);
    itoa(n, s);
    printf("%s\n", s);
    n = 0;
    memset(s, '\0', MAXLEN);
    itoa(n, s);
    printf("%s\n", s);
    n = 8880;
    memset(s, '\0', MAXLEN);
    itoa(n, s);
    printf("%s\n", s);
    n = -0;
    memset(s, '\0', MAXLEN);
    itoa(n, s);
    printf("%s\n", s);

}