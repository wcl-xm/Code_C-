//
// Created by 夏木 on 20/11/03.
//
#include <iostream>
#define OK 1
#define Maxsieze 100
using namespace std;

typedef struct Sqlist
{
    int *elem;
    int length;
}sqlist;

int Init(sqlist &l)
{
    if (!l.elem)return 0;
    l.elem =new int [Maxsieze];
    l.length=0;
    return OK;
}

int Insert(sqlist &l,int i,int e)
{
    if(i<0||i>l.length+1)return 0;
    if (l.length==Maxsieze)return 0;
    for (int j = l.length-1; j >i-1 ; --j) {
        l.elem[j+1]=l.elem[j];
    }
    l.elem[i-1] = e;
    l.length++;
    return OK;
}

int Delete(sqlist &l, int i,int e)
{
    if(i<1||i>l.length||l.length==0)return 0;
    for (int j = i-1; j <l.length ; ++j) {
        l.elem[j]=l.elem[j+1];
    }
    l.length--;
    return OK;
}

int main()
{
    return 0;
}