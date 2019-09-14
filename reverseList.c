#include "operHeader.h"

node reverseList(node);

int main()
{
    node First = NULL;
    node revFirst = NULL;
    int choice;

    while (1)
    {
        printf("Enter your choice:\n");
        printf("1:InsertFront\n2:InsertRear\n3:DeleteFront\n4:DeleteRear\n5:display\n6:Reverse list\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            First = InsertFront(First);
            break;
        case 2:
            First = InsertRear(First);
            break;
        case 3:
            First = DeleteFront(First);
            break;
        case 4:
            First = DeleteRear(First);
            break;
        case 5:
            Display(First);
        case 6:
            revFirst = reverseList(First);
            Display(revFirst);
            break;
        default:
            exit(0);
        }
    }
}

node reverseList(node F)
{
    node T = F;
    node temp, LN = NULL;
    while (T != NULL)
    {
        temp = T;
        T = T->link;
        temp->link = LN;
        LN = temp;
    }

    return temp;
}