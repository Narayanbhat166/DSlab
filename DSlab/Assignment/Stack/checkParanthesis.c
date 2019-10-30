#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define size 10

struct stack
{
	char items[size];
	int top;
};

typedef struct stack stack;

void push(stack *ps,char op)
{
	ps->items[++ps->top] = op;
}

char pop(stack *ps)
{
	if(ps->top == -1)
		return '\0';
	return ps->items[ps->top--]; 
}

void main()
{
    stack paranthesis;
    paranthesis.top = -1;

    char input[20];
    char discard;
    printf("Enter the input expression\n");
    gets(input);
    int i=0;
    char symb;
    while((symb = input[i++]) != '\0')
    {
        if(symb == ')' && paranthesis.top == -1)
        {
            printf("\nIt is an invalid expression");
            exit(0);
        }
        if(symb =='(')
            push(&paranthesis,symb);
        else if(symb == ')')
            discard = pop(&paranthesis);
    }

    if(paranthesis.top == -1)
        printf("\nIt is a valid expression");
    else
        printf("\nIt is an invalid expression");    
}
    
