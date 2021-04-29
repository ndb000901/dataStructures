/************************************
 * 
 * auther:wuhen
 * Time:2021.4.29
 * details:栈的顺序结构
 * 
************************************/

#include<stdio.h>

#define MAXSIZE 10
#define STATUS int
#define ERROR 0
#define OK 1
#define DATA_TYPE int 

struct Stack
{
    DATA_TYPE stack[MAXSIZE];
    int top;
};

void initStack(struct Stack* stack)
{
    stack->top = -1;
}

STATUS push(struct Stack* stack,DATA_TYPE e)
{
    if(stack->top == MAXSIZE - 1)
    {
        return ERROR;
    }
    stack->top++;
    stack->stack[stack->top] = e;
    return OK;

}

STATUS pop(struct Stack* stack,DATA_TYPE* e)
{
    if(stack->top == -1)
    {
        return ERROR;
    }
    *e = stack->stack[stack->top];
    stack->top--;
    return OK;
    
}

void clearStack(struct Stack* stack)
{
    stack->top = -1;
}

int main()
{
    struct Stack* stack = malloc(sizeof(struct Stack));
    initStack(stack);
    int i;
    for(i = 0;i < 6;i++)
    {
        push(stack,i);
    }
    for(i = 0;i < 3;i++)
    {
        int *temp = malloc(sizeof(sizeof(int)));
        pop(stack,temp);
        printf("%d\n",*temp);
    }
    return 0;
}














