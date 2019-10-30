#include<stdio.h>
#include<stdlib.h>

struct node {
	int info;
	struct node *link;  //Address of the next node
};

typedef struct node *node;

node CreateNode(int val){
    node NN;
    NN = (node) malloc(sizeof(struct node));
    NN -> link = NULL;
    NN -> info = val;
    return NN;
}

node InsertFront(node F, int item)
{
    node NN = CreateNode(item);
    if(F == NULL)
        return NN;
    NN -> link = F;
    return NN;
}

void Display(node F)
{
    if(F == NULL)
    {
        printf("\nEmpty");
        return;
    }
    node temp = F;
    while(temp)
    {
        printf("%d",temp->info);
        temp = temp->link;
    }
}

node Add(node F,node S)
{
    printf("Entered");
    int count = 0,sum = 0;
    node temp = NULL;

    while(F!=NULL && S!=NULL)
    {
            printf("Entered1");
        sum = F->info + S->info + count;
        count = sum / 10;
        sum %= 10;
        temp = InsertFront(temp,sum);
        F = F->link;
        S = S->link;
    }

    while(F!=NULL)
    {
        sum = F->info + S->info + count;
        count = sum / 10;
        sum %= 10;
        temp = InsertFront(temp,sum);
        F = F->link;
    }

    while(S!=NULL)
    {
        sum = F->info + S->info + count;
        count = sum / 10;
        sum %= 10;
        temp = InsertFront(temp,sum);
        S = S->link;
    }

    return temp;
}

void main()
{
    node First = NULL;
    node Second = NULL;
    node Result = NULL;

    int item;

    printf("Enter the first number, Enter -1 to terminate\n");
    scanf("%d",&item);

    while (item != -1)
    {
        First = InsertFront(First,item);
        scanf("%d",&item);
    } 

    printf("Enter the Second number, Enter -1 to terminate\n");
    scanf("%d",&item);

    while (item != -1)
    {
        Second = InsertFront(Second,item);
        scanf("%d",&item);
    }
    
    Result = Add(First, Second);

    Display(Result);
    
}
