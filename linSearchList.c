#include"operHeader.h"


void linSearchByKey(node F);
void linSearchByPos(node F);

void main() {

	node First = NULL;
	int choice;

	while(1) {

		printf("\nEnter your choice:\n");
		printf("1:InsertFront\n2:InsertRear\n3:DeleteFront\n4:DeleteRear\n5:display\n6:Search Item By Key\n7:Search Item by position\n");

		scanf("%d",&choice);
	
		switch(choice) {
			case 1:First = InsertFront(First);
				   break;
			case 2:First = InsertRear(First);
				   break;
			case 3:First = DeleteFront(First);
				   break;
			case 4:First = DeleteRear(First);
				   break;
			case 5:Display(First);
				   break;
			case 6:linSearchByKey(First);
				   break;
			case 7:linSearchByPos(First);
				   break;
			default:exit(0);
		}
	}
}

void linSearchByKey(node F) {
	if(F == NULL) {
		printf("\nThe list is empty\n");
		return;
	}

	int item, pos = 1;

	printf("\nEnter the item\n");
	scanf("%d",&item);

	while(F != NULL) {

		if (F -> info == item) {
			printf("%d is found at position %d \n", item, pos);
			return ;
		}

		F = F->link;
		pos++;
	}

	if(F == NULL) {
		printf("%d does not exist in the list\n", item);
		return;
	}
}

void linSearchByPos(node F) {
	if(F == NULL) {
		printf("\nThe list is empty\n");
		return;
	}

	int item, pos ,count = 1;

	printf("\nEnter the position\n");
	scanf("%d",&pos);

	while(F != NULL && count != pos) {
		F = F->link;
		count++;
	}

	if(F == NULL) {
		printf("%d is an invalid position\n", pos);
		return;
	}

	printf("\nThe item present at pos %d is %d\n",pos, F->info);

}

