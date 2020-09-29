//
// Created by 夏木 on 2020/9/28.
//
#include <iostream>
#include <cstdio>
using namespace std;

typedef struct {
    //项的表示，多项式的项作为LinkList的数据元素
    float coef;//系数
    int expn;//指数
}term,ElemType;//两个类型名：term用于本ADT，ElemType为LinkList的数据对象名

typedef struct LNode/*结点类型*/{
    ElemType data;
    struct LNode *next;
}LNode,*Link,*Position;

/*链表类型*/
typedef struct LinkList{
    Link head,tail;/*分别指向线性链表中的头结点和最后一个结点*/
    int len;    /*指示线性链表中数据元素的个数*/
}LinkList;

typedef LinkList polynomial;//用带表头结点的有序链表表示多项式;

void InitList(polynomial &p)
{
    p.head= nullptr;
    p.len = 0;
}

int cmp(term a, term b)//比较多项式的项,a的指数值<b的指数值返回-1,a的指数值〉b的指数值返回0//a的指数值=b的指数值返回1
{/*算法略*/
    return 0;
}

int LocateElem(polynomial &p,ElemType e,int (*cmp)(term a,term b)){
    return 0;
};

void CreatePolyn(polynomial &p,int m)
{
    polynomial h;ElemType e;
    //输入m项的系数和指数，建立表示一元多项式的有序链表P
    InitList(p);h=p;e.coef=0.0;e.expn=-1;//SetCurElem(P,e)
    //置头结点的数据元素
    for(int i=1;i<=m;i++)//依次输入m个非零项
    {
        cin>>e.coef>>e.expn;
        if(!LocateElem(p,e,(*cmp)())
            //当前链表中不存在该指数项
            ListInsert_Link(p,ie);//在第一个大于插入项指数的数据项前插入/新的数据项
    }
}

int main(){

    return 0;
}

