#include<stdio.h>
#define size 5

struct stack
{
	int items[size];
	int top;
};

typedef struct stack stack;

void push(stack *);
void pop(stack *);
void peek(stack *);
void display(stack *);

void main()
{
	stack s;
	s.top = -1;
	int choice;
	while(1)
	{
		printf("\nEnter your choice:");
		printf("\n1:Push\n2:Pop\n3:Peek\n4:Display\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:push(&s);
			       display(&s);
			       break;
			case 2:pop(&s);
			       display(&s);
			       break;
			case 3:peek(&s);
			       break;
			case 4:display(&s);
			       break;
			default :exit(0);
		}
	}
}

void push(stack *ps)
{
	if(ps->top == size-1)
	{
		printf("\nStack Overflow");
		return;
	}

	printf("\nEnter the item to be inserted");
	scanf("%d",&ps->items[++ps->top]);
}

void pop(stack *ps)
{
	if(ps->top == -1)
	{
		printf("\nStack Underflow");
		return;
	}

	printf("\nPopped %d",ps->items[ps->top--]);
}

void peek(stack *ps)
{
	if(ps->top == -1)
	{
		printf("\nStack is empty");
		return;
	}

	printf("\nTop element is %d",ps->items[ps->top]);
}

void display(stack *ps)
{
	if(ps->top == -1)
	{
		printf("\nStack is empty");
		return;
	}
	int i;
	for(i=ps->top;i>=0;i--)
		printf("%d ",ps->items[i]);
}

