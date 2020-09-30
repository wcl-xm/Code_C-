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
}LNode,*Link;

/*链表类型*/
typedef struct LinkList{
    Link head,tail;/*分别指向线性链表中的头结点和最后一个结点*/
    int len;    /*指示线性链表中数据元素的个数*/
}LinkList;

typedef LinkList polynomial;//用带表头结点的有序链表表示多项式;

void InitList(polynomial &p)
{
    p.head = new LNode;
    p.head->next= nullptr;
    p.len = 0;
}

int cmp(term a, term b)//比较多项式的项,a的指数值<b的指数值返回-1,a的指数值〉b的指数值返回1//a的指数值=b的指数值返回0
{
    if (a.expn<b.expn)
        return -1;
    else if (a.expn>b.expn)
        return 1;
        return 0;
}

int LocateElem(polynomial &p,ElemType e,int (*cmp)(term a,term b))
{
    int flag = 0;
    Link q = p.head->next;
    for (int i = 0; i < p.len; ++i) {
        if (q&&cmp(q->data,e))
            q = q->next;
        else
            flag=1;
    }
    return flag;
};

void ListInsert_Link(polynomial &p,ElemType e)
{
    Link s = new LNode;
    s->data.coef=e.coef;s->data.expn=e.expn;
    Link pre = p.head;
    Link q = p.head->next;
    while (q&&cmp(q->data,e)==-1)
    {
        pre = q;
        q = q->next;
    }
    s->next = q;
    pre->next=s;
    p.len++;
}

void CreatePolyn(polynomial &p,int m)
{
    polynomial h;ElemType e;
    //输入m项的系数和指数，建立表示一元多项式的有序链表P
    InitList(p);
    h=p;e.coef=0.0;e.expn=-1;//SetCurElem(P,e)
    //置头结点的数据元素
    for(int i=1;i<=m;i++)//依次输入m个非零项
    {
        cout<<"请输入系数和指数"<<endl;
        cin>>e.coef>>e.expn;
        if(!LocateElem(p,e,cmp))//当前链表中不存在该指数项
            ListInsert_Link(p,e);//在第一个大于插入项指数的数据项前插入/新的数据项
    }
    h.head=h.head->next;
    float mid=h.head->data.coef ;
    for (int j = 0; j <p.len ; ++j) {
        mid = h.head->data.coef;
        if (j<p.len-1&&mid>0)
            cout<<"+ ";
        cout<<h.head->data.coef<<"X^"<<h.head->data.expn<<" ";
        h.head=h.head->next;
    }
}
void DeleteLNode(Link p){
    delete p;
}
void Add_Less(polynomial p1,polynomial p2){
    polynomial p = p1;
}
int main(){
    polynomial p;
    CreatePolyn(p,3);
    return 0;
}

