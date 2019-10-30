#include<stdio.h>
#include<stdlib.h>

typedef struct Student {
    int regno;
    char name[10];
    float marks;
}Student;

void Read(Student *s);
void Display(Student *s);
void InsertByOrder(Student *s);
void DeleteByKey(Student *s);

void Check(Student *s,int );

int NE = 0, i,size;


void main() {
	system("clear");
    Student *s;
    int choice;

    printf("Enter the total number of students to whom the memory is to be allocated\n");
    scanf("%d",&size);

    s = (Student *) malloc(size * sizeof(Student));
    Check(s,size);

    while(1) {
        printf("\n___________________________________________________________________\n");
        printf("\nEnter your choice:\n");
        printf("1:Read\n2:Display\n3:InsertByOrder\n4:DeleteByKey\n");

        scanf("%d",&choice);

        switch (choice) {
            case 1:Read(s);break;
            case 2:Display(s);break;
            case 3:InsertByOrder(s);Display(s);break;
            case 4:DeleteByKey(s);Display(s);break;
            default :exit(0);
        }
    }
}

void Read(Student *s) {
    int n;
    printf("Enter the number of students:\n");
    scanf("%d",&n);

    NE = n;

    if (n > size){
        printf("Memory full, reallocating memory block\n");
        s = (Student *) realloc(s,(NE)*sizeof(Student));
        Check(s,NE);
    }

    for(i = 0;i< NE;i++){
        printf("Enter the details of student %d\n",i+1);

        printf("Enter the RegNo:");
        scanf("%d",&(s+i)->regno);
        printf("Name:");
        scanf("%s",(s+i)->name);
        printf("Enter the marks:");
        scanf("%f",&(s+i)->marks);
        printf("\n");
    }
}

void Display(Student *s) {
    for(i = 0;i<NE;i++) {
        printf("\nStudent %d\n",i+1);
        printf("RegNo: %d\n",(s+i)->regno);
        printf("Name: %s\n",(s+i)->name);
        printf("marks: %0.2f\n",(s+i)->marks);
    }
}

void Check(Student *s,int n) {
	if(s!=NULL) 
		printf("\nMemory of %d bytes has been allocated at address %u\n",(n * sizeof(Student)),s);

	
}

void InsertByOrder(Student *s) {
	if(NE == size) {
		printf("Memory full, reallocating memory block\n");
        	s = (Student *) realloc(s,(NE+1)*sizeof(Student));
        	Check(s,NE+1);
	}
	
	Student n;
	printf("Enter the details of new student \n");

        printf("Enter the RegNo:");
        scanf("%d",&n.regno);
        printf("Name:");
        scanf("%s",(n.name));
        printf("Enter the marks:");
        scanf("%f",&(n.marks));
        printf("\n");
	
	for(i = NE -1;n.regno < (s+i)->regno; i--) {
		*(s+i+1) = *(s+i);
	}
	
	*(s+i+1) = n;
	NE++;
}

void DeleteByKey(Student *s) {
	int pos = 0,Regno;
	if(NE == 0) {
		printf("\nEmpty, exiting");
		return;
	}

	printf("\nEnter the Regno of the student to be deleted\n");
	scanf("%d",&Regno); 
	for(i=0;i<NE;i++) {
		if((s+i)->regno == Regno) {
			pos = i+1;
			break;
		}
	}

	if(pos == 0) {
		printf("\nStudent with regno %d is not found\n",Regno);
		return;
	}

	printf("\npos = %d \n",pos);


	printf("\nDeleted student with information at position %d\n",pos);
	printf("RegNo: %d\n",(s+i)->regno);
        printf("Name: %s\n",(s+i)->name);
        printf("marks: %0.2f\n",(s+i)->marks);
	
	for(i = pos -1;i<NE;i++)
		*(s+i) = *(s+i+1);
	
	NE--;
}
	
	

	








































