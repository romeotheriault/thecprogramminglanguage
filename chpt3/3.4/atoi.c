#include <stdio.h>
#include <string.h>
#define MAXLENGTH 1024

void reverse(char s[]);
void itoa(long long int n, char s[]);

// itoa: convert n to characters in s[]
void itoa(long long int n, char s[])
{
    int i;
    long long int sign;

    i = 0;
    if ((sign = n) < 0) { // Record sign
        n = -n;          // Make n positive
    } 
    do {                 // Generate digits in reverse order.
        s[i++] = n % 10 + '0'; // Get next digit
    } while ((n /= 10)> 0);    // delete it
    if (sign < 0) {
        s[i++] = '-';
    }
    reverse(s); 
}

// Reverse a string in place
void reverse(char s[]) {
    int len = strlen(s);
    char c;
    for (int i = 0, j = len-1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main() {
    //int n = 9987;
    signed long long int n = 2147483648;
    char s[MAXLENGTH];
    memset(s, '\0', MAXLENGTH);
    itoa(n, s);
    printf("integer as string is: %s\n", s);
    return 0;
}