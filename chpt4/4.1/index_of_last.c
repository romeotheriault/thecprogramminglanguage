#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 /* maximum input line length */
int mgetline(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattern[] = "ould"; /* pattern to search for */
/* find all lines matching pattern */
int main()
{
    char line[MAXLINE];
    int found = 0;
    int index;;
    while (mgetline(line, MAXLINE) > 0)
        if ((index = strindex(line, pattern)) >= 0) {
            printf("index: %d, string: %s", index, line);
            found++;
        }
        return found;
}

/* getline: get line into s, return length */
int mgetline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strindex: return index of start of the last instance of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int slen = strlen(s)-1;
    int tlen = strlen(t)-1;
    int i, j, k;
    for (i = slen; s[i] >= 0; i--) {
        for (j=i, k=tlen; k>=0 && s[j]==t[k]; j--, k--) {
            if (k==0) {
                return j;
            }
        }
    }
    return -1;
}