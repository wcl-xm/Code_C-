#include <iostream>
#include <cstdlib>
using namespace std;
typedef int Status;
#define OK 1
#define ERROR -1
typedef int Status ;
//操作数栈
typedef struct StackNodeOPND{
    double value;
    StackNodeOPND *next;
} *OPND;
// 操作符栈
typedef struct StackNodeOPTR{
    char op;
    StackNodeOPTR *next;
} *OPTR;
/*
 * 操作数栈的操作
 */
Status Init(OPND &opnd)
{
    while (opnd!= nullptr)//删除旧节点
    {
        OPND temp = opnd;
        opnd = temp->next;
        delete temp;
    }
    opnd == nullptr;
    return OK;
}

Status Push(OPND & opnd , double value)
{
    OPND temp = new StackNodeOPND;
    temp->value = value;
    temp->next = opnd;
    opnd = temp;
    return OK;
}

Status Pop(OPND &opnd ,double &value,Status (*IsEmpty)(OPND))
{
    IsEmpty(opnd);
    value = opnd->value;
    OPND temp = opnd;
    opnd = temp->next;
    delete temp;
    return OK;
}

Status GetTop(OPND &opnd ,double value, Status (*IsEmpty)(OPND))
{
    IsEmpty(opnd);
    value = opnd->value;
    return OK;
}

Status IsEmpty(OPND &opnd)
{
    if (opnd == nullptr)
        return ERROR;
    return OK;
}

Status Parse(char expr[])
{
    OPND opnd = nullptr;
    OPTR optr = nullptr;
    Init(opnd);
    //Init(optr);
    for(int i=0;expr[i]!='\0';i++){
        char c = expr[i];
        if (c>='0'&& c<='9'||c=='.')
        {
            char token[20]={0};
            int j = 0;
            while (expr[i+j]>='0'&&expr[i+j]<='9'||expr[i+j] == '.')
            {
                token[j] = expr[i+j];
                j++;
            }
            token[j] = '\0';
            i = i+j-1;
            double value = atof(token);
            Push(opnd,value);
        }
    }
    return OK;
}

int main() {
    std::cout << "Hello," << std::endl;
    return 0;
}
