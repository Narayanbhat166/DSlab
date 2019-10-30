#include<stdio.h>

int fib(int n,int indent)
{
    printf("\n");
    for(int i=0;i<indent;i++)
        printf("|");
    printf("Fib(%d)",n);
    if(n==0 || n==1)
        return n;
    return fib(n-1,indent+1)+fib(n-2,indent+1);
}
void main()
{
    printf("\nFinal result is = %d",fib(5,0));
}