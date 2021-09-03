#include <stdio.h>

int main();
int lower(int c);

int main() {
  printf("C lower is: %c\n", lower('C'));
}

int lower(int c) { return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c; }
