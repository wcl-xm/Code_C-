/*这是线性表例题
 * 数据结构包括数据类型及相关的操作
 */
#include <iostream>

using namespace std;

typedef int Element;
typedef int Status;
#define OK 0
#define ERROR -1
#define OVERFLOW -2
#define maxsize 10

typedef struct {
    Element *elem;
    int length;
} sqlist;

Status Init(sqlist &l) {
    l.elem = new Element(maxsize);
    if (!l.elem)return ERROR;
    l.length = 0;
    return OK;
}

Status Writeelem(sqlist &l, int i) {
    if (i < 1 || i > maxsize)return OVERFLOW;
    for (int j = 1; j < maxsize + 1; ++j) {
        l.elem[j] = j;
        l.length++;
    }
    return OK;
}

Status Getelem(sqlist l, int i, Element &e) {
    if (i < 1 || i > l.length) return ERROR;
    e = l.elem[i];
    return OK;
}

Status Insertelem(sqlist &l, int i, Element &e) {
    if (i > l.length || !l.elem || l.length == 10)
        return ERROR;
    for (int j = l.length; j >= i; j--) {
        l.elem[j + 1] = l.elem[j];
    }
    return OK;
}

Status Deletelist(sqlist &l, int i, Element &e) {
    if (!l.elem || i > l.length || i < 1)return ERROR;
    e = l.elem[i];
    for (int j = i; j < l.length; ++j) {
        l.elem[j] = l.elem[j + 1];
    }
    return OK;
}

//TODO 这里是主函数

int main() {
    int e;
    sqlist l;
    Init(l);
    Writeelem(l, 10);
    cout << l.length << endl;
    Getelem(l, 9, e);
    cout << e;
    return 0;
}
