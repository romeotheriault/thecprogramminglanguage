#include <stdio.h>
#define MAXLINE 1000
#define LINELENGTH 79

int getlines(char line[], int maxline);
void copy(char to[], char from[]);
void pline(char l[]);

/* print the longest input line */
int main()
{
  int i;
  int len;    /* current line length */
  char line[MAXLINE];   /* current input line */
  char longest[MAXLINE];    /* longest line saved here */


    while ((len = getlines(line, MAXLINE)) > 0) {
        if (len > 0 && len > LINELENGTH) {   /* there was at least one line */
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
