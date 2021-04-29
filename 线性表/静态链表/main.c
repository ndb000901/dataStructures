/************************************
 * 
 * auther:wuhen
 * Time:2021.4.28
 * details:静态链表
 * 
************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10
#define DATA_TYPE int
#define STATUS int
#define ERROR 0
#define OK 1
#define UNAVAILABLE -1
#define NOTFOUND -1

struct Node
{
    DATA_TYPE data;
    int next;
};

struct List
{
    struct Node list[MAXSIZE];
    int lengh;
};

void initList(struct List* nodeList)
{
    int i;
    for(i = 1;i < MAXSIZE - 1;i++)
    {
        nodeList->list[i - 1].next = i;
    }
    nodeList->list[MAXSIZE - 2].next = 0;
    nodeList->list[MAXSIZE - 1].next = 0;
    nodeList->lengh = 0;
}

int mallocNode(struct List* nodeList)
{
    if(nodeList->list[0].next == 0)
    {
        return UNAVAILABLE;
    }
    int index;
    index = nodeList->list[0].next;
    nodeList->list[0].next = nodeList->list[index].next;
    return index;
}

STATUS freeNode(struct List* nodeList,int index)
{
    nodeList->list[index].next = nodeList->list[0].next;
    nodeList->list[0].next = index;
}
STATUS addElement(struct List* nodeList,DATA_TYPE e)
{
    int index = mallocNode(nodeList);
    if(index == -1)
    {
        return ERROR;
    }
    if(nodeList->list[MAXSIZE - 1].next == 0)
    {
        nodeList->list[index].next = 0;
        nodeList->list[index].data = e;
        nodeList->list[MAXSIZE - 1].next = index;
        nodeList->lengh++;
        return OK;
    }
    nodeList->list[index].data = e;
    nodeList->list[index].next = nodeList->list[MAXSIZE - 1].next;
    nodeList->list[MAXSIZE - 1].next = index;
    nodeList->lengh++;
    return OK;
    
}

STATUS alterElementByIndex(struct List* nodeList,int index,DATA_TYPE e)
{
    if(nodeList->lengh == 0 || index < 1 || index > nodeList->lengh)
    {
        return ERROR;
    }
    int i;
    int temp = nodeList->list[MAXSIZE - 1].next;
    for(i = 1;i < index;i++)
    {
        temp = nodeList->list[temp].next;
    }
    nodeList->list[temp].data = e;
    return OK;
}

STATUS alterElementByValue(struct List* nodeList,DATA_TYPE value,DATA_TYPE e)
{
    if(nodeList->lengh == 0)
    {
        return ERROR;
    }
    int i = nodeList->list[MAXSIZE - 1].next;
    while(i)
    {
        if(nodeList->list[i].data == value)
        {
            nodeList->list[i].data = e;
        }
        i = nodeList->list[i].next;
    }
    return OK;
}

int findElement(struct List* nodeList,DATA_TYPE e)
{
    int i = nodeList->list[MAXSIZE - 1].next;
    while(i)
    {
        if(nodeList->list[i].data == e)
        {
            return i;
        }
        i = nodeList->list[i].next;
    }
    return NOTFOUND;
}

STATUS deleteElementByIndex(struct List* nodeList,int index)
{
    if(nodeList->lengh == 0 || index < 1 || index > nodeList->lengh)
    {
        return ERROR;
    }
    int i,j;
    int temp = nodeList->list[MAXSIZE - 1].next;
    if(index == 1)
    {
        i = nodeList->list[MAXSIZE - 1].next;
        nodeList->list[MAXSIZE - 1].next = nodeList->list[i].next;
        freeNode(nodeList,i);
        nodeList->lengh--;
        return OK;
    }
    for(i = 1;i < index - 1;i++)
    {
        temp = nodeList->list[temp].next;
    }
    if(index == nodeList->lengh)
    {
        freeNode(nodeList,nodeList->list[temp].next);
        nodeList->list[temp].next = 0;
        nodeList->lengh--;
        return OK;
    }
    j = nodeList->list[temp].next;
    nodeList->list[temp].next = nodeList->list[j].next;
    freeNode(nodeList,j);
    nodeList->lengh--;
    return OK;
}

void printList(struct List* nodeList)
{
    int i = nodeList->list[MAXSIZE - 1].next;
    printf("--------------------------------------------\n");
    while(i)
    {
        printf("%d\n",nodeList->list[i].data);
        i = nodeList->list[i].next;
    }
}

int main()
{
    struct List* nodeList = malloc(sizeof(struct List));
    initList(nodeList);
    addElement(nodeList,22);
    addElement(nodeList,33);
    addElement(nodeList,44);
    addElement(nodeList,55);
    addElement(nodeList,66);
    addElement(nodeList,77);

    // for(int i = 0;i < MAXSIZE;i++)
    // {
    //     printf("%d\n",list[i].next);
    // }
    // printList(nodeList);
    // alterElementByIndex(nodeList,1,100);
    // alterElementByIndex(nodeList,3,300);
    // alterElementByIndex(nodeList,6,600);
    printList(nodeList);
    // deleteElementByIndex(nodeList,3);
    deleteElementByIndex(nodeList,6);
    printList(nodeList);
    return 0;
}

