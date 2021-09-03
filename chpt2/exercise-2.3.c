#include <stdio.h>
#include <math.h>

int main ()
{

int lim = 20;
int s[20] = { 0 };
int c;
int i;
int j;

int num = 0;

  for (i=0; i < lim - 1; ++i) {
    if ((c = getchar()) == '\n') {
      s[i] = '\0';
      break;
    }
    else if (c == EOF) {
      break;
    }
    else {
      s[i] = c;
    }
  }

  for (j=0; i > 0; --i) {
    if (s[i-1] >= '0' && s[i-1] <= '9') {
      num = num + (s[i-1] - '0') * (int) pow(16, j);
    }
    else if (s[i-1] >= 'a' && s[i-1] <= 'z') {
      num = num + ((s[i-1] - 'a' + 10) * (int) pow(16, j));
    }
    else if (s[i-1] >= 'A' && s[i-1] <= 'Z') {
      num = num + ((s[i-1] - 'A' + 10) * (int) pow(16, j));
    }
    //printf("num at pos %i is: %i\n", i-1, s[i-1]);
    ++j;
  }
  printf("%i\n", num);
}
