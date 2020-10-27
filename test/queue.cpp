//
// Created by 夏木 on 20/10/27.
//
#include<iostream>
#define OK 1
#define ERROR -1

struct ElemType{
    int a;
    float b;
    char c;
};

typedef struct QNode{
    ElemType elem;
    QNode *next;
}QNode,*QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

int Init(LinkQueue &Q)
{
    Q.front = Q.rear = new QNode;
    Q.front = nullptr;
    return OK;
}

int EnQueue(LinkQueue &Q, ElemType e)
{
    QueuePtr s = new QNode;
    s->elem = e;
    s->next = nullptr;
    Q.rear->next = s;
    Q.rear = s;
    return OK;
}

int DeQueue(LinkQueue &Q,ElemType e)
{
    if (Q.rear==Q.front)return ERROR;
    QueuePtr p = Q.front->next;
    e = p->elem;
    Q.front = p->next;
    if (p == Q.rear)Q.rear = Q.front;   //判断是否删除到最后一个元素
    delete p;
    return OK;
}

