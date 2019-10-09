#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct term
{
	int cf;
	int px;
	int py;
	int flag; //0 if used and 1 if not used

	struct term *link;
};

typedef struct term *term;

struct Head
{
	int info;
	term link;
};

typedef struct Head *Head;

term createTerm()
{
	term NN=NULL;
	NN = (term) malloc(sizeof(struct term));
	NN ->flag = 1;
	return NN;
}

void createPoly(Head);
void Display(Head);
void Evaluate(Head);
Head Add(Head,Head);
void DeleteTerm(term);

void main()
{
	Head poly1;
	Head poly2;
	Head poly3;
	
	poly1 = (Head) malloc(sizeof(struct Head));
	poly2 = (Head) malloc(sizeof(struct Head));
	
	poly1->info = 0;
	poly2->info = 0;
	
	poly1->link = NULL;
	poly2->link = NULL;

	printf("\nCreating polynomial 1");
	createPoly(poly1);
	Display(poly1);

	printf("\nCreating polynomial 2");
	createPoly(poly2);
	Display(poly2);
	
	poly3 = Add(poly1,poly2);
	Display(poly1);
	Display(poly2);
	printf("\nResulting polynomial is\n");
	Display(poly3);



}	

void createPoly(Head H)
{
	int cf;
	term LN = H->link;
	printf("\nTo terminate, enter coefficient as 0");
	while(1)
	{
		printf("\nEnter the coefficient of the term\n");
		scanf("%d",&cf);
		if(cf == 0)
		{	
			printf("\nPolynomial created\n");
			break;
		}
		term NN = createTerm();
		NN->cf = cf;
		NN->link = NULL;
		printf("\nEnter the power of x and y\n");
		scanf("%d %d",&NN->px,&NN->py);
		if(H->info == 0)
			H->link = NN;
		else
			LN -> link = NN;
		LN = NN;
		H->info++;
	}
}

void Display(Head H)
{
	if(H->info == 0)
	{
		printf("\nPolynimial is empty");
		return;
	}

	term temp = H->link;
	printf("\n");
	while(temp!=NULL)
	{
		if(temp->cf != 0)
			printf("%+d",temp->cf);
		if(temp->px != 0)
			printf("x%d",temp->px);
		if(temp->py != 0)
			printf("y%d ",temp->py);
		temp = temp -> link;
	}
}
			
void Evaluate(Head H)
{
	int x;
	int y;
	int sum = 0;

	printf("\nEnter the values of x and y\n");
	scanf("%d %d",&x,&y);
	term temp = H->link;
	while(temp!=NULL)
	{
		sum+=(temp->cf) * (pow(x,temp->px)) * (pow(y,temp->py));
		temp = temp->link;
	}
	printf("\nValue of the polynomial is: %d",sum);
}

Head Add(Head H1,Head H2)
{
	printf("In add");
	Head result;
	result = (Head) malloc(sizeof(struct Head));
	result->info =0;
	result->link = NULL;

	term temp1 = H1->link;
	term temp2 = NULL;
	term LN=NULL;
	while(temp1!=NULL)
	{
		temp2 = H2->link;
		while(temp2!=NULL)
		{
			if(temp1->px==temp2->px && temp1->py==temp2->py)
			{
				if(temp1->cf+temp2->cf == 0)
				{
					temp1->flag=0;
					temp2->flag=0;
					break;
				}
			
				term NN = createTerm();
				NN->cf = temp1->cf+temp2->cf;
				NN->px = temp1->px;
				NN->py = temp1->py;
				NN->link = NULL;
				if(result->info ==0)
					result->link = NN;
				else
					LN -> link = NN;
				LN = NN;
				result->info++;

				temp2->flag=0; //terms are used
				temp1->flag=0; //terms are used
				break;
			}
			temp2 = temp2->link;
			
		}
		temp1 = temp1->link;
	}

	printf("First loop ran");

	//to add those terms which are not used

	temp1 = H1->link;
	while(temp1!=NULL)
	{
		if(temp1->flag != 0)
		{
				term NN = createTerm();
				NN->cf = temp1->cf;
				NN->px = temp1->px;
				NN->py = temp1->py;
				NN->link = NULL;
				if(result->info ==0)
					result->link = NN;
				else
					LN -> link = NN;
				LN = NN;
				result->info++;
		}
		temp1 = temp1->link;
	}

	printf("Second loop also ran man");

	temp2 = H2->link;
	while(temp2!=NULL)
	{
		if(temp2->flag != 0)
		{
			term NN = createTerm();
				NN->cf = temp2->cf;
				NN->px = temp2->px;
				NN->py = temp2->py;
				NN->link = NULL;
				if(result->info ==0)
					result->link = NN;
				else
					LN -> link = NN;
				LN = NN;
				result->info++;
		}
		temp2= temp2->link;
	}
	printf("leaving add");
	return result;



}


	

