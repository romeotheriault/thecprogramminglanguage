// Exercise 3-3
// Write a function expand(s1,s2) that expands shorthand notation like a-z in the string s1
// into the equivalent complete list abc...xyz in s2. Allow for letters of either case and
// digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that 
// leading or trailing - is taken literally.

#include <stdio.h>
#include <string.h>

# define MAX_LENGTH 1024

void expand (char *s1, char *s2, int len)
{
    int start = 128;
    int end = 128;
    int ptr1 = 0;
    int ptr2 = 0;
    while (ptr1 <= len-1)
    {
        if (s1[ptr1] == '-' && ptr1 == 0) {
            start = '-';
            ptr1++;
        }
        else if (s1[ptr1] == '-' && ptr1 == len-1) {
            end = '-';
            ptr1++;
        }
        else if (s1[ptr1] != '-' && start == 128)
        {
            start = s1[ptr1++];
        }
        else if (s1[ptr1] != '-' && start != 128)
        {
            end = s1[ptr1++];
        }
        else if (s1[ptr1] == '-') {
            ptr1++;
            continue;
        }
        if (start != 128 && end != 128) {
            for (int i = start; i <= end; i++)
            {
                s2[ptr2++] = i;
            }
            if (ptr1 != len - 1 && s1[ptr1] == '-') {
                start = s1[ptr1-1];
                end = 128;
                ptr2--;
            } else {
                start = end = 128;
            }
        }
    }
}

int main ()
{
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];
    memset(s1, '\0', MAX_LENGTH);
    memset(s2, '\0', MAX_LENGTH);

    char c;
    int i = 0;
    while ((c = getchar()) != EOF)
    {
        s1[i++] = c;
    }

    int len1 = strlen(s1);
    if (s1[len1-1] == '\n') {
        s1[len1-1] = '\0';
        len1--;
    }

    expand(s1, s2, len1);

    int len = strlen(s2);
    for (int i = 0; i < len; i++)
    {
        printf("%c ", s2[i]);
    }
}