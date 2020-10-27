/*
 *坑爹程序一堆错，抄书不如自己做
 */
#include <iostream>
#include <cstdlib>
using namespace std;
#define OK 1
#define ERROR -1
typedef int Status1;
typedef char Status2;
typedef double Status3;

//操作数栈
typedef struct StackNodeOPND {
    double value;
    StackNodeOPND *next;
} *OPND;

// 操作符栈
typedef struct StackNodeOPTR {
    char op;
    StackNodeOPTR *next;
} *OPTR;

Status1 Init_OPND(OPND &opnd) {
    while (opnd != nullptr)//删除旧节点
    {
        OPND temp = opnd;
        opnd = temp->next;
        delete temp;
    }
    opnd == nullptr;
    return OK;
}

Status1 Init_OPTR(OPTR &optr) {
    while (optr != nullptr)//删除旧节点
    {
        OPTR temp = optr;
        optr = temp->next;
        delete temp;
    }
    optr == nullptr;
    return OK;
}

Status1 Push_OPND(OPND &opnd, double value) {
    OPND temp = new StackNodeOPND;
    temp->value = value;
    temp->next = opnd;
    opnd = temp;
    return OK;
}

Status1 Push_OPTR(OPTR &optr, char op) {
    OPTR temp = new StackNodeOPTR;
    temp->op = op;
    temp->next = optr;
    optr = temp;
    return OK;
}

Status1 IsEmpty_OPND(OPND &opnd) {
    if (opnd == nullptr)
        return ERROR;
    return OK;
}

Status1 IsEmpty_OPTR(OPTR &optr) {
    if (optr == nullptr)
        return ERROR;
    return OK;
}

Status1 Pop_OPND(OPND &opnd, double &value) {
    if (IsEmpty_OPND(opnd) == OK) {
        value = opnd->value;
        OPND temp = opnd;
        opnd = temp->next;
        delete temp;
    }
    return OK;
}

Status1 Pop_OPTR(OPTR &optr, char &op) {
    if (IsEmpty_OPTR(optr) == OK) {
        op = optr->op;
        OPTR temp = optr;
        optr = temp->next;
        delete temp;
    }
    return OK;
}


Status1 GetTop_OPTR(OPTR &optr, char &op) {
    if (IsEmpty_OPTR(optr) == OK)
        op = optr->op;
    return OK;
}

Status2 Precede(char a, char b) {
    char aPriorTable[6][6] = {// +-*/()
            {'>', '>', '<', '<', '<', '>'},
            {'>', '>', '<', '<', '<', '>'},
            {'>', '>', '>', '>', '<', '>'},
            {'>', '>', '>', '>', '<', '>'},
            {'<', '<', '<', '<', '<', '='},
            {'>', '>', '>', '>', '>', '>'}};
    int x = -1;
    int y = -1;
    char opr[] = "+-*/()";
    for (int i = 0; i < 6; ++i) {
        if (a == opr[i])x = i;
        if (b == opr[i])y = i;
    }
    return aPriorTable[x][y];
}

Status3 calc(double a, char theta, double b) {
    double value = 0;
    switch (theta) {
        case '+' :
            value = a + b;
            break;
        case '-' :
            value = a - b;
            break;
        case '*' :
            value = a * b;
            break;
        case '/' :
            value = a / b;
            break;
        default:
            cout << "表达式错误" << endl;
            exit(0);
    }
    return value;
}

Status1 Parse(char expr[]) {
    OPND opnd = nullptr;
    OPTR optr = nullptr;
    Init_OPND(opnd);
    Init_OPTR(optr);
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c >= '0' && c <= '9' || c == '.') {
            char token[20] = {0};
            int j = 0;
            while (expr[i + j] >= '0' && expr[i + j] <= '9' || expr[i + j] == '.') {
                token[j] = expr[i + j];
                j++;
            }
            token[j] = '\0';
            i = i + j - 1;
            double value = atof(token);
            Push_OPND(opnd, value);
        } else {
            char op = 0;
            char pre = 0;
            GetTop_OPTR(optr, op);
            if (IsEmpty_OPTR(optr) == ERROR)pre = '<';
            else pre = Precede(op, c);
            switch (pre) {
                case '<' :
                    Push_OPTR(optr, c);
                    break;
                case '=' :
                    Pop_OPTR(optr, op);
                    break;
                case '>' :
                    double a = 0;
                    double b = 0;
                    Pop_OPND(opnd, b);
                    Pop_OPND(opnd, a);
                    Pop_OPTR(optr, op);
                    Push_OPND(opnd, calc(a, op, b));
                    i--;
                    break;
            }

        }
    }
    while (IsEmpty_OPTR(optr) == OK) {
        double a = 0;
        double b = 0;
        char op = 0;
        Pop_OPND(opnd, b);
        Pop_OPND(opnd, a);
        Pop_OPTR(optr, op);
        Push_OPND(opnd, calc(a, op, b));
    }
    double value = 0;
    Pop_OPND(opnd, value);
    return value;
}

int main() {
    char expr[256] = {0};
    cout << "表达式：";
    cin >> expr;
    cout << "结果：" << Parse(expr) << endl;
    return OK;

}
