#include<stdio.h>
int main()
{
   system("clear");
   int x,y,*px=&x,*py=&y,sum,*sump=&sum;
   printf("Enter two numbers\n");
   scanf("%d %d",px,py);
   printf("x = %d is at location %u and y = %d is at location %u\n",*px,px,*py,py);
   *sump = *px + *py;
   printf("sum = %d is at location %u",*sump,sump);
   return 0;
}
