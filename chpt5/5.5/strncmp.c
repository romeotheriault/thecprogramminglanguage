#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
NAME
       strcmp, strncmp - compare two strings
SYNOPSIS
       #include <string.h>
       int strncmp(const char *s1, const char *s2, size_t n);
DESCRIPTION
       The  strcmp()  function compares the two strings s1 and s2.  The locale is not taken into account
       (for a locale-aware comparison, see strcoll(3)).  It returns an integer less than, equal  to,  or
       greater than zero if s1 is found, respectively, to be less than, to match, or be greater than s2.

       The  strncmp() function is similar, except it compares only the first (at most) n bytes of s1 and
       s2.
RETURN VALUE
       The strcmp() and strncmp() functions return an integer less than, equal to, or greater than  zero
       if  s1  (or  the  first n bytes thereof) is found, respectively, to be less than, to match, or be
       greater than s2.
*/

int sstrncmp(const char *s1, const char *s2, size_t n)
{
    unsigned char c1 = '\0';
    unsigned char c2 = '\0';

    while (n > 0)
    {
        c1 = *s1++;
        c2 = *s2++;
        if (c1 == '\0' || c1 != c2)
              return c1 - c2;
        n--;
    }
    return c1 - c2;
}

int main (void)
{
    char s1[] = "aatdojcbtfisi";
    char s2[] = "ratdogcatfish";

    int rc2 = strncmp(s1, s2, 14);

    int rc;

    rc = sstrncmp(s1, s2, 14);
    printf("rc: %d\n", rc);
    printf("rc2: %d\n", rc2);
    exit(0);
}