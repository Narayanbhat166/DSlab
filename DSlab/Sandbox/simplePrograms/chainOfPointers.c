#include<stdio.h>
int main()
{
   system("clear");
   printf("This is a program to illustrate the chain of pointers");
   int x,*p1 = &x,**p2 = &p1,***p3 = &p2;
   printf("\nEnter a number\n");
   scanf("%d",&x);
   printf("value of x = %d it is at location %u\n",*p1,p1);
   printf("value of p1 = %u it is at location %u\n",*p2,p2);
   printf("value of p2 = %u it is at location %u\n",*p3,p3);
   return 0;
}
