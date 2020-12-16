//
// Created by 夏木 on 20/11/30.
//
#include <iostream>
#include <cstring>

using namespace std;

void Test(char *str)
{
    for (int i = 0; i < 3; ++i) {
        str[i] = i;
    }
}


int main()
{
//    char value=0,value1 =0;
//    char a[8]={'0','0','0','0','0','1','0','1'};
//    for (int i = 0; i < 8; ++i) {
//        value <<= 1;
//        if (a[i]=='1')
//            value |=1;
//    }

//    for (int j = 0; j < 8; ++j) {
//        value1 |=1;
//    }
//    cout<<value;

//    FILE *p;
//    int ch;
//    p = fopen("E:\\Pictures\\muskratracer_6k1xv6.png","rb");
//    while ((ch =fgetc(p))!=EOF)
//        cout<<ch<<" ";
//    return 0;

    char value =0;
    for (int i = 0; i < 8; ++i) {
        value<<=1;
        value |=1;
    }
    char a[2]={'1','2'};
    char b[2];
//    strcpy(b,a);
    for (int j = 0; j < 2; ++j) {
        cout<<int(a[j])<<" ";
//        cout<<endl;
//        cout<<int(b[j])<<" ";

    }
//    cout<<int(value);
cout<< -126%2;
}