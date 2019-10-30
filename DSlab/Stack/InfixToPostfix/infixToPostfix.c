#include "stack.h"
#include <ctype.h>

int stackPrecedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 2;

    case '*':
    case '/':
        return 4;

    case '$':
    case '^':
        return 6;

    case '(':
        return 0;
    }
}

int inputPriority(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 3;

    case '$':
    case '^':
        return 5;

    case '(':
        return 9;
    case ')':
        return 0;
    }
}

int isOperand(char op)
{
    switch (op)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '$':
    case '^':
    case '(':
    case ')':
        return 0;

    default:
        return 1;
    }
}

void infixToPostfix(char Input[], char postfix[])
{

    stack oprStack;
    oprStack.top = -1;

    char symb;
    int i = 0;
    int j = 0;

    while (Input[i] != '\0')
    {
        symb = Input[i++];

        if (isOperand(symb))
        {
            postfix[j++] = symb;
        }

        else

        {
            while (oprStack.top != -1 && inputPriority(symb) < stackPrecedence(peek(&oprStack)))
            {

                if (symb == ')')
                {
                    while (peek(&oprStack) != '(')
                        postfix[j++] = pop(&oprStack);
                    char discard = pop(&oprStack);
                    break;
                }
                else
                {
                    postfix[j++] = pop(&oprStack);
                }
            }

            if (symb != ')')
                push(&oprStack, symb);
        }
    }

    while (peek(&oprStack) != '\0')
        postfix[j++] = pop(&oprStack);

    postfix[j++] = '\0';
}
void main()
{

    char infix[20];
    char postfix[20] = {'\0'};

    freopen("input.txt", "r", stdin);
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);

    printf("Infix %s\nPostfix %s\n", infix, postfix);
}
