#include <stdio.h>
#include <string.h>

// Non-pointer method
void reverse (char *s)
{
    int len = strlen(s)-1;
    for (int i = 0; i < len; i++, len--)
    {
        char tmp = s[i];
        s[i] = s[len];
        s[len] = tmp;
    }
}

// Pointer method.
void preverse (char *s)
{
    int len = strlen(s)-1;
    for (int i = 0; i < len; i++, len--)
    {
        char tmp = *(s+i);
        *(s+i) = *(s+len);
        *(s+len) = tmp;
    }
    
}

int main (void)
{
    char s[] = "romeo";
    preverse(s);
    printf("%s\n", s);
}