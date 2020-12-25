//
// Created by XM on 20/12/23.
//
#include<iostream>


using namespace std;
typedef struct BiNode{
    char  data;
    BiNode *lchild,*rchild;
}*BiTree;

void CreatBiTree(BiTree &T)
{
    char  ch;
    cin>>ch;
    if(ch=='#')T= nullptr;
    else
    {
        T = new BiNode;
        T->data = ch;
        CreatBiTree(T->lchild);
        CreatBiTree(T->rchild);
    }
}

int Depth(BiTree T)
{
    int m,n;
    if (T== nullptr)return 0;
    else
    {
        n = Depth(T->lchild);
        m = Depth(T->rchild);
        return n>m?n+1:m+1;
    }
}

int main(){
    BiTree T;
    CreatBiTree(T);
    int num = Depth(T);
    cout<<num;
}
