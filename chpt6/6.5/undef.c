#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE]; /* pointer table */

struct nlist {      /* table entry */
    struct nlist *next; /* next entry in chain */
    char *name;         /* defined name */
    char *defn;         /* replacement text */
};

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    //printf("hash bucket: %d\n", hashval % HASHSIZE);
    //return hashval % HASHSIZE;
    return 0;
}

/* lookup: look for s in hashtab */
int undef(char *s)
{
    struct nlist *np1;
    struct nlist *np2;

    np1 = hashtab[hash(s)];
    np2 = np1;

    for (; np2 != NULL; np2 = np2->next) {
        if (strcmp(s, np2->name) == 0) {
            if (np2->next == NULL) {
                if (np1 == np2) {               /* First node */
                    free((void *) np2);        /* free previous node */
                    hashtab[hash(s)] = NULL;
                    return 1; // found
                } else {                        /* Last node */
                    np1->next = NULL;
                    free((void *) np2);
                    return 1; // found
                } 
            } else {
                if (np1 == np2) {               /* First node */
                    hashtab[hash(s)] = np2->next;
                    free((void *) np2);
                    return 1;
                } else {
                    np1->next = np2->next;
                    free((void *) np2);
                    return 1;
                }
            }
        }
        np1 = np2;
    }
    return 0;       // not found
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np; // found
    return NULL;       // not found
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {  /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else                              /* already there */
        free((void *) np->defn);        /* free previous defn */
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

void print_hash_table(void)
{
    struct nlist *np;
    for (int i = 0; i < HASHSIZE; i++) {
        if (hashtab[i] != NULL)
            np = hashtab[i];
            printf("address: %p - hashtab[%d] - charname: %s\n", np, i, np->name);
            for (np = np->next; np; np = np->next) 
                if (np->next)
                    printf("\tcharname: %s - address: %p\n", np->name, np->next); 
                else
                    printf("\tcharname: %s - address: NULL\n", np->name); 
                    break;
    }
}

int main(void)
{
    struct nlist *node;

    char *n = "romeo";
    char *d = "maya";
    node = install(n,d);

    n = "romeo1";
    d = "maya1";
    node = install(n,d);
    n = "romeo2";
    d = "maya2";
    node = install(n,d);

    n = "romeo3";
    d = "maya3";
    node = install(n,d);

    n = "rome9";
    d = "may3";
    node = install(n,d);

    n = "rom100";
    d = "may39";
    node = install(n,d);
    n = "rom101";
    d = "may39";
    node = install(n,d);
    n = "rom112";
    d = "may39";
    node = install(n,d);
    n = "rom110";
    d = "may39";
    node = install(n,d);
    n = "romep";
    d = "maya";
    node = install(n,d);

    //printf("node address: %p\n", node);
    //printf("node name: %s; node defn: %s\n", node->name, node->defn);
    print_hash_table();
    int rc = undef("rome9");
    if (rc)
        printf("removed node");
    rc = undef("romeo");
    if (rc)
        printf("removed node");
    rc = undef("romep");
    if (rc)
        printf("removed node");
    print_hash_table();
}