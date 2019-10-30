#include<stdio.h>
#include<stdlib.h>

struct node {
	int info;
	struct node *link;
};

typedef struct node *node;

void InsertFront(node);
void InsertRear(node);
void DeleteFront(node);
void DeleteRear(node);
void Display(node);
node createNode() {
	node NN;
	NN = (node)malloc(sizeof(struct node));
	if(NN != NULL) 
		printf("\nNew node is created at address %u\n",NN);
	return NN;
}
void main() {
	int choice;
	node Header = NULL;
	Header = createNode();
	Header -> link = Header;
	Header -> info = 0;
	while(1) {
		printf("\nEnter your choice:\n");
		printf("1:InsertFront\n2:InsertRear\n3:DeleteFront\n4:DeleteRear\n5:Display\n");
		scanf("%d",&choice);
		switch(choice) {
			case 1:InsertFront(Header);
				break;
			case 2:InsertRear(Header);
				break;
			case 3:DeleteFront(Header);
				break;
			case 4:DeleteRear(Header);
				break;
			case 5:Display(Header);
				break;
			default :exit(0);
		}
	}
}

void InsertFront(node H) {
	node NN;
	NN = createNode();
	printf("\nEnter the details to be inserted\n");
	scanf("%d",&NN->info);
	NN ->link = H->link;
	H ->link = NN;
	H->info++;
	Display(H);
}

void InsertRear(node H) {
	node NN;
	NN = createNode();
	printf("\nEnter the details to be inserted\n");
	scanf("%d",&NN->info);
	node LN = H->link;
	while(LN ->link != H) 
		LN = LN ->link;
	LN->link = NN;
	NN -> link = H;
	H->info++;
	Display(H);
}

void DeleteFront(node H) {
	if(H->link == H ) {
		printf("\nList is Empty\n");
		return ;
	}

	node T = H->link;
	H->link = T->link;
	printf("\nDeleted %d\n",T->info);
	free(T);
	H->info--;
	Display(H);
}

void DeleteRear(node H) {
	if(H->link == H) {
		printf("\nList is Empty\n");
		return ;
	}

	node LN = H->link;
	while(LN ->link->link != H)
		LN = LN->link;
	printf("\nDeleted %d\n",LN->link->info);
	free(LN->link);
	LN ->link = H;
	H->info--;
	Display(H);
}

void Display(node H) {
	if(H->link == H) {
		printf("\nList is Empty\n");
		return ;
	}
	node T = H->link;
	while(T != H) {
		printf("%d ",T->info);
		T = T->link;
	}
}



	
