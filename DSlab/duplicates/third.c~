#include<stdio.h>
int main()
{
	system("clear");
	int a[10],*p = a,n,i,sum=0;
	printf("Enter a number");
	scanf("%d",&n);
	printf("\nEnter %d elements:\n",n);
	for(i=0;i<n;i++)
	{
	scanf("%d",p++);
	sum += *(--p);
	p++;
	}
	p=a;
	printf("\nThe entered elements are\n");
	for(i=0;i<n;i++)
	printf("%d ",*(p++));
	printf("\nThe sum is %d ",sum);
	return 0;
}
