#include <stdio.h>
#include <string.h>
#define MAXLENGTH 1024

// Write a version of itoa that accepts three arguments instead of two. 
// The third argument is a minimum field width; 
// the converted number must be padded with blanks on the left if necessary to make it wide enough.

void reverse(char s[]);
void itoa(long long int n, char s[], int length);

// itoa: convert n to characters in s[]
void itoa(long long int n, char s[], int length)
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
    while (i<length) {
        s[i++] = '0';
    }
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
    signed long long int n = -53648;
    char s[MAXLENGTH];
    int length = 10;
    memset(s, '\0', MAXLENGTH);
    itoa(n, s, length);
    printf("integer as string is: %s\n", s);
    return 0;
}