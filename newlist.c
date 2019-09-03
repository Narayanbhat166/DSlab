#include<stdio.h>
#include<stdlib.h>

struct node {
	int info;
	struct node *link;  //Address of the next node
};

typedef struct node *NODE;

NODE createNode();

int main () {
	NODE First = NULL;

	First = createNode();
	if( First != NULL) {
		printf("A new node is created at adress %u\n",First);
	}


}

NODE createNode() {
	NODE NN = NULL;
	NN = (NODE) malloc(sizeof(struct node));
	return NN;
}