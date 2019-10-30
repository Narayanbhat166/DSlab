#include <stdio.h>
#include <string.h>

struct operandStack
{
    char items[10][20]; //String array which can store 10 Strings to length 20
    int top;
};

typedef struct operandStack operandStack;

void push2(operandStack *s, char op[])
{
    strcpy(s->items[++s->top], op);
}

char * pop2(operandStack *s)
{
    if (s->top == -1)
        return "empty";
    return s->items[s->top--];
}

char * peek2(operandStack *s)
{
    if (s->top == -1)
        return "empty";
    return s->items[s->top];
}
