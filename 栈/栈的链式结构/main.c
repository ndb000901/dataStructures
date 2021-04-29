/************************************
 * 
 * auther:wuhen
 * Time:2021.4.29
 * details:栈的链式结构
 * 
************************************/

#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define DATA_TYPE int
#define STATUS int

struct Node
{
    DATA_TYPE data;
    struct Node* next;
};

struct Stack
{
    struct Node* top;
    int lengh;
};

void initStack(struct Stack* stack)
{
    stack->lengh = 0;
    stack->top = NULL;
}

STATUS push(struct Stack* stack,DATA_TYPE e)
{
    struct Node* node = malloc(sizeof(struct Node));
    node->data = e;
    if(stack->lengh == 0)
    {
        node->next = NULL;
        stack->top = node;
        stack->lengh++;
        return OK;
    }
    node->next = stack->top;
    stack->top = node;
    stack->lengh++;
    return OK;
}

STATUS pop(struct Stack* stack,DATA_TYPE* e)
{
    if(stack->lengh == 0)
    {
        return OK;
    }
    struct Node* p;
    p = stack->top;
    *e = p->data;
    stack->top = p->next;
    free(p);
    stack->lengh--;
    return OK;

}

void clearStack(struct Stack* stack)
{
    struct Node* p = stack->top;
    struct Node* q;
    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    stack->lengh = 0;
    stack->top = NULL;

}

int main()
{
    struct Stack* stack = malloc(sizeof(struct Stack));
    initStack(stack);
    int i;
    for(i = 1;i < 6;i++)
    {
        push(stack,i);
    }
    // for(i = 1;i < 3;i++)
    // {
    //     int temp;
    //     pop(stack,&temp);
    //     printf("%d\n",temp);
    // }
    clearStack(stack);
    return 0;
}
