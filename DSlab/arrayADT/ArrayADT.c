//Program to implement array abstract data type
#include<stdio.h>
#include<stdlib.h>

void Read(int *);
void Display(int *);
void Insert(int *);
void Delete(int *);
void InsertByOrder(int *);
void DeleteByKey(int *);

//To keep track of number of elements
int NE = 0,i,size;
void main() {
    int choice;
    int *p;

    printf("Enter the size of the array\n");
    scanf("%d",&size);

    p = (int *)malloc(size * sizeof(int));
    if(p!=NULL)
        printf("Memory space of %d bytes has been allocated \nMemory location %u",(size * sizeof(int)),p);
        else
        printf("Failed to allocate memory");

    while(1) {
        printf("\nEnter your choice:\n");
        printf("1:Read\n2:Display\n3:Insert\n4:InsertByOrder\n5:Delete\n");

        scanf("%d",&choice);

        switch (choice) {
            case 1:Read(p);break;
            case 2:Display(p);break;
            case 3:Insert(p);Display(p);break;
	    case 4:InsertByOrder(p);Display(p);break;
            case 5:Delete(p);Display(p);break;
	    //case 6:DeleteByKey(p);Display(p);break;
            default :exit(0);
        }
    }
}

void Read(int *x) {
    int n;
    printf("Enter the number of elements to be inserted:\n");
    scanf("%d",&n);

    if(n>size) {
        printf("Array limit exceeded,reallocating memory\n");
        x = (int * )realloc(x,n * sizeof(int));
    }

    NE = n;

    printf("\nEnter the elements to be inserted:\n");
    for(i = 0;i < n; i++)
        scanf("%d",(x+i));
}

void Display(int *x) {
    for(i = 0;i < NE; i++)
    printf(" %d",*(x + i));
}

void Insert(int *x) {
    int pos = 0,item=0;

    //check whether the array is full
    if(NE >= size) {
        printf("Array full, reallocating memory\n");
        x = (int *) realloc (x , (NE+1)*sizeof(int));
    }


    printf("Enter the item to be inserted\n");
    scanf("%d",&item);

    printf("Enter the position where the element is to be inserted\n");
    scanf("%d",&pos);

    while (pos < 1 || pos > NE + 1) {
        printf("Invalid position, Enter again\n");
        scanf("%d",&pos);
    }

    for(i = NE-1; i>=pos-1; i--)
        *(x + i +1) = *(x + i);
    *(x + pos - 1) = item;
    NE++;
}

void Delete(int *x) {
    int pos = 0;

    //Check if array is empty
    if (NE == 0) {
        printf("Array is empty, cannot delete items");
        return ;
    }

    printf("Enter the position to be deleted\n");
    scanf("%d",&pos);

    while (pos < 1 || pos >= NE + 1) {
        printf("Invalid position, Enter again\n");
        scanf("%d",&pos);
    }

    for(i = pos-1 ; i<NE-1 ; i++)
        *(x + i) = *(x + i +1);
    NE--;
}


void InsertByOrder(int *x) {
	int i,item;
	if(NE == size) {
		printf("\nMemory full, reallocating memory\n");
		x = (int *) realloc (x,(NE + 1)*sizeof(int));
	}

			
	printf("Enter the item to be inserted\n");
    	scanf("%d",&item);

	for(i = NE-1;*(x+i) > item ;i++) 
		*(x + i + 1) = *(x+i);
	*(x+i) = item;
	NE++;
}
















