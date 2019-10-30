/*Please find the below header file for more details*/
#include"operHeader.h"


node InsertByOrder(node);
node DeleteByKey(node);

int main () {
	node First = NULL;
	int choice;
	

	while(1) {
		printf("Enter your choice:\n");
		printf("1:InsertByOrder\n2:DeleteByKey\n3:display\n");

		scanf("%d",&choice);
	
		switch(choice) {
			case 1:First = InsertByOrder(First);Display(First);
				   break;
			case 2:First = DeleteByKey(First);Display(First);
				   break;
			case 3:Display(First);
				   break;
			default:exit(0);
		}
	}
	return 0;
}


node InsertByOrder(node F) {
	node NN;
	NN = createnode();
	NN->link = NULL;

	printf("\nEnter the details to be inserted\n");
	scanf("%d",&NN->info);

	if(F==NULL) {
		F = NN;
		printf("\nList empty\n");
		return F;
	}

	if(F->info >= NN->info) {
		NN ->link = F;
		return NN;
	}

	node CN = F, PN = NULL;

	while(CN!=NULL && NN->info > CN->info) {
		PN = CN;
		CN = CN -> link;
	}

	NN -> link = CN;
	PN -> link = NN;


	return F;
}


node DeleteByKey(node F) {
	if (F == NULL) {
		printf("\nThe list is empty, Returning to main\n");
		return F;
	}

	int pos = 1,item;
	
	printf("\nEnter the item to be removed\n");
	scanf("%d",&item);

	if(F->info == item) {
		printf("\nDeleted %d at position %d\n",item,pos);
		F = F->link;
		return F;
	}

	node CN,PN = NULL;
	CN = F;

	

	

	while(CN != NULL && CN->info != item) {
		PN = CN;
		CN = CN->link;
		pos++;
	}

	if(CN == NULL) {
		printf("The element does not exist\n");
		return F;
	}

	else

		printf("\nDeleted %d at position %d\n",item,pos);

		PN->link = CN->link;
		free(CN);

		return F;

}
