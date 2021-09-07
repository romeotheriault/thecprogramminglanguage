#include <stdio.h>
#include <string.h>


void _reverse(char s[], int len, int start)
{
    if (start < len) {
        char temp = s[start];
        s[start] = s[len-1];
        s[--len] = temp;
        _reverse(s, len, ++start);
    }
}

void reverse(char s[])
{
    int start = 0;
    int len = strlen(s);
    if (len <= 0)
        return;
    _reverse(s, len, start);
}

/*
// Iterative approach
void reverse(char s[])
{
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        char temp = s[i];
        s[i] = s[len-1];
        s[--len]  = temp;
    }
}
*/

int main(void)
{
    char s[] = "theriault";
    reverse(s);
    printf("%s\n", s);
}