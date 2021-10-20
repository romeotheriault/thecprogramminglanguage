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


#define MAX_SIDS 100000
#define MAX_USERNAME_LEN 100
struct tnode *addtree(struct tnode *, char*);
void treeprint(struct tnode *);

void get_sid(char *line, int sids[], int max_sids)
{
    // Pulling the sid out of a line like this:
    // [02] Tue 19Jan21 00:18:26 - (108422) Connected to 38.96.131.2 (local address 10.1.240.194, port 21)
    static int sid_count = 0;
    char *connected = ") Connected";
    char *t;
    char sid[7];
    if ((t = strstr(line, connected)) != NULL) {
        sid[6] = '\0';
        for (int i = 5; i >= 0; i--)
            sid[i] = *(--t);
       
       if (sid_count < MAX_SIDS) {
           sids[sid_count] = atoi(sid);
           //printf("%d\n", sids[sid_count]);
           sid_count++;
       } else {
           printf("Too many sids.\n");
           exit(1);
       }
    }
}

int get_username(char *p, char *user, int sids[], int sids_len)
{
    // Pulling the username and sid out of a line like this:
    // [02] Tue 19Jan21 00:18:26 - (108422) User "ibitest" logged in
    // Reverse until second double quote found, keeping count.
    int double_quote_count = 0;
    int username_length = 0;
    char *t = user;
    do
    {
        if (*p-- == '"')
            double_quote_count++;
        username_length++;
    } while (double_quote_count < 2);

    // Move forward one character
    p++;
    username_length--;

    while (username_length-- >= 0)
        *user++ = *p++;

    *user = '\0';

    // Now lets find the sid.
    char sid[7];
    int isid;
    while (*p-- != '(')
        ;
    p++; p++;
    for (int i = 0; i < 6; i++)
        sid[i] = *p++;
    isid = atoi(sid);
    //printf("sid: %s - isid: %d\n", sid, isid);
    for (int i = 0; i <= sids_len; i++) {
        if (isid == sids[i]) {
            //printf("found sid: %d for user: %s\n", isid, t);
            return 1;
        }
    } 
    return 0;
}

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

    fp = fopen("./ftplog", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    struct tnode *root;
    char user[MAX_USERNAME_LEN];

    root = NULL;

    char *p;
    char *logged_in_string = "\" logged in";
    char *port21 = "port 21";
    int sids[MAX_SIDS] = { };
    while ((read = getline(&line, &len, fp)) != -1) {
        if ((p = strstr(line, logged_in_string)) != NULL) {
            if (get_username(p, user, sids, MAX_SIDS))
                root = addtree(root, user);
        } else if (strstr(line, port21) != NULL) {
            //printf("%s", line);
            get_sid(line, sids, MAX_SIDS);
        }
    }
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