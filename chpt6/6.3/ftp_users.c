#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/* Example log
[02] Tue 19Jan21 00:18:26 - (108422) Connected to 38.96.131.2 (local address 10.1.240.194, port 21)
[21] Tue 19Jan21 00:18:26 - (108422) 220 Serv-U FTP Server v15.1 ready...
[20] Tue 19Jan21 00:18:26 - (108422) SYST
[21] Tue 19Jan21 00:18:26 - (108422) 530 Not logged in.
[20] Tue 19Jan21 00:18:26 - (108422) USER ibitest
[21] Tue 19Jan21 00:18:26 - (108422) 331 User name okay, need password.
[20] Tue 19Jan21 00:18:26 - (108422) PASS **********
[02] Tue 19Jan21 00:18:26 - (108422) User "ibitest" logged in
[21] Tue 19Jan21 00:18:26 - (108422) 230 User logged in, proceed.
*/


#define MAX_USERNAME_LEN 100
struct tnode *addtree(struct tnode *, char*);
void treeprint(struct tnode *);
//int getword(char *, int);

/* getword: get next word or character from input */
/*
int getword(char *user, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = user;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return user[0];
}
*/

struct tnode {
    char *user;
    int count;
    struct tnode *left;
    struct tnode *right;
};

/* talloc: make a node */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

struct tnode *addtree(struct tnode *t, char *user)
{
    int cond;
    if (t == NULL) 
    {
        t = talloc();
        t->user = strdup(user);
        t->count = 1;
        t->right = NULL;
        t->left = NULL;
    } 
    else if ((cond = strcmp(user, t->user) == 0))
        t->count++;
    else if (cond < 0)
        t->left = addtree(t->left, user);
    else
        t->right = addtree(t->right, user);
    return t;
}

void treeprint(struct tnode *t)
{
    if (t!=NULL) {
        treeprint(t->left);
        printf("%d: %s\n", t->count, t->user);
        treeprint(t->right);
    }
}

/* ftp user frequency count */
int main()
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("/tmp/ftplog", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    struct tnode *root;
    char user[MAX_USERNAME_LEN];

    root = NULL;

    while ((read = getline(&line, &len, fp)) != -1) {
        //printf("Retrieved line of length %zu:\n", read);
        //printf("%s", line);
        if (isalpha(user[0])) {
            root = addtree(root, user);
        }
    }
    /*
    while (getword(user, MAX_USERNAME_LEN) != EOF)
        if (isalpha(user[0])) {
            root = addtree(root, user);
        }
    */
    treeprint(root);
    fclose(fp);
    if (line)
        free(line);
    return 0;
}

#define BUFFER_SIZE 1024
char buff[BUFFER_SIZE];
int buff_count = 0;

int getch(void)
{
    return (buff_count > 0) ? buff[buff_count--] : fgetc(stdin);
}

void ungetch(int c)
{
    if (buff_count == BUFFER_SIZE-1)
        printf("Error: Buffer is full.\n");
    else
        buff[buff_count++] = c;
}