#include <stdio.h>
#define MAXLEN 100

/* Return 1 if t occurs at the end of the string s */
int strend(char *s, char *t)
{
    int i = 0, j = 0;
    if (!*t || !*s)
        return 0;
    while (*s++)
        i++;
    while (*t++)
        j++;
    if (i < j)
        return 0;
    for (; *t-- == *s-- && j >= 1; j--);
    return (j == 0) ? 1 : 0;
}

int main (void)
{
    char s[MAXLEN] = "gcat";
    char t[MAXLEN] = "cat";
    if (strend(s, t))
        printf("%s occurs at the end of s\n", t);
    else
        printf("Not found.\n");
}