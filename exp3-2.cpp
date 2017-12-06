#include<iostream>
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
int main(void)
{
    SqStack *s;
    ElemType a;
    InitStack(s);

    if(StackEmpty(s))
        cout<<"This stack is empty!"<<endl;
    else
        cout<<"This stack is not empty!"<<endl;

    for(int i=0;i<5;i++)
    {
        cin>>a;
        Push(s,a);
    }
    if(StackEmpty(s))
        cout<<"This stack is empty!"<<endl;
    else
        cout<<"This stack is not empty!"<<endl;

    cout<<"The deleted stack element is:";
    while(!StackEmpty(s))
    {
        Pop(s,a);
        cout<<a;
    }

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
