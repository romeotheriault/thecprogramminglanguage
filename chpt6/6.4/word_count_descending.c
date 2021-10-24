#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/* 
   Print the distinct words in it's input sorted in descending order
   of frequency of occurence. Precede each word by it's count.
*/

#define MAXWORD 100
#define MAXLINE 1000
struct tnode *addtree(struct tnode *, char*);
//void treeprint(struct tnode *);
int getword(char *, int);
int tnode_count = 0;
int tnode_array_index = 0;

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

/* qsort: sort v[left]...v[right] into descending order */
void qqsort(void *v[], int left, int right)
{
    int i, last;

    if (right <= left) /* do nothing if the array contains */
        return;        /* fewer than two elements */
    swap(v, right, (left+right)/2);
    last = right;
    for (i = right-1; i >= left; i--)
        if ((v[i], v[right]) < 0)
            swap(v, --last, i);
    swap(v, right, last);
    qqsort(v, left, last-1);
    qqsort(v, last+1, right);
}

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
        tnode_count++;
    } 
    else if (cond = strcmp(word, t->word) == 0)
        t->count++;
    else if (cond < 0)
        t->left = addtree(t->left, word);
    else
        t->right = addtree(t->right, word);
    return t;
}

/*void treeprint(struct tnode *t)
{
    if (t!=NULL) {
        treeprint(t->left);
        printf("%d: %s\n", t->count, t->word);
        treeprint(t->right);
    }
}*/

void add_node_to_array(struct tnode *t, struct tnode **tarray)
{
    if (t!=NULL) {
        tnode_array_index++;
        add_node_to_array(t->left, tarray);
        //printf("%d: %s\n", t->count, t->word);
        tarray[tnode_array_index] = t;
        add_node_to_array(t->right, tarray);
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
    // Allocate space for the array of tnode pointers
    struct tnode **nodes = (struct tnode **) malloc(sizeof(struct tnode) * tnode_count);
    add_node_to_array(root, nodes);
    printf("tnode_array_index: %d\n", tnode_array_index);
    printf("tnode count: %d\n", tnode_count);
    for (int i = 1; i <= tnode_array_index; i++)
    {
        printf("%d: %s\n", nodes[i]->count, nodes[i]->word);
    }
    
    //treeprint(root);
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