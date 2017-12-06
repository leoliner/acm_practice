#include<iostream>
#include<stdio.h>
using namespace std;
#define MaxSize 100
typedef int ElemType;
typedef struct
{
    int r;//�к�
    int c;//�к�
    ElemType d;//Ԫ��ֵ
}TupNode;//��Ԫ������
typedef struct
{
    int rows;//����
    int cols;//����
    int nums;//����Ԫ�ظ���
    TupNode data[MaxSize];
}TSMatrix;
void CreateMat(TSMatrix &t,ElemType **A,int n);//��һ��ϡ����󴴽�����Ԫ���ʾ
bool Value(TSMatrix &t,ElemType x,int i,int j);//��Ԫ��Ԫ�صĸ�ֵ
bool Assign(TSMatrix t,ElemType &x,int i,int j);//��ָ��λ�õ�Ԫ��ֵ��������
void DispMat(TSMatrix t);//�����Ԫ��
void TranTat(TSMatrix t,TSMatrix &tb);//ϡ�����ת��
//��������1 0 0 0;0 2 0 0;0 0 3 0;0 0 0 4
//������Խ���֮��
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
    //�ͷ������ڴ�ռ�
    for(int i=0;i<n;i++)
    delete [] a[i];
    delete [] a;
    return 0;
}
void CreateMat(TSMatrix &t,ElemType **A,ElemType n) //��һ��ϡ����󴴽�����Ԫ���ʾ
{
    int i,j;
    t.rows=n;
    t.cols=n;
    t.nums=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        if(A[i][j]!=0)//����ϡ������еķ���Ԫ��
        {
            t.data[t.nums].r=i;
            t.data[t.nums].c=j;
            t.data[t.nums].d=A[i][j];
            t.nums++;
        }
    }
}
bool Value(TSMatrix &t,ElemType x,int i,int j) //��Ԫ��Ԫ�صĸ�ֵ
{
    int k=0,k1;
    if(i>=t.rows || t.cols)
        return false;
    while(k<t.nums &&i>t.data[k].r) k++;
}
bool Assign(TSMatrix t,ElemType &x,int i,int j) //��ָ��λ�õ�Ԫ��ֵ��������
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
void DispMat(TSMatrix t) //�����Ԫ��
{
    int k;
    if(t.nums<=0)
        return ;
    printf("\t%d\t%d\t%d\n",t.rows,t.cols,t.nums);
    printf("\t��������������������������������_\n");
    for(k=0;k<t.nums;k++)
        printf("\t%d\t%d\t%d\n",t.data[k].r,t.data[k].c,t.data[k].d);
}
void TranTat(TSMatrix t,TSMatrix &tb) //ϡ�����ת��
{
    int k,k1=0,v;
    tb.rows=t.cols;
    tb.cols=t.rows;
    tb.nums=t.nums;
    if(t.nums!=0)
    {
        for(v=0;v<t.cols;v++)
            for(k=0;k<t.rows;k++)//ɨ��t�е�����Ԫ��
        if(t.data[k].c==v)//���к�Ϊv
        {
            tb.data[k1].r=t.data[k].c;
            tb.data[k1].c=t.data[k].r;
            tb.data[k1].d=t.data[k].d;
            k1++;
        }
    }
}
