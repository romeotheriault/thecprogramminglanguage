#include <stdio.h>

int main();
void print_bits(unsigned int num);
unsigned int setbits(unsigned int x, unsigned int p, unsigned int n, unsigned int y);
unsigned int invert(unsigned int x, unsigned int p, unsigned int n);

int main() {
  //int x = setbits(255,3,4,0);
  int x = invert(767,3,4);
  print_bits(x);
}


void print_bits(unsigned int num) {
  for (int i=(sizeof(int)*8); i>0; i--) {
    printf("%d", ((num & 2147483648) > 0) ? 1: 0);
    num = num << 1;
    if ((i%4)-1 == 0)
      printf(" ");
  }
  printf("\n");
}

unsigned int setbits(unsigned int x, unsigned int p, unsigned int n, unsigned int y) { 
    return (x & ~(~(~0 << n) << (p+1-n))) | ( y & ~(~0<<n)) << (p+1-n);
}

unsigned int invert(unsigned int x, unsigned int p, unsigned int n) {
  int j = ~x;
  return (x & ((~0 << n) << (p+1-n))) | (~x & ~(~0<<n)) << (p+1-n);
}
