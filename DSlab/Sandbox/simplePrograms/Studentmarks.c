#include<stdio.h>
#include<stdlib.h>
struct student
{
  int regno;
  char name[10];
float marks[3];
float avg;
};
typedef struct student STU;
void read(STU[]);
void write(STU[]);
void calculate(STU[]);
int n;
void main()
{
 STU s[20];
printf("Enter the number of students\n");
scanf("%d",&n);
int ch; 
for(;;)
{  printf(" Enter 1 to read\n 2 to write\n 3 to calculate\n");
    scanf("%d",&ch);
   switch(ch)
  {
     case 1: read(s);
     break;
     case 2: write(s);  
     break;
     case 3:calculate(s); 
     break;
     default: exit(0);
   }
}
}
void read(STU A[])
{ 
   int i,j;
  for(i=0;i<n;i++)
   {  
       printf("Enter the regno name and marks of student %d in three tests",i+1);
       scanf("%d %s",&A[i].regno,A[i].name);
       for(j=0;j<3;j++)
        { 
          scanf("%f",&A[i].marks[j]);
         }
    }
}
void write(STU A[])
{ printf("REGNO\tNAME\tTEST1\tTEST2\tTEST3\n__________________________________________________\n");
   int i,j;
  for(i=0;i<n;i++)
   {  printf("%d\t%s\t",A[i].regno,A[i].name);
       for(j=0;j<3;j++)
        { 
          printf("%.2f\t",A[i].marks[j]);
         } 
        printf("\n");
    }
    printf("\n");
}
void calculate(STU A[])
{
  float min,sum;
  int i,j;
  for(i=0;i<n;i++)
     { 
       min=A[i].marks[0];
       sum=A[i].marks[0];
        for(j=1;j<3;j++)
           {
             sum+=A[i].marks[j];
                if(A[i].marks[j]<min)
                {
                  min=A[i].marks[j];
                 }
            }
        A[i].avg=(sum-min)/2;
        printf("The average of best 2 of student %d is %.2f\n",i+1,A[i].avg);
      }
}
        
