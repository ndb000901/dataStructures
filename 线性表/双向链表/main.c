/************************************
 * 
 * auther:wuhen
 * Time:2021.4.27
 * details:双向链表
 * 
************************************/

#include<stdlib.h>
#include<stdio.h>

#define ERROR 0
#define OK 1
#define STATUS int
#define DATA_TYPE int 

struct Node 
{
    DATA_TYPE data;
    struct Node* next;
    struct Node* prior;
};

struct ListHead
{
    int lengh;
    struct Node* next;
    struct Node* tail;
};

void initList(struct ListHead* head)
{
    head->lengh = 0;
    head->next = NULL;
    head->tail = NULL;
}

STATUS addHeadElement(struct ListHead* head,DATA_TYPE e)
{
    struct Node* node = malloc(sizeof(struct Node));
    node->data = e;
    if(head->lengh == 0)
    {
        node->next = NULL;
        node->prior = NULL;
        head->next = node;
        head->tail = node;
        head->lengh++;
        return OK;
    }
    node->next = head->next;
    node->prior = NULL;
    head->next->prior = node;
    head->next = node;
    head->lengh++;
    return OK;

}

STATUS addTailElement(struct ListHead* head,DATA_TYPE e)
{
    struct Node* node = malloc(sizeof(struct Node));
    node->data = e;
    if(head->lengh == 0)
    {
        node->next = NULL;
        node->prior = NULL;
        head->next = node;
        head->tail = node;
        head->lengh++;
        return OK;
    }
    node->next = NULL;
    node->prior = head->tail;
    head->tail->next = node;
    head->tail = node;
    head->lengh++;
    return OK;
}

STATUS insertElement(struct ListHead* head,int index,DATA_TYPE e)
{
    if(index < 1 || index > head->lengh + 1)
    {
        return ERROR;
    }
    struct Node* node = malloc(sizeof(struct Node));
    struct Node* p = head->next;
    node->data = e;
    if(index == 1)
    {
        addHeadElement(head,e);
        return OK;
    }
    if(index == head->lengh + 1)
    {
        addTailElement(head,e);
        return OK;
    }
    int i = 1;
    while(i < index - 1)
    {
        p = p->next;
        i++;
    }
    node->next = p->next;
    node->prior = p;
    p->next->prior = node;
    p->next = node;
    head->lengh++;
    return OK;
}

void printListHead(struct ListHead* head)
{
    struct Node* p = head->next;
    while(p)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
}
void printListTail(struct ListHead* head)
{
    struct Node* p = head->tail;
    while(p)
    {
        printf("%d\n",p->data);
        p = p->prior;
    }
}

STATUS alterElementByIndex(struct ListHead* head,int index,DATA_TYPE e)
{
    if(head->lengh == 0 || index < 1 || index > head->lengh)
    {
        return ERROR;
    }
    struct Node* p = head->next;
    int i = 1;
    while(i < index)
    {
        p = p->next;
        i++;
    }
    p->data = e;
    return OK;
    

}

STATUS alterElementByValue(struct ListHead* head,DATA_TYPE value,DATA_TYPE e)
{
    struct Node* p = head->next;
    while(p)
    {
        if(p->data == value)
        {
            p->data = e;
        }
        p = p->next;
    }
    return OK;
}

STATUS deleteElement(struct ListHead* head,int index)
{

}

void clearList(struct ListHead* head)
{
    struct Node* p = head->next;
    struct Node* q;
    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    head->next = NULL;
    head->tail = NULL;
    head->lengh = 0;
}

int main()
{
    struct ListHead* head = malloc(sizeof(struct ListHead));
    initList(head);
    int i;
    // for(i = 0;i < 10;i++)
    // {
    //     addHeadElement(head,i);
    // }
    // for(i = 10;i < 20;i++)
    // {
    //     addTailElement(head,i);
    // }
    insertElement(head,1,1);
    insertElement(head,1,2);
    insertElement(head,2,3);
    insertElement(head,2,4);
    insertElement(head,2,5);
    printListHead(head);
    printf("-------------------------------\n");
    printListTail(head);
    return 0;
}