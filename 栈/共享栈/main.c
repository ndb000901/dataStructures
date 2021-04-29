/************************************
 * 
 * auther:wuhen
 * Time:2021.4.29
 * details:共享栈
 * 
************************************/

#include<stdlib.h>
#include<stdio.h>

#define ERROR 0
#define OK 1
#define MAXSIZE 10
#define STATUS int
#define DATA_TYPE int
#define LEFT 0
#define RIGHT 1

struct Stack
{
    DATA_TYPE stack[MAXSIZE];
    int topLeft;
    int topRight;
};

void initStack(struct Stack* stack)
{
    stack->topLeft = -1;
    stack->topRight = MAXSIZE;
}

STATUS push(struct Stack* stack,DATA_TYPE e,int type)
{
    if(stack->topLeft == stack->topRight - 1)
    {
        return ERROR;
    }
    if(type == LEFT)
    {
        stack->topLeft++;
        stack->stack[stack->topLeft] = e;
        return OK;
    }
    if(type == RIGHT)
    {
        stack->topRight--;
        stack->stack[stack->topRight] = e;
        return OK;
    }

}

STATUS pop(struct Stack* stack,DATA_TYPE* e,int type)
{
    if(type == LEFT && stack->topLeft == -1)
    {
        return ERROR;
    }
    if(type == RIGHT && stack->topRight == MAXSIZE)
    {
        return ERROR;
    }
    if(type == LEFT)
    {
        *e = stack->stack[stack->topLeft];
        stack->topLeft--;
        return OK;
    }
    if(type == RIGHT)
    {
        *e = stack->stack[stack->topRight];
        stack->topRight++;
        return OK;
    }

}

void clearStack(struct Stack* stack)
{
    stack->topLeft = -1;
    stack->topRight = MAXSIZE;
}

int main()
{
    struct Stack* stack = malloc(sizeof(struct Stack));
    initStack(stack);
    int i;
    for(i = 0;i < 4;i++)
    {
        push(stack,i,LEFT);
    }
    for(i = 4;i < 8;i++)
    {
        push(stack,i,RIGHT);
    }
    for(i = 0;i < 2;i++)
    {
        int temp;
        pop(stack,&temp,LEFT);
        printf("%d\n",temp);
        pop(stack,&temp,RIGHT);
        printf("%d\n",temp);

    }

    return 0;
}
