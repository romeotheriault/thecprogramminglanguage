#include <stdio.h>

int main(void)
{
    char *linebuf = NULL;
    size_t line_buf_size = 0;
    printf("What is your name? ");
    while (getline(&linebuf, &line_buf_size, stdin)!=-1)
    {
        printf("line read: %s", linebuf);
    }
    
}