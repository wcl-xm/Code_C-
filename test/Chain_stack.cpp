//
// Created by 夏木 on 20/10/26.
//

#include <iostream>
#define OK 1
#define ERROR -1
#define maxsize 100

struct SElemType
{
    int a;
    float b;
    char c;
} ;

typedef struct Stack
{
    SElemType *top;
    SElemType *base;
    int stacksize;
}SQStack;

void Init(SQStack &l)
{
    l.base = new SElemType[maxsize];
    if (!l.base) exit(ERROR);
    l.top = l.base;
    l.stacksize =maxsize;
}

int push(SQStack &l, SElemType e)
{
    if(l.top-l.base==maxsize)return ERROR;
    *l.top++ = e;
    return OK;
}

int pop(SQStack &l, SElemType &e)
{
    if (l.top==l.base)return ERROR;
    e = *l.top--;
    return OK;
}

int Delete(SQStack &l)
{
    delete l.base;
    return OK;
}
