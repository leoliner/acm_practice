#include<iostream>
#include<malloc.h>
#define MaxSize 100
using namespace std;
typedef char ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int top;
}SqStack;//顺序栈类型
void InitStack(SqStack *&s);//初始化栈
void DestoryStack(SqStack *&s);//销毁栈
bool StackEmpty(SqStack *s);//判断栈是否为空
bool Push(SqStack *&s,ElemType e);//进栈
bool Pop(SqStack *&s,ElemType &e);//出栈
bool GetTop(SqStack *s,ElemType &e);//取栈顶元素
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
