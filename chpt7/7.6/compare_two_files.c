#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("usage: %s <file1> <file2>\n", argv[0]);
        exit(1);
    }
    FILE *f1;
    FILE *f2;
    char *prog = argv[0];

    if ((f1 = fopen(*++argv, "r")) == NULL) {
        fprintf(stderr, "%s: can't open %s\n", prog, *argv);
        exit(1);
    }
    if ((f2 = fopen(*++argv, "r")) == NULL) {
        fprintf(stderr, "%s: can't open %s\n", prog, *argv);
        exit(1);
    }

    char *f1p = NULL;
    char *f2p = NULL;
    size_t s1 = 0;
    size_t s2 = 0;

    while (getline(&f1p, &s1, f1) != -1 && getline(&f2p, &s2, f2) != -1) {
        if (strcmp(f1p, f2p) != 0) {
            printf("lines that differ: \n");
            printf("line1: %s", f1p);
            printf("line2: %s", f2p);
            fclose(f1);
            fclose(f2);
            exit(0);
        }
    }
    printf("files match\n");
    fclose(f1);
    fclose(f2);
    exit(0);
}