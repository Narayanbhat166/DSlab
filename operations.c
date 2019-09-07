#include<stdio.h>
#include<stdlib.h>

struct node {
	int info;
	struct node *link;  //Address of the next node
};

typedef struct node *node;

node createnode();
node InsertFront(node);
node InsertRear(node);
void Display(node);
node DeleteFront(node F);
node DeleteRear(node F);

int main () {
	node First = NULL;
	int choice;
	

	while(1) {
		printf("Enter your choice:\n");
		printf("1:InsertFront\n2:InsertRear\n3:DeleteFront\n4:DeleteRear\n5:display\n");

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
			default:exit(0);
		}
	}


}

node createnode() {
	node NN = NULL;
	NN = (node) malloc(sizeof(struct node));
	if (NN!=NULL)
		printf("\nNew node is created at address %u",NN);
	return NN;
}

node InsertFront(node F) {
	node NN = NULL;

	NN = createnode();
	NN->link=NULL;

	printf("\nEnter the details to be inserted\n");
	scanf("%d",&NN->info);
	if(F==NULL) {
		F = NN;
		printf("\nList empty\n");
	}
	else
		NN->link = F;
		F = NN;
	Display(F);
	return F;
}

void Display(node F) {

	if(F==NULL) {
		printf("\nList is empty\n");
		return;
	}

	printf("\n");
	while(F!=NULL) {
		printf(" %d",F->info);
		F = F->link;
	}
	printf("\n");
}

node InsertRear(node F) {
	node NN,LN;

	LN=F;

	NN = createnode();
	NN->link = NULL;

	printf("\nEnter the details to be inserted\n");
	scanf("%d",&NN->info);

	if(F==NULL) 
		return NN;

	while(LN->link != NULL) {
		LN = LN->link;
	}

	LN->link = NN;
	Display(F);
	return F;
}

node DeleteFront(node F) {
	if(F==NULL) {
		printf("List is empty\n");
		return F;
	}

	printf("\nDeleted %d\n",F->info);

	node NN=F;
	F=F->link;
	free(NN);
	Display(F);
	return F;
}

node DeleteRear(node F) {
	
	if(F == NULL) {
		printf("\nList is empty\n");
		return F;
	}

	if(F->link == NULL) {
		printf("\nDeleted %d\n",F->info);
		free(F);
		return NULL;
	}

	node LN=F;

	while(LN->link->link != NULL) 
		LN = LN -> link;

	printf("\nDeleted %d\n",LN->link->info);
	free(LN->link);

	LN->link = NULL;

	Display(F);
	return F;

}