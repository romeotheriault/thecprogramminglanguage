#include <stdio.h>
#include <stdlib.h>

#define SIZE 1


/* Read input into a character array
   Pass the character array (by reference) to a function.
   Function converts tabs and newlines into visible "\t" and "\n".
   Push the character array with visible characters into another array.
*/

void escape(char *s, char *t);

int main() {

  char c;
  char *word = malloc((SIZE+1) * sizeof(int));

  int i;
  for(i = 0; (c = getchar()) != EOF; i++) {
     word[i] = c; 
     if ( i >= SIZE ) {
        printf("i: %i > 1. will realloc\n", i);
        word = realloc(word, i * sizeof(int));
      }
  }
  word[i+1] = '\0';

  char *new_word = malloc((i+1) * sizeof(int));

  escape(new_word, word); 

  printf("t: %s\n", word);
  printf("s: %s\n", new_word);
  
  free(new_word);
  free(word);
  printf("%lu\n", sizeof(int));

}

void escape(char *s, char *t) {
  while(*t) {
    switch(*t) {
      case '\n':
        *s++ = '\\';
        *s = 'n';
        s++; t++;
        break;
      case '\t':
        *s++ = '\\';
        *s = 't';
        s++; t++;
        break;
      default:
        *s++ = *t++;
    }
  }
  *s = '\0';
}
