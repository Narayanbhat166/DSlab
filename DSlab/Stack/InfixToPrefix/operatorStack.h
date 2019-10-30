#include <stdio.h>
#define size 10

//Character stack for storing the operators

struct operatorStack
{
	char items[size];
	int top;
};

typedef struct operatorStack operatorStack;

void push1(operatorStack *ps, char op)
{
	ps->items[++ps->top] = op;
}

char pop1(operatorStack *ps)
{
	if (ps->top == -1)
		return '\0';
	return ps->items[ps->top--];
}

char peek1(operatorStack *ps)
{
	if (ps->top == -1)
		return '\0';
	return ps->items[ps->top];
}

void display(operatorStack *ps)
{
	printf("\nStack contents are\n");

	int i;
	for (i = 0; i <= ps->top; i++)
		printf("%c ", ps->items[i]);
}
