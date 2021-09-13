#include <stdio.h>
#define MAXLEN 100

/* strcat, pointer version. Copies the string t to the end of s */
int sstrcat (char *s, char *t)
{
    while (*s != '\0')
        s++;
    while (*t != '\0')
        *s++ = *t++;
    *s = '\0';
    return 0;
}

int main (void)
{
    char s[MAXLEN] = "testing";
    char t[MAXLEN] = "timestwo hotdog";
    if(sstrcat(s, t)) {
        printf("strcat failed");
        return 1;
    } else {
        printf("%s\n", s);
        return 0;
    }
}