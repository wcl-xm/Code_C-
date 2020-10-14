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
} term, ElemType;//两个类型名：term用于本ADT，ElemType为LinkList的数据对象名

typedef struct LNode/*结点类型*/{
    ElemType data;
    struct LNode *next;
} LNode, *Link;

/*链表类型*/
typedef struct LinkList {
    Link head, tail;/*分别指向线性链表中的头结点和最后一个结点*/
    int len;    /*指示线性链表中数据元素的个数*/
} LinkList;

typedef LinkList polynomial;//用带表头结点的有序链表表示多项式;

void InitList(polynomial &p) {
    p.head = new LNode;
    p.head->next = nullptr;
    p.len = 0;
}

int cmp(term a, term b)//比较多项式的项,a的指数值<b的指数值返回-1,a的指数值〉b的指数值返回1//a的指数值=b的指数值返回0
{
    if (a.expn < b.expn)
        return -1;
    else if (a.expn > b.expn)
        return 1;
    return 0;
}

int LocateElem(polynomial &p, ElemType e, int (*cmp)(term a, term b)) //在创建多项式时检验是否cin相同指数的项，flag=0表示不存在，flag=1为存在
{
    int flag = 0;
    Link q = p.head->next;
    for (int i = 0; i < p.len; ++i) {
        if (q && cmp(q->data, e))
            q = q->next;
        else
            flag = 1;
    }
    return flag;
};

void ListInsert_Link(polynomial &p, ElemType e) //生成新节点并插入链中,只用于创建多项式
{
    Link s = new LNode;
    s->data.coef = e.coef;
    s->data.expn = e.expn;
    Link pre = p.head;
    Link q = p.head->next;
    while (q && cmp(q->data, e) == -1) {
        pre = q;
        q = q->next;
    }
    s->next = q;
    pre->next = s;
    p.len++;
}

void CreatePolyn(polynomial &p, int m)//手动创建新的链
{
    polynomial h;
    ElemType e;
    //输入m项的系数和指数，建立表示一元多项式的有序链表P
    InitList(p);
    h = p;
    e.coef = 0.0;
    e.expn = -1;//SetCurElem(P,e)
    //置头结点的数据元素
    for (int i = 1; i <= m; i++)//依次输入m个非零项
    {
        cout << "请输入系数和指数" << endl;
        cin >> e.coef >> e.expn;
        if (!LocateElem(p, e, cmp))//当前链表中不存在该指数项
            ListInsert_Link(p, e);//在第一个大于插入项指数的数据项前插入/新的数据项
    }
}

polynomial Add1(polynomial pa, polynomial pb) //两项多项式加法，生成新的多项式并带回，原多项式不变更
{
    Link p1 = pa.head->next;
    Link p2 = pb.head->next;
    polynomial p3;
    float sum;
    InitList(p3);
    Link p = p3.head;
    while (p2 && p1) {
        if (p1->data.expn == p2->data.expn) {
            sum = p1->data.coef + p2->data.coef;
            if (sum != 0) {
                Link s = new LNode;//创建新节点
                s->data.coef = sum;
                s->data.expn = p1->data.expn;//为新节点的数据域赋值
                s->next = nullptr;//新节点的指针域指向空
                p->next = s;//头结点的指针域指向新节点s
                p = s;//指针后移到s
                p1 = p1->next;
                p2 = p2->next;
            } else {
                p1 = p1->next;
                p2 = p2->next;
            }
        } else if (p1->data.expn < p2->data.expn) {
            Link s = new LNode;
            s->data.expn = p1->data.expn;
            s->data.coef = p1->data.coef;
            s->next = nullptr;
            p->next = s;
            p = s;
            p1 = p1->next;
        } else {
            Link s = new LNode;
            s->data.expn = p2->data.expn;
            s->data.coef = p2->data.coef;
            s->next = nullptr;
            p->next = s;
            p = s;
            p2 = p2->next;
        }
    }
    p->next = p1 ? p1 : p2;//将剩余部分的多项式整体移到新创建的链表上
    return p3;
}

