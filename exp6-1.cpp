#include<iostream>
#include<stdio.h>
using namespace std;
#define MaxSize 100
typedef int ElemType;
typedef struct
{
    int r;//行号
    int c;//列号
    ElemType d;//元素值
}TupNode;//三元组类型
typedef struct
{
    int rows;//行数
    int cols;//列数
    int nums;//非零元素个数
    TupNode data[MaxSize];
}TSMatrix;
void CreateMat(TSMatrix &t,ElemType **A,int n);//从一个稀疏矩阵创建其三元组表示
bool Value(TSMatrix &t,ElemType x,int i,int j);//三元组元素的赋值
bool Assign(TSMatrix t,ElemType &x,int i,int j);//将指定位置的元素值赋给变量
void DispMat(TSMatrix t);//输出三元组
void TranTat(TSMatrix t,TSMatrix &tb);//稀疏矩阵转置
//样例数据1 0 0 0;0 2 0 0;0 0 3 0;0 0 0 4
//输出主对角线之和
int main(void)
{
    int n;
    TSMatrix t;
    ElemType **a;
    cin>>n;
    a=new ElemType* [n];
    for(int i=0;i<n;i++)
        a[i]=new ElemType[n];

    char x;
    for(int c=0;c<n;c++)
        for(int d=0;d<n;d++)
        scanf("%d%c",&a[c][d],&x);
    CreateMat(t,a,n);
    int sum=0;
    for(int i=0;i<t.nums;i++)
    {
        if(t.data[i].c==t.data[i].r)
        sum+=t.data[i].d;
    }

    cout<<sum;
    //释放数组内存空间
    for(int i=0;i<n;i++)
    delete [] a[i];
    delete [] a;
    return 0;
}
void CreateMat(TSMatrix &t,ElemType **A,ElemType n) //从一个稀疏矩阵创建其三元组表示
{
    int i,j;
    t.rows=n;
    t.cols=n;
    t.nums=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        if(A[i][j]!=0)//储存稀疏矩阵中的非零元素
        {
            t.data[t.nums].r=i;
            t.data[t.nums].c=j;
            t.data[t.nums].d=A[i][j];
            t.nums++;
        }
    }
}
bool Value(TSMatrix &t,ElemType x,int i,int j) //三元组元素的赋值
{
    int k=0,k1;
    if(i>=t.rows || t.cols)
        return false;
    while(k<t.nums &&i>t.data[k].r) k++;
}
bool Assign(TSMatrix t,ElemType &x,int i,int j) //将指定位置的元素值赋给变量
{
    int k=0;
    if(i>=t.rows || j>=t.cols)
        return false;
    while(k<t.nums && i>t.data[k].r) k++;
    while(k<t.nums && i==t.data[k].r && j>t.data[k].c) k++;
    if(t.data[k].r==i&&t.data[k].c==j)
        x=t.data[k].d;
    else
        x=0;
    return true;
}
void DispMat(TSMatrix t) //输出三元组
{
    int k;
    if(t.nums<=0)
        return ;
    printf("\t%d\t%d\t%d\n",t.rows,t.cols,t.nums);
    printf("\t————————————————_\n");
    for(k=0;k<t.nums;k++)
        printf("\t%d\t%d\t%d\n",t.data[k].r,t.data[k].c,t.data[k].d);
}
void TranTat(TSMatrix t,TSMatrix &tb) //稀疏矩阵转置
{
    int k,k1=0,v;
    tb.rows=t.cols;
    tb.cols=t.rows;
    tb.nums=t.nums;
    if(t.nums!=0)
    {
        for(v=0;v<t.cols;v++)
            for(k=0;k<t.rows;k++)//扫描t中的所有元素
        if(t.data[k].c==v)//若列号为v
        {
            tb.data[k1].r=t.data[k].c;
            tb.data[k1].c=t.data[k].r;
            tb.data[k1].d=t.data[k].d;
            k1++;
        }
    }
}
