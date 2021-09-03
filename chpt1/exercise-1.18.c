#include <stdio.h>
#define MAXLINE 1000

int getlines(char line[], int maxline);
void copy(char to[], char from[]);
void rem_trailing_tab_space(char l[], int len);
void pline(char l[]);

/* Remove trailing tabs and whitespace */
int main()
{
  int i;
  int len;    /* current line length */
  char line[MAXLINE];   /* current input line */


    while ((len = getlines(line, MAXLINE)) > 0) {
        if (len > 0) {   /* there was at least one line */
                rem_trailing_tab_space(line, len);
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
/* 32 is space; 9 is tab. */
void rem_trailing_tab_space(char l[], int len)
{
    int i;
    i = 0;
    
    while (len > 0 && (l[len] == 32 || l[len] == 9 || l[len] == 0 || l[len] == 10)) {
        l[len] = '\0';
        --len;
    }
    l[len+1] = '\n';
    //printf("/%i/ /%i/ /%i/ /%i/", l[len], l[len-1], l[len-2], l[len-3]);
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
