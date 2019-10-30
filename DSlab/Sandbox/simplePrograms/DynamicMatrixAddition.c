#include<stdio.h>
#include<stdlib.h>
void Read(int *,int , int);
void Display(int *,int ,int );
void Add(int *,int ,int ,int *,int ,int ,int *);
int i,j;
void main()
{
	int *a, *b ,*sum;
        int m1,n1,m2,n2;
        printf("Enter the rows and columns of the first Matrix\n");
        scanf("%d %d",&m1, &n1);
	
	a = (int *)malloc(m1 * n1 * sizeof(int));

	if(a != NULL)
	printf("The memory of %d bytes is allocated at address %u\n",(m1 * n1 * sizeof(int)),a);
   
        printf("Enter the elements of the first Matrix\n");
        Read(a,m1 ,n1 );
        printf("The entered elements are\n");
	Display(a,m1 ,n1 );

        printf("Enter the rows and columns of the second Matrix\n");
        scanf("%d %d",&m2, &n2);

	b = (int *)malloc(m1 * n1 * sizeof(int));

	if(b != NULL)
	printf("The memory of %d bytes is allocated at address %u\n",(m2 * n2 * sizeof(int)),b);
   

	printf("Enter the elements of the second Matrix\n");
        Read(b,m2 ,n2 );
        printf("The entered elements are\n");
	Display(b,m2 ,n2 );
	
	sum = (int *)malloc(m1 * n1 * sizeof(int));

	Add(a,m1 ,n1 ,b ,m2 ,n2 ,sum );
	printf("The Sum matrix is");
	Display(sum,m2 ,n2);
}


void Read(int *X,int m, int n)
{
	for(i = 0; i < m ; i++)
		for(j = 0; j < n ; j++)
			scanf("%d",(X + i * n + j));
}
void Display(int *X,int m,int n)
{	
	printf("\n");
	for(i = 0; i < m ; i++)
	{
		for(j = 0; j < n ; j++)
			printf(" %d",*(X + i * n + j));
		printf("\n");
	}
}
void Add(int *X,int m1,int n1,int *Y,int m2,int n2,int *sum)
{
	if(m1 != m2 || n1 != n2)
	{
		printf("Matrices are not compatible for addition. Program is exiting\n");
		exit(0);
	}
	else
	{
		for(i = 0; i < m1 ; i++)
			for(j = 0; j < n1 ; j++)
				*(sum + i * n1 + j) = *(X + i * n1 + j) + *(Y + i * n1 + j);
	}
}

	
   
