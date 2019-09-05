#include<stdio.h>
#include<stdlib.h>

struct node {
	int info;
	struct node *link;  //Address of the next node
};

typedef struct node *NODE;

NODE InsertByOrder(NODE);
NODE DeleteByKey(NODE);
void Display(NODE);
NODE createNode();

int main () {
	NODE First = NULL;
	int choice;
	

	while(1) {
		printf("Enter your choice:\n");
		printf("1:InsertByOrder\n2:DeleteByKey\n3:display\n");

		scanf("%d",&choice);
	
		switch(choice) {
			case 1:First = InsertByOrder(First);Display(First);
				   break;
			case 2:First = DeleteByKey(First);
				   break;
			case 3:Display(First);
				   break;
			default:exit(0);
		}
	}
}

NODE createNode() {
	NODE NN = NULL;
	NN = (NODE) malloc(sizeof(struct node));
	if (NN!=NULL)
		printf("\nNew node is created at address %u",NN);
	return NN;
}

NODE InsertByOrder(NODE F) {
	NODE NN;
	NN = createNode();
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

	NODE CN = F, PN = NULL;

	while(CN!=NULL && NN->info > CN->info) {
		PN = CN;
		CN = CN -> link;
	}

	NN -> link = CN;
	PN -> link = NN;


	return F;
}

void Display(NODE F) {

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
