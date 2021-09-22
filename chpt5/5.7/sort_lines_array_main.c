#include <stdio.h>
#include <string.h>

#define MAXLINES 900000   // max #lines to be sorted

char *lineptr[MAXLINES];  // pointers to text lines

int readlines(char *lineptr[], int nlines, char *allocp);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);
#define ALLOCSIZE 900000           // size of available space

/* sort input lines */
int main(void)
{
  char allocbuf[ALLOCSIZE];  // storage for alloc 
  char *allocp = allocbuf;   // next free position

  int nlines;    // number of input lines read

  if((nlines = readlines(lineptr, MAXLINES, allocp)) >= 0)
    {
      qsort(lineptr, 0, nlines-1);
      writelines(lineptr, nlines);
      return 0;
    }
  else
    {
      printf("nlines: %d\n", nlines);
      printf("error: input too big to sort\n");
      return 1;
    }
}

#define MAXLEN 900000   // max length of any input line
int ggetline(char *, int);
//char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char *allocp)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = ggetline(line, MAXLEN)) > 0)
    if (nlines >= maxlines) {
      //printf("nlines2: %d\n", nlines);
      //printf("alloc: %d", *p);
      return -1;
    }
    else {
	      line[len-1] = '\0';   // delete newline
	      strcpy(allocp, line);
	      lineptr[nlines++] = allocp;
        allocp += len;
    }
  return nlines;
}

/* getline: read a line into s, return length */
int ggetline(char *s, int lim)
{
  int c, i;

  for (i = 0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
    s[i] = c;
  if (c == '\n')
    {
      s[i] = c;
      ++i;
    }
  s[i] = '\0';
  return i;
}

/*
#define ALLOCSIZE 9000000           // size of available space

static char allocbuf[ALLOCSIZE];  // storage for alloc 
static char *allocp = allocbuf;   // next free position

char *alloc(int n)
{
  if (allocbuf + ALLOCSIZE - allocp >= n)   // if it fits
    {
      allocp += n;
      return allocp - n;  
    }
  else
    return 0;
}
*/

/* write lines: write output lines */
void writelines(char *lineptr[], int nlines)
{
  int i;

  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right)  // do nothing if array contains fewer than two elements
    return;
  swap(v, left, (left + right )/2);
  last = left;
  for (i = left+1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}