#include <stdio.h>
#include <string.h>

char one[] = "tesping one";
char two[] = "testing two";
char *t[2] = {one, two};

void func1 (void)
{
    printf("%s\n", *t);
    t[0]++;
    printf("%s\n", *t);
    t[0]++;
    printf("%s\n", *t);
    t[0]++;
    t[0]++;
    t[0]++;
    t[0]++;
}

void func2 (void)
{
    printf("%s\n", *t);
}

int main (void)
{
    int len = strlen(one);
    printf("len: %d\n", len);
    func1();
    func2();

}
