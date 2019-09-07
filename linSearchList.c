#include"operHeader.h"


void linSearchByKey(node F);

void main() {

	node First = NULL;
	int choice;

	while(1) {

		printf("Enter your choice:\n");
		printf("1:InsertFront\n2:InsertRear\n3:DeleteFront\n4:DeleteRear\n5:display\n6:Search Item By Key\n");

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

	printf("Enter the item");
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

