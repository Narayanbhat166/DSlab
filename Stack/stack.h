#include <stdio.h>
#define size 10

//Character stack for storing the operators

struct stack
{
	char items[size];
	int top;
};

typedef struct stack stack;

void push(stack *ps, char op)
{
	ps->items[++ps->top] = op;
}

char pop(stack *ps)
{
	if (ps->top == -1)
		return '\0';
	return ps->items[ps->top--];
}

char peek(stack *ps)
{
	if (ps->top == -1)
		return '\0';
	return ps->items[ps->top];
}

void display(stack *ps)
{
	printf("\nStack contents are\n");

	int i;
	for (i = ps->top; i >= 0; i--)
		printf("%c ", ps->items[i]);
}
