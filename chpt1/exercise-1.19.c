#include <stdio.h>
#define MAXLINE 1000

int getlines(char line[], int maxline);
void copy(char to[], char from[]);
void pline(char l[]);
void reverse(char s[], int len);

/* Remove trailing tabs and whitespace */
int main()
{
  int i;
  int len;    /* current line length */
  char line[MAXLINE];   /* current input line */


    while ((len = getlines(line, MAXLINE)) > 0) {
        if (len > 0) {   /* there was at least one line */
                reverse(line, len);
                pline(line);
        }
    }
    return 0;
}

/* getlines: read a line into s, return length */
int getlines(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

/* reverse: reverse the input line */
void reverse(char s[], int len)
{
    char temp[MAXLINE];
    int i;
    i = 0;
    
    while (len >= 0) {
        if (s[len] != '\0' && s[len] != 10) {
            temp[i] = s[len];
            ++i;
        }
        --len;
    }
    
    copy(s, temp);
    
    temp[i+1] = '\n';
    temp[i+2] = '\0';
}


/* pline: print the character array (line) */
void pline(char l[])
{
    int i;
    
    i = 0;
    while (l[i] != '\0') {
        printf("%c", l[i]);
        ++i;
    }
    printf("\n");
}