void Add2(polynomial &pa, polynomial &pb)//两项多项式的加法，用于实现乘法功能中中间多项式相加的功能，不生成新链表，加法过程中删除第二链表，只保留头结点
{
    Link p1 = pa.head->next;
    Link p2 = pb.head->next;
    Link p3 = pa.head;
    Link temp;
    float sum;
    while (p2 && p1) {
        if (p1->data.expn == p2->data.expn) {
            sum = p1->data.coef + p2->data.coef;
            if (sum != 0) {
                p1->data.coef = sum;
                p3->next = p1;
                p3 = p1;
                p1 = p1->next;
                temp = p2;
                p2 = p2->next;
                delete temp;
            } else {
                temp = p1;
                p1 = p1->next;
                delete temp;
                temp = p2;
                p2 = p2->next;
                delete temp;
            }
        } else if (p1->data.expn < p2->data.expn) {
            p3->next = p1;
            p3 = p1;
            p1 = p1->next;
        } else {
            p3->next = p2;
            p3 = p2;
            p2 = p2->next;
        }
    }
    p3->next = p1 ? p1 : p2;
}

polynomial Less(polynomial pa, polynomial pb) //两项多项式相减，仿照加法Add1
{
    Link p1 = pa.head->next;
    Link p2 = pb.head->next;
    polynomial p3;
    float sum;
    InitList(p3);
    Link p = p3.head;
    while (p2 && p1) {
        if (p1->data.expn == p2->data.expn) {
            sum = p1->data.coef - p2->data.coef;
            if (sum != 0) {
                Link s = new LNode;
                s->data.coef = sum;
                s->data.expn = p1->data.expn;
                s->next = nullptr;
                p->next = s;
                p = s;
                p1 = p1->next;
                p2 = p2->next;
            } else {
                p1 = p1->next;
                p2 = p2->next;
            }
        } else if (p1->data.expn < p2->data.expn) {
            Link s = new LNode;
            s->data.expn = p1->data.expn;
            s->data.coef = p1->data.coef;
            s->next = nullptr;
            p->next = s;
            p = s;
            p1 = p1->next;
        } else {
            Link s = new LNode;
            s->data.expn = p2->data.expn;
            s->data.coef = p2->data.coef;
            s->next = nullptr;
            p->next = s;
            p = s;
            p2 = p2->next;
        }
    }
    if (p2 != nullptr)
        while (p2) {
            Link s = new LNode;
            s->data.expn = p2->data.expn;
            s->data.coef = -p2->data.coef;
            s->next = nullptr;
            p->next = s;
            p = s;
            p2 = p2->next;
        }
    else
        p->next = p1;
    return p3;
}

/*
 * 思路 ：多个中间多项式相加
 * 设置p3为固定链表;temp为临时链表。
 * 将第一次中间项多项式的结果赋给p3，其后每次中间多项式都赋给temp并与p3相加，temp每次在Add2中清空，最后返回p3
 */
polynomial Multiplication(polynomial &pa, polynomial &pb)//两项多项式乘法，生成新链表并返回
{
    Link p1 = pa.head->next;
    Link p2 = pb.head->next;
    polynomial p3;
    polynomial temp;
    int count = 0;
    InitList(p3);
    InitList(temp);
    Link p = p3.head;
    while (p1)
    {
        while (p2)
        {
            Link s = new LNode;
            s->data.coef = p1->data.coef * p2->data.coef;
            s->data.expn = p1->data.expn + p2->data.expn;
            s->next = nullptr;
            p->next = s;
            p = s;
            p2 = p2->next;
        }
        p2 = pb.head->next;
        count++;
        p = temp.head;
        if (count > 1)
            Add2(p3, temp);
        p1 = p1->next;
    }
    delete temp.head;
    return p3;
}

/*
 * 这除法是啥玩意啊，，，，，，，
 */
polynomial Division(polynomial &pa, polynomial &pb) {
    polynomial p;
    return p;
}

void Show(polynomial pt) {
    Link p = pt.head->next;
    while (p) {
        cout << p->data.coef << "X^" << p->data.expn << " ";
        if (p->next != nullptr && p->next->data.coef > 0)
            cout << "+ ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    polynomial p1, p2, p3, p4, p5;
    CreatePolyn(p1, 2);
    CreatePolyn(p2, 2);
    p3 = Add1(p1, p2);
    p4 = Less(p1, p2);
    p5 = Multiplication(p1, p2);
    Show(p1);
    Show(p2);
    Show(p3);
    Show(p4);
    Show(p5);
    return 0;
}

