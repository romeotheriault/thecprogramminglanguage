#include <stdio.h>

/* strncpy(dest, src, n)
char * strncpy ( char * destination, const char * source, size_t num );
Return - destination is returned
Copy at most n characters of t to s. 
  The  strcpy()  function copies the string pointed to by src, including the terminating null byte ('\0'), to the buffer pointed
  to by dest.  The strings may not overlap, and the destination string dest must be large enough to receive the copy.  Beware of
  buffer overruns!  (See BUGS.)
  
  The strncpy() function is similar, except that at most n bytes of src are copied.  Warning: If there is no null byte among the
  first n bytes of src, the string placed in dest will not be null-terminated.
  
  If the length of src is less than n, strncpy() writes additional null bytes to dest to ensure that a  total  of  n  bytes  are
  written.
*/

char * sstrncpy(char * dest, const char * src, int num)
{
    int i = 0;
    int dst_size = sizeof(dest);
    while ((*dest++ = *src++) && (i++ < num-1))
        ;

    while (dest++ && i++ < num-1 && i < dst_size) 
        *dest = '\0';

    return dest;
}

int main (void)
{
    char src_string[] = "This is a test";
    char dest_string[50];
    

    sstrncpy(dest_string, src_string, 7);

    printf("src: %s\n", src_string);
    printf("dest: %s\n", dest_string);
}