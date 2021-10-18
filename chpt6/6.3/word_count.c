#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define MAXLINE 1000
struct tnode *addtree(struct tnode *, char*);
void treeprint(struct tnode *);
int getword(char *, int);

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

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
    return word[0];
}

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

/* talloc: make a node */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

struct tnode *addtree(struct tnode *t, char *word)
{
    int cond;
    if (t == NULL) 
    {
        t = talloc();
        t->word = strdup(word);
        t->count = 1;
        t->right = NULL;
        t->left = NULL;
    } 
    else if (cond = strcmp(word, t->word) == 0)
        t->count++;
    else if (cond < 0)
        t->left = addtree(t->left, word);
    else
        t->right = addtree(t->right, word);
    return t;
}

void treeprint(struct tnode *t)
{
    if (t!=NULL) {
        treeprint(t->left);
        printf("%d: %s\n", t->count, t->word);
        treeprint(t->right);
    }
}

/* word frequency count */
int main()
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    treeprint(root);
    return 0;
}

#define BUFFER_SIZE 1024
char buff[BUFFER_SIZE];
int buff_count = 0;

int getch(void)
{
    (buff_count > 0) ? buff[buff_count--] : fgetc(stdin);
}

void ungetch(int c)
{
    if (buff_count == BUFFER_SIZE-1)
        printf("Error: Buffer is full.\n");
    else
        buff[buff_count++] = c;
}