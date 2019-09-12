/*Please find the below header file for more details*/
#include"operHeader.h"

node InsertByPos(node);
node DeleteByPos(node);

void main() {

	node First = NULL;
	int choice;

	while(1) {

		printf("\nEnter your choice:\n");
		printf("1:InsertFront\n2:InsertRear\n3:DeleteFront\n4:DeleteRear\n5:display\n6:Insert Item By position\n7:Delete Item by position\n");

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
			case 6:First = InsertByPos(First);
				   break;
		        case 7:First = DeleteByPos(First);Display(First);
			 	   break;
			default:exit(0);
		}
	}
}

node InsertByPos(node F) {
	node NN;
	NN = createnode();
	NN->link = NULL;

	int pos, count = 1;

	printf("\nEnter the details to be inserted\n");
	scanf("%d",&NN->info);

	printf("\nEnter the position where %d is to be inserted\n",NN->info);
	scanf("%d",&pos);

	if(F==NULL && pos == 1) {
		F = NN;
		printf("\nList empty\nInserted %d at position %d\n", NN->info, count);
		return F;
	}

	if(F==NULL && pos != 1) {
		printf("\nInvalid position, returning to main\n");
		return F;
	}

	if(F != NULL && pos == 1) {
		NN->link = F;
		printf("\nInserted %d at position %d\n", NN->info, count);
		return NN;
	}

	node CN = F, PN = NULL;
	while(CN != NULL && count != pos) {
		PN = CN;
		CN = CN->link;
		count++;
	}

	if(count != pos) {
		printf("\nInvalid position, returning to main\n");
		return F;
	}

	PN -> link = NN;
	NN -> link = CN;

	printf("\nInserted %d at position %d\n", NN->info, count);
	Display(F);
	return F;
}


node DeleteByPos(node F) {
	if (F == NULL) {
		printf("\nThe list is empty\n");
		return F;
	}

	int pos;
	printf("\nEnter the position To be deleted:\n");
	scanf("%d",&pos);

	if(F->link == NULL && pos != 1 || pos == 0) {
		printf("\nInvalid position\n");
		return F;
	}

	
	if(pos == 1) {
		printf("\nDeleted %d at position %d\n",F->info,pos);
		node T = F;
		free(T);
		return F->link;
	}

	if (pos > 1) {
		node CN = F,PN = NULL;
		int count=1;
		while(CN != NULL && count != pos ) {
			PN = CN;
			CN = CN -> link;
			count ++;
		}

		if(CN == NULL) {
			printf("\nInvalid position\n");
			return F;
		}
	

		PN -> link = CN -> link;
		printf("\nDeleted %d at position %d\n",CN->info,count);
		free(CN);
		return F;
		}
}
		
			
	