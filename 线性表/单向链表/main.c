/************************************
 * 
 * auther:wuhen
 * Time:2021.4.27
 * details:单向链表
 * 
************************************/

#include<stdlib.h>
#include<stdio.h>

#define STATUS int
#define OK 1
#define ERROR 0
#define DATA_TYPE int

// 定义节点
struct Node
{
    DATA_TYPE data;
    struct Node* next;
};

// 定义头节点
struct ListHead
{
    int lengh;
    struct Node* next;  // 指向第一个节点
    struct Node* tail;  // 指向最后一个节点
};

// 初始化表头
void initList(struct ListHead* head)
{
    head->lengh = 0;
    head->next = NULL;
    head->tail = NULL;
}

// 头插法增加节点
STATUS addHeadElement(struct ListHead* head,DATA_TYPE e)
{
    struct Node* node = malloc(sizeof(struct Node));
    node->data = e;
    if(head->lengh == 0)
    {
        node->next = NULL;
        head->next = node;
        head->tail = node;
        head->lengh++;
        return OK;
    }
    node->next = head->next;
    head->next = node;
    head->lengh++;
    return OK;
}

// 尾插法增加数据
STATUS addTailElement(struct ListHead* head,DATA_TYPE e)
{
    struct Node* node = malloc(sizeof(struct Node));
    node->data = e;
    node->next = NULL;
    if(head->lengh == 0)
    {
        head->next = node;
        head->tail = node;
        head->lengh++;
        return OK;
    }
    head->tail->next = node;
    head->tail = node;
    head->lengh++;
    return OK;
}

// 在指定节点后插入元素
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
    p->next = node;
    head->lengh++;
    return OK;

}

// 遍历链表
void printList(struct ListHead* head)
{
    int i;
    struct Node* p = head->next;
    while(p)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
}

// 根据索引修改节点
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

// 将所有数据为value的元素修改为e
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

// 根据索引删除元素
STATUS deleteElementByIndex(struct ListHead* head,int index)
{
    if(index < 1 || index > head->lengh)
    {
        return ERROR;
    }
    struct Node* p = head->next;
    struct Node* q;
    if(index == 1)
    {
        q = head->next;
        head->next = q->next;
        free(q);
        head->lengh--;
        return OK;
    }

    int i = 1;
    while(i < index)
    {
        q = p;
        p = p->next;
        i++;
    }
    if(i == head->lengh)
    {
        q->next = NULL;
        free(p);
        head->lengh--;
        return OK;
    }
    q->next = p->next;
    free(p);
    head->lengh--;
    return OK;
}

// 清空链表
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
    for(i = 0;i < 10;i++)
    {
        addHeadElement(head,i);
    }
    insertElement(head,1,100);
    insertElement(head,2,200);
    insertElement(head,10,300);
    alterElementByIndex(head,1,1000);
    alterElementByIndex(head,8,8000);
    alterElementByIndex(head,13,8000);
    alterElementByValue(head,8000,9000);
    printList(head);
    printf("-------------------------------------------------");
    deleteElementByIndex(head,1);
        printList(head);
            printf("-------------------------------------------------");
    deleteElementByIndex(head,2);
        printList(head);
            printf("-------------------------------------------------");
    printList(head);
    printf("hello,world!");
    return 0;
}



