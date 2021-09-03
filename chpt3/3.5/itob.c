#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1024

// Write the function itob(n,s,b) that converts the integer n into a base b 
// character representation in the string s. In particular, itob(n,s,16) 
// formats s as a hexadecimal integer in s.

void reverse(char s[]) {
    int len = strlen(s);
    char c;
    for (int i = 0, j = len-1; i < j; i++, j--)
       c=s[i], s[i]=s[j], s[j]=c; 
}

void itob(int n, char s[], int b) {

    int i = 0, r;

    do {
        r = n % b;
        s[i++] = r < 9 ? r+'0' : r+'a'-10;
    } while ((n /= b)>0);
    reverse(s);
}

int main() {
    int n = 35631;
    char s[MAX_LENGTH];
    memset(s, '\0', MAX_LENGTH);
    itob(n, s, 16);
    printf("int as int: %d\n", n);
    printf("int as hex: %s\n", s); 
    return 0;
}