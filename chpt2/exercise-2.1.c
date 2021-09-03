#include <stdio.h>
#include <limits.h>

int main ()
{

unsigned char ucm, ucm_old = 0;

while (++ucm > ucm_old)
  ucm_old = ucm;

printf("ucm: %i\n", ucm_old);

printf("unsigned char max: %i\n", UCHAR_MAX);
/*
printf("signed char min: %i\n", SCHAR_MIN);
printf("signed char max: %i\n", SCHAR_MAX);

printf("unsigned short max: %i\n", USHRT_MAX);
printf("signed short min: %i\n", SHRT_MIN);
printf("signed short max: %i\n", SHRT_MAX);
*/

signed int sim, sim_old = 0;
signed int simin, simin_old = 0;

while (++sim > sim_old)
  sim_old = sim;

while (--simin < simin_old)
  simin_old = simin;

printf("sim %i\n", sim_old);
printf("simin %i\n", simin_old);

printf("signed int min: %i\n", INT_MIN);
printf("signed int max: %i\n", INT_MAX);

/*
printf("unsigned int max: %i\n", UINT_MAX);

printf("unsigned long max: %lu\n", ULONG_MAX);
printf("signed long min: %lli\n", LLONG_MIN);
printf("signed long max: %lli\n", LLONG_MAX);
*/



}
