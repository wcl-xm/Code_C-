/*
 * @Autor: KD小乐
 * @Date: 2020-10-01 21:28:17
 * @LastEditTime: 2020-10-14 20:54:55
 * @FilePath: \MyProject\Shiyanzuoye.cpp
 */
#include<iostream>
using namespace std;
typedef struct PNode
{
    float coef;                 //系数
    int expn;                   //指数
    PNode *next;         //指向下一个节点的指针
}PNode,*Polynomial;

void CreatePolyn(Polynomial &P,int n)            //创建空链表，并赋值
{
    Polynomial s;
    Polynomial pre;
    Polynomial q;
    P=new PNode;                //创建头指针
    P->next=NULL;               //头指针的下一个节点为空，链表是空链表
    for(int i=1;i<=n;i++)
    {
        s=new PNode;            //生成新的节点
        cin>>s->coef>>s->expn;  //循环赋值
        pre=P;
        q=P->next;
        while(q&&q->expn<s->expn)
        {
            pre=q;
            q=q->next;
        }
        s->next=q;
        pre->next=s;
    }
}
void Display(Polynomial &P)                 //打印多项式链表
{
    Polynomial q = P->next;
    printf("打印多项式的线性表：[");
    while(q)
    {
        printf("(%.2f,%d)  ",q->coef, q->expn);
        q = q->next;
    }
    printf("]\n\n");
}
// void Add(Polynomial &Pa,Polynomial &Pb)        //多项式相加
// {
//     Polynomial p1,p2,p3,r;
//     p1=Pa->next;
//     p2=Pb->next;
//     //p3=Pa;
//     while(p1&&p2)
//     {
//         p3=new PNode;
//         if(p1->expn==p2->expn)
//         {
//             int sum=p1->coef+p2->coef;
//             if(sum!=0)
//             {
//                 p1->coef=sum;
//                 p3->next=p1;
//                 p3=p1;
//                 p1=p1->next;
//                 r=p2;
//                 p2=p2->next;
//                 delete r;
//             }
//             else
//             {
//                 r=p1;
//                 p1=p1->next;
//                 delete r;
//                 r=p2;
//                 p2=p2->next;
//                 delete r;
//             }
//         }
//         else if(p1->expn<p2->expn)
//         {
//             p3->next=p1;
//             p3=p1;
//             p1=p1->next;
//         }
//         else
//         {
//             p3->next=p2;
//             p3=p2;
//             p2=p2->next;
//         }
//     }
//     p3->next=p1?p1:p2;
//     delete Pb;
// }
// void Sub(Polynomial &Pa,Polynomial &Pb)      //多项式相减
// {
//     Polynomial p1,p2,p3,r;
//     p1=Pa->next;
//     p2=Pb->next;
//     p3=Pa;
// 	while(p1&&p2)
// 	{
//         if(p1->expn==p2->expn)
// 		{
// 			float x;
// 			x=p1->coef-p2->coef;
// 			if(x!=0)
// 			{
// 				p1->coef=x;
// 				p3->next=p1;
//                 p3=p1;
//                 p1=p1->next;
//                 r=p2;
//                 p2=p2->next;
//                 delete r;
//                 printf("success\n");
// 			}
// 			else
// 			{
//                 r=p1;
//                 p1=p1->next;
//                 delete r;
//                 r=p2;
//                 p2=p2->next;
//                 delete r;
//                 printf("success1\n");
// 			}
// 		}
// 		else if(p1->expn<p2->expn)
// 		{
//             p3->next=p1;
//             p3=p1;
//             p1=p1->next;
//             printf("success2\n");
// 		}
//         else
//         {
//             p3->next=p2;
//             p3=p2;
//             p2=p2->next;
//             printf("success3\n");
//             break;
//         }
// 	}
//     p3->next=p1?p1:p2;
//     delete Pb;
// }
void Multiplication(Polynomial &Pa,Polynomial &Pb)     //多项式相乘
{

    Polynomial p1,p2,p3;
    p1=Pa->next;
    p2=Pb->next;
    Polynomial L=p1;
    //pn=p3->next;
    while(p2)
    {
        while(p1)
        {
            int xishu1=p1->coef*p2->coef;             //各项系数之积。
            int sumxiangshu1=p1->expn+p2->expn;       //各项指数之和。
            Polynomial pn=new PNode;                  //将初始化后的Pn变量实例化生成pn节点，每次循环都生成新的pn节点。
            pn->coef=xishu1;                          //项数之积
            pn->expn=sumxiangshu1;                    //系数之和
            pn->next=NULL;                            //next置为空
            p3->next=pn;                              //将pn节点链接到新链上
            p3=pn;                                    //p3链往下遍历一个
            p1=p1->next;
            //delete pn;
            //printf("[(%1.2f,%d)]\n",pn->coef,pn->expn);
        }
        p1=L;                                         //p1链上的指针重新赋在p1链头。
        p2=p2->next;
    }
}
int main()
{
    Polynomial Pa,Pb;
    CreatePolyn(Pa, 2);
    printf("打印Pa多项式:\n");
    Display(Pa);
    CreatePolyn(Pb, 2);               //初始化并创建多项式链表Pb
    printf("打印Pb多项式:\n");
    Display(Pb);
    // CreatePolyn(Pc, 2);               //初始化并创建多项式链表Pa
    // printf("打印Pc多项式:\n");
    // Display(Pc);
    cout<<"执行相乘法操作后的和多项式为:"<<endl;
    Multiplication(Pa,Pb);
    //Display(Pa);
    //cout<<"执行相乘法操作后的和多项式为:"<<endl;
    // Add(Pa,Pb);
    // cout<<"执行相加操作后的和多项式为:"<<endl;
    // Display(Pa);
    //Sub(Pa,Pc);
    //cout<<"执行相减操作后的和多项式为:"<<endl;
    //Display(Pa);
    return 0;
}




