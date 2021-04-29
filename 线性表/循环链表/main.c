/************************************
 * 
 * auther:wuhen
 * Time:2021.4.29
 * details:循环链表
 * 
************************************/

#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define STATUS int
#define DATA_TYPE int
#define NOTFOUND -1

struct Node
{
    DATA_TYPE data;
    struct Node* next;
};

struct List
{
    int lengh;
    struct Node* head;
    struct Node* tail;
};

void initList(struct List* list,struct Node* head)
{
    list->lengh = 0;
    list->head = head;
    list->tail = NULL;
}

STATUS addHeadElement(struct List* head,DATA_TYPE e)
{
    struct Node* node = malloc(sizeof(struct Node));
    node->data = e;
    if(head->lengh == 0)
    {
        head->tail = node;
        node->next = head->head;
        head->head->next = node;
        head->lengh++;
        return OK;
    }
    node->next = head->head->next;
    head->head->next = node;
    head->lengh++;
    return OK;
}

STATUS addTailElement(struct List* head,DATA_TYPE e)
{
    struct Node* node = malloc(sizeof(struct Node));
    node->data = e;
    if(head->lengh == 0)
    {
        head->tail = node;
        node->next = head->head;
        head->head->next = node;
        head->lengh++;
        return OK;
    }
    head->tail->next = node;
    head->tail = node;
    node->next = head->head;
    head->lengh++;
    return OK;

}

STATUS alterElementByIndex(struct List* head,int index,DATA_TYPE e)
{
    if(head->lengh == 0 || index < 1 || index > head->lengh)
    {
        return ERROR;
    }
    struct Node* p = head->head->next;
    int i;
    for(i = 1;i < index;i++)
    {
        p = p->next;
    }
    p->data = e;
    return OK;
    
}

STATUS alterElementByValue(struct List* head,DATA_TYPE value,DATA_TYPE e)
{
    if(head->lengh == 0)
    {
        return ERROR;
    }
    struct Node* p = head->head->next;
    while(p != head->head)
    {
        if(p->data == value)
        {
            p->data = e;
        }
        p = p->next;
    }
    return OK;
}

STATUS deleteElement(struct List* head,int index)
{
    if(head->lengh == 0 || index < 1 || index > head->lengh)
    {
        return ERROR;
    }
    struct Node* p = head->head->next;
    struct Node* q;
    if(index == 1)
    {

        head->head->next = p->next;
        if(head->lengh == 1)
        {
            head->tail = 0;
            head->head->next = NULL;
        }
        free(p);
        head->lengh--;
        return OK;
    }
    int i;

    for(i = 1;i < index;i++)
    {
        q = p;
        p = p->next;
    }
    if(index == head->lengh)
    {
        q->next = head->head;
        free(p);
        head->tail = q;
        head->lengh--;
        return OK;
    }
    q->next = p->next;
    free(p);
    head->lengh--;
    return OK;
}

void clearList(struct List* head)
{
    if(head->lengh == 0)
    {
        return;
    }
    struct Node* p = head->head->next;
    struct Node* q;
    while(p != head->head)
    {
        q = p->next;
        free(p);
        p = q;
    }
    head->head->next = NULL;
    head->lengh = 0;
    head->tail = NULL;
    return OK;

}
void printList(struct List* head)
{
    if(head->lengh == 0)
    {
        return ;
    }
    printf("------------------------------------\n");
    struct Node* p = head->head->next;
    while(p != head->head)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
}

int main()
{
    struct List* list = malloc(sizeof(struct List));
    struct Node* head = malloc(sizeof(struct Node));
    initList(list,head);
    // addHeadElement(list,1);
    // addHeadElement(list,2);
    // addHeadElement(list,3);
    // addHeadElement(list,4);    
    addTailElement(list,1);
    addTailElement(list,2);
    addTailElement(list,3);
    addTailElement(list,4);  
    addTailElement(list,5);
    addTailElement(list,6);
    printList(list);  
    // deleteElement(list,1);
    // deleteElement(list,3);
    // deleteElement(list,6);
    clearList(list);
    printList(list);
    
    return 0;
}




