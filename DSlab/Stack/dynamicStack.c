#include<stdio.h>
#include<stdlib.h>

int size;

struct stack
{
	int *items;
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
	printf("\nEnter the maximum size of the stack\n");
	scanf("%d",&size);

	s.items = (int *)malloc(sizeof(int) * size);

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
		printf("\n");
	}
}

void push(stack *ps)
{
	if(ps->top == size-1)
	{
		printf("\nStack Overflow\n");
		return;
	}

	printf("\nEnter the item to be inserted\n");
	scanf("%d",(ps->items+ ++ps->top));
}

void pop(stack *ps)
{
	if(ps->top == -1)
	{
		printf("\nStack Underflow\n");
		return;
	}

	printf("\nPopped %d",*(ps->items+ps->top--));
}

void peek(stack *ps)
{
	if(ps->top == -1)
	{
		printf("\nStack is empty");
		return;
	}

	printf("\nTop element is %d",*(ps->items+ps->top));
}

void display(stack *ps)
{
	if(ps->top == -1)
	{
		printf("\nStack is empty");
		return;
	}
	int i;
	printf("\n");
	for(i=ps->top;i>=0;i--)
		printf("%d ",*(ps->items+i));
}

