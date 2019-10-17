#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *plink;
    struct node *nlink;
};

typedef struct node *node;

void InsertFront(node);
void InsertRear(node);
void DeleteFront(node);
void DeleteRear(node);
void Display(node);
void InsertByOrder(node);
void DeleteByKey(node);
void DeleteLeft(node);

node CreateNode()
{
    node NN = (node)malloc(sizeof(struct node));
    return NN;
}

void main()
{
    node Head = CreateNode();
    Head->info = 0;
    Head->plink = Head->nlink = Head;

    int choice;
    while (1)
    {
        printf("\nEnter your choice:\n");
        printf("1:InsertFront\n2:InsertRear\n3:DeleteFront\n4:DeleteRear\n5:InsertByOrder\n6:display\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            InsertFront(Head);
            Display(Head);
            break;
        case 2:
            InsertRear(Head);
            Display(Head);
            break;
        case 3:
            DeleteFront(Head);
            Display(Head);
            break;
        case 4:
            DeleteRear(Head);
            Display(Head);
            break;
        case 5:
            InsertByOrder(Head);
            Display(Head);
            break;
        case 6:
            DeleteByKey(Head);
            Display(Head);
            break;
        case 7:
            DeleteLeft(Head);
            Display(Head);
            break;
        case 8:
            Display(Head);
            break;
        default:
            exit(0);
        }
    }
}

void InsertFront(node H)
{
    node NN = CreateNode();
    printf("\nEnter the details to be inserted\n");
    scanf("%d", &NN->info);

    NN->nlink = H->nlink;
    NN->plink = H;
    NN->nlink->plink = NN;
    H->nlink = NN;
    H->info++;
}

void InsertRear(node H)
{
    node NN = CreateNode();
    printf("\nEnter the details to be inserted\n");
    scanf("%d", &NN->info);

    NN->nlink = H;
    NN->plink = H->plink;
    NN->plink->nlink = NN;
    H->plink = NN;
    H->info++;
}

void DeleteFront(node H)
{
    if (H->info == 0)
        return;
    node del = H->nlink;
    printf("\nDeleted %d", del->info);
    H->nlink = del->nlink;
    del->nlink->plink = H;
    H->info--;
}

void DeleteRear(node H)
{
    if (H->info == 0)
        return;
    node del = H->plink;
    printf("\nDeleted %d", del->info);
    H->plink = del->plink;
    del->plink->nlink = H;
    H->info--;
}

void Display(node H)
{
    if (H->info == 0)
    {
        printf("\nList is empty\n");
        return;
    }
    node temp = H->nlink;
    while (temp != H)
    {
        printf("%d ", temp->info);
        temp = temp->nlink;
    }
}

void InsertByOrder(node H)
{
    node NN = CreateNode();
    printf("\nEnter the details to be inserted\n");
    scanf("%d", &NN->info);

    node CN = H->nlink;
    while (CN != H && NN->info > CN->info)
        CN = CN->nlink;

    NN->nlink = CN;
    NN->plink = CN->plink;
    CN->plink = NN;
    NN->plink->nlink = NN;
    H->info++;
}

void DeleteByKey(node H)
{
    if (H->info == 0)
        return;

    int key;
    printf("\nEnter the key to be delted\n");
    scanf("%d", &key);
    node CN = H->nlink;
    while (CN != H)
    {
        if (CN->info == key)
        {
            printf("\nDeleted %d\n", CN->info);
            CN->plink->nlink = CN->nlink;
            CN->nlink->plink = CN->plink;
            H->info--;
            return;
        }
        CN = CN->nlink;
    }

    printf("\nInvalid key\n");
}

void DeleteLeft(node H)
{
    if (H->info == 0)
        return;

    int pos;
    printf("\nEnter the position:\n");
    scanf("%d", &pos);

    if (pos <= 1 || pos > H->info)
    {
        printf("\nInvalid position\n");
        return;
    }

    int count = 1;
    node CN = H->nlink;
    while (count < pos)
    {
        CN = CN->nlink;
        count++;
    }

    node del = CN->plink;
    printf("\nDeleted %d\n", del->info);
    del->plink->nlink = del->nlink;
    CN->plink = del->plink;
    H->info--;
}
