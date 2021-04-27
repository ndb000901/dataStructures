/************************************
 * 
 * auther:wuhen
 * Time:2021.4.26
 * details:线性表
 * 
************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100    // 线性表最大限度
#define DATA_TYPE int   // 数据类型
#define OK 1            // 正确
#define ERROR 0         // 错误
#define STATUS int      // 状态码类型

struct List
{
    DATA_TYPE data[MAX_SIZE];
    int lengh;
};

// 初始化线性表
void initList(struct List * list)
{
    list->lengh = 0;
}

// 获取任意位置数据
STATUS getElement(struct List list,int index,DATA_TYPE *e)
{
    if(list.lengh == 0 || index < 0 || index > list.lengh - 1)
    {
        return ERROR;
    }
    printf("%d\n",list.data[index]);
    *e = list.data[index];
    return OK;

}

// 插入数据
STATUS insertElement(struct List* list,int index,DATA_TYPE data)
{
    if(list->lengh > MAX_SIZE - 1 || index < 0 || index > list->lengh)
    {
        return ERROR;
    }
    int i = list->lengh - index;
    while(i)
    {
        list->data[index + i] = list->data[index + i -1];
        i--;
    }
    list->data[index] = data;
    list->lengh++;
    return OK;
}

//增加数据，默认插在尾部
STATUS addElement(struct List* list,DATA_TYPE data)
{
    return insertElement(list,list->lengh,data);
}

// 修改数据
STATUS alterElement(struct List* list,int index,DATA_TYPE data)
{
    if(list->lengh ==  0 || index < 0 || index > list->data - 1)
    {
        return ERROR;
    }
    list->data[index] = data;
    return OK;
}

// 删除数据
STATUS deleteElement(struct List* list,int index)
{
    if(list->lengh == 0 || index < 0 || index > list->lengh - 1)
    {
        return ERROR;
    }
    int i = index;
    for(;i < list->lengh - 1;i++)
    {
        list->data[i] = list->data[i + 1];
    }
    list->lengh--;
    return OK;
}

// 查找数据，默认返回第一个匹配的索引
int findElement(struct List list,DATA_TYPE data)
{
    if(list.lengh == 0)
    {
        return -1;
    }
    int i = 0;
    for(;i < list.lengh;i++)
    {
        if(list.data[i] == data)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    struct List* list;
    initList(list);
    insertElement(list,0,20);
    insertElement(list,1,30);
    insertElement(list,2,100);
    insertElement(list,2,101);
    insertElement(list,3,200);
    addElement(list,255);
    alterElement(list,2,1020);
    alterElement(list,0,1021);
    alterElement(list,5,1111);

    printf("a1:%d\n",findElement(*list,2021));
    printf("a1:%d\n",findElement(*list,1021));

    deleteElement(list,0);
    deleteElement(list,3);
    deleteElement(list,list->lengh - 1);
    DATA_TYPE* data = malloc(sizeof(DATA_TYPE));
    // DATA_TYPE* data;
    int status = getElement(*list,10,data);
    printf("data:%d\n",*data);
    printf("hello,world!\n");
}