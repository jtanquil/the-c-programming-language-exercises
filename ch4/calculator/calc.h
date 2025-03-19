#define NUMBER '0'

enum { NOT_VAR, IS_VAR };
enum { NO_ASSIGNMENT, ASSIGNMENT };

void push(double, int);
double pop(int);

int getop(char []);

void assign(double, int);
double get(int);
double get_last(void);
void assign_last(double);
int get_index(int);

int top_var(void);

int getch(void);
void ungetch(int);