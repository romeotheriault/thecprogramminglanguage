#include <stdio.h>

/*
char *strncat(char *dest, const char *src, size_t n);
DESCRIPTION
       The strcat() function appends the src string to the dest string, overwriting the terminating null byte ('\0') at the end
       of dest, and then adds a terminating null byte.  The strings may not overlap, and the dest string must have enough space
       for  the  result.  If dest is not large enough, program behavior is unpredictable; buffer overruns are a favorite avenue
       for attacking secure programs.

       The strncat() function is similar, except that

       *  it will use at most n bytes from src; and

       *  src does not need to be null-terminated if it contains n or more bytes.

       As with strcat(), the resulting string in dest is always null-terminated.

       If src contains n or more bytes, strncat() writes n+1 bytes to dest (n from src plus the terminating null byte).  There‐
       fore, the size of dest must be at least strlen(dest)+n+1.

*/

char *sstrncat(char *d, const char *s, size_t n)
{
    //printf("0: %p - %c\n", d, *d);
    // Fast-forward to the end of dest.
    for (; *d != '\0'; d++);
        //printf("1: %p - %c\n", d, *d);
    // Copy n chars from src into dest
    for (int i = 0; i < n-1 && *s; i++, d++) {
        *d = *s++;
        //printf("2: %p - %c\n", d, *d);
    }

    *d = '\0'; 
    return d;
}

int main (void)
{
    const char s[] = "Joey";
    char d[100] = "Hello";
    sstrncat(d, s, sizeof(s));
    printf("dest: %s\n", d);
    return 0;
}