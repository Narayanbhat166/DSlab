#include "operHeader.h"

node Concatenate(node, node);

int main()
{
    node L1First = NULL;
    node L2First = NULL;
    int choice;

    while (1)
    {
        printf("Enter your choice:\n");
        printf("\n1:InsertFront of List 1\n2:Insert Front of List 2\n3:Insert rear of list 1 \n4:Insert rear of list 2:\n5:display list 1\n6:display list 2\n7:Concatenate list 1 and list 2\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            L1First = InsertFront(L1First);
            break;
        case 2:
            L2First = InsertFront(L2First);
            break;
        case 3:
            L1First = InsertRear(L1First);
            break;
        case 4:
            L2First = InsertRear(L2First);
            break;
        case 5:
            Display(L1First);
            break;
        case 6:
            Display(L2First);
            break;
        case 7:
            Concatenate(L1First, L2First);
            break;
        default:
            exit(0);
        }
    }
}

node Concatenate(node f1, node f2)
{

    if (f1 == NULL)
    {
        f1 = f2;
        printf("Successfully concatenated the lists");
        Display(f1);
        return f1;
    }

    node temp = f1;

    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = f2;

    printf("Successfully concatenated the lists");
    Display(f1);

    return f1;
}