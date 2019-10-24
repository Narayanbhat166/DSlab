#include"operandStack.h"
void main()
{
    operandStack stk;
    stk.top=-1;
    if(peek(&stk) == "empty")
    printf("Stack is empty\n");
    push(&stk,"Nani");
    if(peek(&stk)!="empty")
    printf("Top = %s",peek(&stk));
}