#include "operandStack.h"
#include "operatorStack.h"

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
        return 7;

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

void partialExpression(operandStack *operand,operatorStack *operator)
{
    char toString[2];
    char *operand1;
    char *operand2;
    char pe[20];

    operand2 = pop2(operand);
    operand1 = pop2(operand);
    toString[0] = pop1(operator);
    toString[1] = '\0';


    strcpy(pe,toString);
    strcat(pe,operand1);
    strcat(pe,operand2);
    push2(operand,pe);
}

void infixToPrefix(char in[],char *po)
{
    operandStack oprndstk;
    oprndstk.top = -1;

    operatorStack oprstk;
    oprstk.top = -1;
    
    char symb;
    char toString[2];
    int i=0;
    int j=0;

    while((symb = in[i++])!='\0')
    {
        
        if(isOperand(symb)){
            toString[0] = symb;
            toString[1] ='\0';
            push2(&oprndstk,toString);
        }

        else
        {

            while(oprstk.top != -1 && inputPriority(symb) < stackPrecedence(peek1(&oprstk))) 
            {
                if(symb == ')')
                {

                    while(peek1(&oprstk)!='(')
                    {  
                        partialExpression(&oprndstk,&oprstk);

                    }
                    char discard = pop1(&oprstk);

                    break;
                } 
                else
                partialExpression(&oprndstk,&oprstk);   
            }
            if(symb!=')')
	    {

                push1(&oprstk,symb);
		display(&oprstk);
	    }
        }
    }

    while(peek1(&oprstk)!='\0')
        partialExpression(&oprndstk,&oprstk);
    
    po = pop2(&oprndstk);    
    printf("\nPrefix expression is %s",po);
}


void main()
{
    char Infix[20];
    char Postfix[20]={'\0'};
    freopen("input.txt", "r",stdin);
    scanf("%s",Infix);
    printf("Scanned %s\n",Infix);

    infixToPrefix(Infix,Postfix);

    printf("\nPrefix expression is %s",Postfix);
}
