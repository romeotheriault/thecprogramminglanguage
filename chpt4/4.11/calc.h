#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define CLEAR '1'
#define SWAP '2'
#define PRINT '3'
#define PRINTALL '4'
#define SIN '5'
#define EXP '6'
#define POW '7'

int getop(char []);
void push(double);
double pop(void);
void pst(void);
void psall(void);
int swap(void);
void clear(void);
int getch(void);
void ungetch(int);