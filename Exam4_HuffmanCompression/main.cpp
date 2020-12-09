#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXVALUE 0x7FFFFFFF
#define N 256 //原文件编码个数
char filename[100];

typedef struct Head{
    char type[4];
    int weight[N+1];
    int length;
}HeadFile;

typedef struct HTNode{
    int weight;
    int lchild,rchild,parents;
}*HuffmanTree;

typedef char * * HuffmanCode;

void InitHead(HeadFile &Hd,int n) {
    strcat(Hd.type,".hfm");
    Hd.length=0;
    for (int i = 0; i <n; ++i)
        Hd.weight[i]=0;
    cout << "请输入文件所在的绝对路径：" << endl;
    cin>>filename;
    int ch=0;
    FILE *file = fopen(filename, "rb");
    if (!file) {
        cout << "Could not find the file\n";
        exit(0);
    }
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch==0)//0单元未用
            ch=256;
        Hd.length++;
        Hd.weight[ch]++;
    }
    fclose(file);
}

void Select(HuffmanTree &HT,int n,int &s1,int &s2)
{
    int min1=MAXVALUE,min2=MAXVALUE;
    for (int i = 1; i <n+1; ++i) {
        if ((HT[i].parents==0)&&(HT[i].weight<min1))
        {
            min2 =min1;
            min1 = HT[i].weight;
            s2=s1;
            s1=i;
        }
        else if ((HT[i].parents==0)&&(HT[i].weight<=min2))
        {
            min2=HT[i].weight;
            s2=i;
        }
    }
}

void CreatHuffmanTree(HuffmanTree &HT,int n,HeadFile Hd)
{
    int m,s1,s2;
    //创建哈夫曼树
    m = 2*n-1; //结点数为2n-1
    HT = new HTNode[m+1];
    for (int i = 1; i < m+1; ++i)
        HT[i].lchild=HT[i].rchild=HT[i].parents=0;
    for (int j = 1; j <= n; ++j)
        HT[j].weight=Hd.weight[j];
    for (int k = n+1; k < m+1; ++k) {
        Select(HT,k-1,s1,s2);
        HT[s1].parents=k;HT[s2].parents=k;
        HT[k].lchild=s1;HT[k].rchild=s2;
        HT[k].weight=HT[s1].weight+HT[s2].weight;
    }
}

void CreateHCode(HuffmanTree HT,HuffmanCode &HC,int n)
{
    char cd[n];//每个节点对应的'0'或'1'
    cd[n-1] ='\0';
    HC = new char*[n];//创建哈夫曼编码表的行
    for (int i = 1 ; i < n+1; ++i) {
        int start =n-1,c,f;
        for(c=i,f=HT[i].parents;f!=0;c=f,f=HT[f].parents)
        {
            if (HT[f].lchild==c)
                cd[--start]='0';
            else
                cd[--start]='1';
        }
        HC[i] = new char[n-start];//创建哈夫曼编码表的列
        strcpy(HC[i] , &cd[start]);
       }
}

void Compress(HuffmanCode HC,HeadFile Hd)
{
    FILE *file,*fin ;
    int pos = 0,ch;
    char value =0;
    char compress_filename[100];
    strcpy(compress_filename,filename);
    strcat(compress_filename,".hfm");
    file = fopen(filename, "rb");
    fin = fopen(compress_filename,"wb");
    fwrite(&Hd,sizeof(HeadFile),1,fin);
    while ((ch=fgetc(file))!=EOF)
    {
        if (ch==0)//0单元未用
            ch=256;
        //将字符转为二进制位，满8位就写入
        for (int i=0; i<strlen(HC[ch]); ++i)
        {
            value <<= 1;
            if (HC[ch][i] == '1')
            {
                value |= 1;
            }
            pos++;	//标示8位二进制位
            if(pos == 8)
            {
                fputc(value,fin);
                value =0;
                pos = 0;
            }//满8位就将value写进压缩文件
        }
    }
    if (pos)	//pos==0，说明刚好存完8位；pos!=0，说明还有多余的位
    {
        value <<= (8-pos);
        fputc(value,fin);
    }
    fclose(fin);
    fclose(file);
}


char* ByteToStr(int ch)
{
    char *str = new char[8];
    int divisor=ch,j;
    char temp[8];
    for (j=7; j>=0; j--)
    {
        divisor = divisor / 2;
        if (divisor%2>0)
            temp[j]='1';
        else
            temp[j]='0';
    }
    if (str[0]=='\0')
        strcpy(str,temp);
    else
        strcat(str,temp);
    return str;
}

//int FindHCode(HuffmanCode &HC ,int &n)
//{
//    char *temp;
//    for (int i = 0; i < n; ++i) {
//        temp = new char[1];
//        strncpy(temp,str,i+1);
//        for (int j = 1; j <=N; ++j) {
//            if (strcmp(temp,HC[j])==0) {
//                n -= i + 1;
//                return j;
//            }
//        }
//    }
//    return 0; //0代表未查到
//}


void UnCompress()
{
    cout << "请输入要解压文件所在的绝对路径：" << endl;
    cin>>filename;
    HeadFile Hd;
    HuffmanTree HT;
    HuffmanCode HC;
    FILE *fout = fopen(filename,"rb");
    fread(&Hd,sizeof(HeadFile),1,fout);
    CreatHuffmanTree(HT,N,Hd);
    CreateHCode(HT,HC,N);
    strcat(filename,".uncompress");
    FILE *fin = fopen(filename,"wb");
    int ch,size;
    size = Hd.length%8?Hd.length/8+1:Hd.length/8;
    char str[size];
    for (int i=0;(ch=fgetc(fout))!=EOF;i++)
    {
        str[i]= ch;
    }
//    cout<<"哈夫曼树:"<<endl;
//    for (int j = 1; j <=2*N-1 ; ++j) {
//        cout<<j<<" "<<HT[j].weight<<" "<<HT[j].parents<<" "<<HT[j].lchild<<" "<<HT[j].rchild<<endl;
//    }
//    cout<<"哈夫曼编码:"<<endl;
//    for (int i = 1  i <= N; ++i) {
//        cout<<i<<" "<<HC[i]<<endl;
//    }
}

int GetFileSize(char name[])
{
    FILE *fp = fopen(filename, "rb");
    fseek( fp, 0, SEEK_END );
    int size =  ftell(fp);
    fclose(fp);
    return size;
}



int main() {
    double f1,f2,percent;
    HeadFile Hd;
    HuffmanTree HT;
    HuffmanCode HC;
    InitHead(Hd,N);
    CreatHuffmanTree(HT,N,Hd);
    CreateHCode(HT,HC,N);
    Compress(HC,Hd);
    f1 = GetFileSize(filename);
    strcat(filename,".hfm");
    f2 = GetFileSize(filename);
    percent = f2/f1*100;
//    cout<<"哈夫曼树:"<<endl;
//    for (int j = 1; j <=2*N-1 ; ++j) {
//        cout<<j<<" "<<HT[j].weight<<" "<<HT[j].parents<<" "<<HT[j].lchild<<" "<<HT[j].rchild<<endl;
//    }
//    cout<<"哈夫曼编码:"<<endl;
//    for (int i = 1; i <= N; ++i) {
//        cout<<i<<" "<<HC[i]<<endl;
//    }
    cout<<"源文件大小："<<f1<<endl;
    cout<<"新文件大小："<<f2<<endl;
    cout<<"压缩率 ："<<percent<<"%"<<endl;
    return 0;
}
//int main(){
//    UnCompress();
//    return 0;
//}

//E:\\Pictures\\2.png
