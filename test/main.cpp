#include <iostream>
using namespace std ;

typedef int Element ;
typedef int Status;
#define OK 0
#define FALSE 0
#define ERROR -1
#define OVERFLOW -2
#define maxsize 10

typedef struct {
    Element * elem;
    int length;
}sqlist;

Status Init(sqlist &l)
{
    l.elem = new Element (maxsize);
    if(!l.elem)return ERROR;
    l.length = 0;
    return OK;
}

Status Writeelem(sqlist &l ,int i){
    if (i<1||i>maxsize)return OVERFLOW;
    for (int j = 1; j < maxsize+2; ++j) {
        l.elem[j] = j;
        l.length++;
    }
    return OK;
}

Status Getelem(sqlist l,int i,Element &e)
{
    if (i<1||i>l.length) return ERROR;
    e = l.elem[i];
    for (int j = 0; j < l.length; ++j) {
        if(l.elem[j]==e)
            return j;
    }
    return OK;
}

Status Insertelem(sqlist &l,int i,Element &e)
{
    return OK;
}

int main(){
    int e;
    auto *l= new sqlist ();
    Init(*l);
    Writeelem(*l,10);
    cout<<l->length;
    cout<<Getelem(*l,9,e);
    return 0;
}
