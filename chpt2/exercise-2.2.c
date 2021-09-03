#include <stdio.h>
#include <limits.h>

int main ()
{

int lim = 20;
char s[lim];
char c;
int i;

  /*
  for (i=0; i<lim-1 && (c=getchar()) != '\n' && c !=EOF; ++i) {
      s[i] = c;
  }
  */

  for (i=0; i < lim - 1; ++i) {
    if ((c=getchar()) == '\n')
      break;
    else if (c == EOF)
      break;
    else
      s[i] = c;
  }

  printf("i is: %d\n", i);
  printf("lim is: %d\n", lim);

  int j = 0;
  while (i-- > 0) {
    printf("%c", s[j++]);
  }
  printf("\n");

}
