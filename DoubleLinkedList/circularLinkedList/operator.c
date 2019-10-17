#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node *node;

void InsertFront(node);
void Display(node);
node createnode();
void InsertByOrder(node);
void DeleteByPos(node);
void Deleteleft(node);
void DeleteRight(node);

typedef struct node *node;

int main()
{
    node Head = createnode();
    Head->info = 0;
    Head->link = Head;
    int choice;

    while (1)
    {
        printf("Enter your choice:\n");
        printf("1:InsertFront\n2:InsertRear\n3:DeleteFront\n4:DeleteRear\n5:display\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            InsertFront(Head);
            Display(Head);
            break;
        case 2:
            InsertByOrder(Head);
            Display(Head);
            break;
        case 3:
            DeleteByPos(Head);
            Display(Head);
            break;
        case 4:
            DeleteLeft(Head);
            Display(Head);
            break;
        case 5:
            DeleteRight(Head);
            Display(Head);
            break;
        case 6:
            Display(Head);
            break;
        default:
            exit(0);
        }
    }
}

node createnode()
{
    node NN = NULL;
    NN = (node)malloc(sizeof(struct node));
    return NN;
}

void InsertFront(node H)
{
    node NN;
    NN = createnode();
    NN->link = NULL;

    printf("\nEnter the details to be inserted\n");
    scanf("%d", &NN->info);

    NN->link = H->link;
    H->link = NN;
    H->info++;
}

void Display(node H)
{
    if (H->info == 0)
    {
        printf("\nList is empty\n");
        return;
    }
    printf("\n");
    node temp = H->link;
    while (temp != H)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }
}

void InsertByOrder(node H)
{
    node NN;
    NN = createnode();
    NN->link = NULL;

    printf("\nEnter the details to be inserted\n");
    scanf("%d", &NN->info);

    node PN = H;
    node CN = H->link;

    while (CN != H && NN->info > CN->info)
    {
        PN = CN;
        CN = CN->link;
    }

    NN->link = CN;
    PN->link = NN;
    H->info++;
}

void DeleteByPos(node H)
{
    if (H->info == 0)
        return;

    int pos;
    printf("\nEnter the position to be deleted\n");
    scanf("%d", &pos);

    if (pos < 1 || pos > H->info)
    {
        printf("\nInvalid position\n");
        return;
    }

    node PN = H;
    node CN = H->link;
    int count = 1;

    while (count < pos)
    {
        PN = CN;
        CN = CN->link;
        count++;
    }

    node del = CN;
    printf("\nDelted %d\n", del->info);
    PN->link = del->link;
    free(del);
    H->info--;
}

void DeleteLeft(node H)
{
    if (H->info == 0)
        return;

    int pos;
    printf("\nEnter the position to the left to be deleted\n");
    scanf("%d", &pos);

    if (pos <= 1 || pos > H->info)
    {
        printf("\nInvalid position\n");
        return;
    }

    node PN = H;
    node CN = H->link;
    int count = 1;

    while (count < pos - 1)
    {
        PN = CN;
        CN = CN->link;
        count++;
    }

    node del = CN;
    printf("\nDelted %d\n", del->info);
    PN->link = del->link;
    free(del);
    H->info--;
}

void DeleteRight(node H)
{
    if (H->info == 0)
        return;

    int pos;
    printf("\nEnter the position to the left to be deleted\n");
    scanf("%d", &pos);

    if (pos < 1 || pos > H->info - 1)
    {
        printf("\nInvalid position\n");
        return;
    }

    node PN = H;
    node CN = H->link;
    int count = 1;

    while (count < pos + 1)
    {
        PN = CN;
        CN = CN->link;
        count++;
    }

    node del = CN;
    printf("\nDelted %d\n", del->info);
    PN->link = del->link;
    free(del);
    H->info--;
}