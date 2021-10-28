#include <stdio.h>
#include <stdlib.h>

/*
int main(void)
{
    int day, month, year;
    if (scanf("%d/%d/%d", &day, &month, &year) != 3) {
        printf("failed to gather input\n");
        exit(1);
    }
    printf("%d/%d/%d\n", day, month, year);
}
*/

int main (void)
{
    int month, day, year;
    size_t bufsize = 0;
    char *buf = NULL;
    getline(&buf, &bufsize, stdin);
    //printf("%s", buf);
    sscanf(buf, "%d/%d/%d", &month, &day, &year);
    printf("%d\n", month);
}