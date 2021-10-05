#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000 /* max #lines to be sorted */
char *lineptr[MAXLINES];  /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qqsort(void *lineptr[], int left, int right,
        int (*comp)(void *, void*), int reverse);
int numcmp(const char *, const char *);

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
    int numeric = 0; /* 1 if numeric sort */
    int reverse = 0;
    int c;

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c) {
            case 'n':
                numeric = 1;
                break;
            case 'r':
                reverse = 1;
                break;
            default:
                printf("q: illegal option %c\n", c);
                argc = 0;
                break;
                exit(EXIT_FAILURE);
            }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qqsort((void **) lineptr, 0, nlines-1,
            (int (*)(void*,void*))(numeric ? numcmp : strcmp), reverse);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

#include <math.h>

/* numcmp: compare s1 and s2 numerically */
int numcmp(const char *s1, const char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qqsort(void *v[], int left, int right, int (*comp)(void *, void *), int reverse)
{
    int i, last;
    void swap(void *v[], int, int);

    if (reverse) {
        if (right <= left) /* do nothing if the array contains */
            return;        /* fewer than two elements */
        swap(v, right, (left+right)/2);
        last = right;
        for (i = right-1; i >= left; i--)
            if ((*comp)(v[i], v[right]) < 0)
                swap(v, --last, i);
        swap(v, right, last);
    } else {
        if (left >= right) /* do nothing if the array contains */
            return;        /* fewer than two elements */
        swap(v, left, (left + right)/2);
        last = left;
        for (i = left+1; i <= right; i++)
            if ((*comp)(v[i], v[left]) < 0)
                swap(v, ++last, i);
        swap(v, left, last);
    }
    qqsort(v, left, last-1, comp, reverse);
    qqsort(v, last+1, right, comp, reverse);
}

int readlines(char *lineptr[], int nlines)
{
    size_t i;
    size_t buffsize = 1000;
    for (i = 0; getline(&lineptr[i], &buffsize, stdin) > 0 && i < MAXLINES; i++)
        ;
    //printf("total lines: %ld\n", i);
    return(i);
}

void writelines(char *lineptr[], int nlines)
{
    while (nlines-- >= 0)
        printf("%s", *lineptr++);
}