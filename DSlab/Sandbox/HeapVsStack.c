#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n;
    int a[5];
    int b[5];
    printf("\nMemory addresses of stack are:");
    printf("\nStack grows from ");
    printf("\na[0] = %u",&a[0]);
    printf("\nb[0] = %u",&b[0]);
    n = &b[0] - &a[0];
    printf("\nConclusion: stack grows from %s",n>0?"lower memory to higher memory":"higher memory to lower memory");

    printf("\n\nMemory addresses of heap are:");

    int *p;
    p = (int*) malloc(5*sizeof(int));
    printf("\np[0] = %u",p);

    int *q;
    q = (int*) malloc(5*sizeof(int));
    printf("\nq[0] = %u",q);

     n = q - p;
    printf("\nConclusion: stack grows from %s",n>0?"lower memory to higher memory":"higher memory to lower memory");

}