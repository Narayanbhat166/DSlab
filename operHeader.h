/*This file serves as the header file for all the other functions*/

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

	printf("\nDeleted %d\n",F->info);
	free(LN->link);

	LN->link = NULL;

	Display(F);
	return F;

}