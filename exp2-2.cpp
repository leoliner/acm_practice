#include<iostream>
#include<malloc.h>
using namespace std;
#define MaxSize 100
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
}SqList;
void InitList(SqList *&L);//初始化顺序表
void CreateList(SqList *&L,ElemType a[],int n);//整体创建顺序表
void DestroyList(SqList *&L);//销毁顺序表
bool ListEmpty(SqList *L);//判断顺序表是否为空
int ListLength(SqList *l);//求顺序表长
void DispList(SqList *L);//输出顺序表
bool GetElem(SqList *L,int i,ElemType &e);//求顺序表某一元素值
int LocateElem(SqList *L,ElemType e);//按元素值查找
bool ListInsert(SqList *&L,int i,ElemType e);//插入元素数据
bool ListDelete(SqList *&L,int i,ElemType &e);//删除数据元素
void ChangeList(SqList *&L)//逆置顺序表
{
    for(int i = 0; i <L->length / 2; i++)
        {
            swap(L->data[i], L->data[L->length - i - 1]);
        }
}
int main()
{
    SqList *L;
    ElemType a[10];
    for(int i=0;i<10;i++)
        cin>>a[i];
    CreateList(L,a,10);
    ChangeList(L);
    DispList(L);
}
void InitList(SqList *&L)
{
    L=(SqList *)malloc(sizeof(SqList));
    L->length=0;
}
void CreateList(SqList *&L,ElemType a[],int n)
{
    int i=0,k=0;
    L=(SqList *)malloc(sizeof(SqList));
    while(i<n)
    {
        L->data[i]=a[i];
        k++;i++;
    }
    L->length=k;
}
void DestroyList(SqList *&L)
{
    free(L);
}
bool ListEmpty(SqList *L)
{
    return (L->length==0);
}
int ListLength(SqList *L)
{
    return  (L->length);
}
void DispList(SqList *L)
{
    for(int i=0;i<L->length;i++)
        cout<<L->data[i]<<" ";
    cout<<"\n";
}
bool GetElem(SqList *L,int i,ElemType &e)
{
    if(i<1 || i>L->length)
        return false;
    e=L->data[i-1];
    return true;
}
int LocateElem(SqList *L,ElemType e)
{
    int i =0;
    while(i<L->length&&L->data[i]!=e)
        i++;
    if(i>=L->length)
        return 0;
    else
        return i+1;
}
bool ListInsert(SqList *&L,int i,ElemType e)
{
    int j;
    if(i<1||i>L->length+1)
        return false;
    i--;
    for(j=L->length;j>i;j--)
        L->data[j]=L->data[j-1];
    L->data[i]=e;
    L->length++;
    return true;
}
bool ListDelete(SqList *&L,int i,ElemType &e)
{
    int j;
    if(i<1||i>L->length)
        return false;
    i--;
    e=L->data[i];
    for(j=i;j<L->length-1;j++)
        L->data[j]=L->data[j+1];
    L->length--;
    return true;
}
