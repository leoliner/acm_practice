#include<iostream>
#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
using namespace std;
typedef char ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int top;
}SqStack;//˳��ջ����
void InitStack(SqStack *&s);//��ʼ��ջ
void DestoryStack(SqStack *&s);//����ջ
bool StackEmpty(SqStack *s);//�ж�ջ�Ƿ�Ϊ��
bool Push(SqStack *&s,ElemType e);//��ջ
bool Pop(SqStack *&s,ElemType &e);//��ջ
bool GetTop(SqStack *s,ElemType &e);//ȡջ��Ԫ��
int JudgePair(SqStack *&s)//�ж��Ƿ�����ƥ��bug���������ų��ִ���
{
    int  i=0,j=0;
    ElemType left[MaxSize],right[MaxSize];
    ElemType e;
    while(!StackEmpty(s))
    {
        Pop(s,e);//40( 41) 91[ 93] 123{ 125}
        if(e==40 || e==91 || e==123)//eΪ������
           {
                left[i]=e;
                i++;
           }
        if(e==41 || e==93 || e==125)//eΪ������
           {
               right[j]=e;
               j++;
           }
    }
    left[i]=right[j]='\0';
    for(int a=0;a<i/2;a++)
    {
        ElemType temp;
        temp=left[a];
        left[a]=left[i-1-a];
        left[i-1-a]=temp;
    }
    if(i==j)
    {
        for(int x=0;x<i;x++)
        {
            if(left[x]==40)
                left[x]+=1;
            else
                left[x]+=2;
            if(left[x]==right[x])
                 return 1;
            else{}
        }
        return 0;
    }
    else
        return 0;
}
int main(void)
{
    SqStack *s;
    ElemType a[MaxSize];
    int i;
    InitStack(s);
    gets(a);
    for(i=0;a[i]!='\0';i++)
    {
        Push(s,a[i]);
    }
    cout<<JudgePair(s);
    return 0;
}
void InitStack(SqStack *&s)
{
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
}
void DestoryStack(SqStack *&s)
{
    free(s);
}
bool StackEmpty(SqStack *s)
{
    return (s->top==-1);
}
bool Push(SqStack *&s,ElemType e)
{
    if(s->top==MaxSize-1)
        return false;
    s->top++;
    s->data[s->top]=e;
    return true;
}
bool Pop(SqStack *&s,ElemType &e)
{
     if(s->top==-1)
        return false;
    e=s->data[s->top];
    s->top--;
    return true;
}
bool GetTop(SqStack *s,ElemType &e)
{
    if(s->top==-1)
        return false;
    e=s->data[s->top];
    return true;
}

