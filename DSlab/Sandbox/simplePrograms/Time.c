#include<stdio.h>
#include<stdlib.h>

struct Time
{
	int hr ;
	int min;
	int sec;
};

typedef struct Time T;

void Read(T *);
void Display(T *);
void Add(T *,T *,T *);
void Update(T *);
void Check(T *);

void main()
{
	int choice;
	T T1, T2, T3, *t1 = &T1 , *t2 = &T2, *t3 = &T3;
	
	while(1)
	{
		printf("\nEnter your choice\n");
		printf("1:Read\n2:Display\n3:Add two times\n4:Update\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:Read(t1);
				break;
			case 2:Display(t1);
				break;
			case 3:Read(t2);
			       Add(t1,t2,t3);
			       Display(t3);
			        break;
			case 4:Update(t1);
			       Display(t1);
			       break;
			default:exit(0);
			
		}
	} 
}

void Read(T *x)
{
	printf("Enter the time in hh:mm:ss format\n");
	scanf("%d:%d:%d",&x->hr,&x->min,&x->sec);
}

void Display(T *x)
{
	printf("\n%0.2d:%0.2d:%0.2d",x->hr,x->min,x->sec);
	printf("\n");
}

void Add(T *x, T *y, T *sum)
{
	sum->sec = x->sec + y->sec; 	
	sum->min = x->min + y->min; 	
	sum->hr = x->hr + y->hr; 	
	
	Check(sum);
}


void Update(T *x)
{
	(x->sec)++;
	Check(x);
}


void Check(T *x)
{
	if(x->sec >= 60)
	{
		x->sec = x->sec - 60;
		(x->min)++;
	}
	
	if(x->min >= 60)
	{
		x->min = x->min - 60;
		(x->hr)++;
	}
	
	if(x->hr >=24)
		x->hr=0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
