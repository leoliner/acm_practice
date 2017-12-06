#include<iostream>
#include<malloc.h>
#include<stdio.h>
#define MaxSize 10000
typedef int ElemType;
using namespace std;
//顺序栈
typedef struct
{
    ElemType data[MaxSize];
    int top;
}SqStack;

//环形顺序队列
typedef struct
{
    ElemType data[MaxSize];
    int front;//队头
    int rear;//队尾
}SqQueue;

void InitQueue(SqQueue *&q);//初始化队列
void DestroyQueue(SqQueue *&q);//销毁队列
bool QueueEmpty(SqQueue *q);//判断队列是否为空
bool enQueue(SqQueue *&q,ElemType e);//入队
bool deQueue(SqQueue *&q,ElemType &e);//出队

void InitStack(SqStack *&s);//初始化栈
void DestoryStack(SqStack *&s);//销毁栈
bool StackEmpty(SqStack *s);//判断栈是否为空
bool Push(SqStack *&s,ElemType e);//进栈
bool Pop(SqStack *&s,ElemType &e);//出栈
bool GetTop(SqStack *s,ElemType &e);//取栈顶元素

int main(void)
{
    SqQueue *q;
    SqStack *s;
    InitQueue(q);
    InitStack(s);
    int num,i=0;
    ElemType a,b;
    cin>>num;
    while(1)
    {
        char temp;
        cin>>a;
        enQueue(q,a);
        scanf("%c",&temp);
        if(temp=='\n')
            break;
    }
    while(!QueueEmpty(q))
    {
        deQueue(q,b);
        Push(s,b);
    }
    while(!StackEmpty(s))
    {
        Pop(s,b);
        cout<<b<<" ";
    }
    DestoryStack(s);
    DestroyQueue(q);
    return 0;
}
void InitQueue(SqQueue *&q)
{
    q=(SqQueue *)malloc(sizeof(SqQueue));
    q->front=q->rear=0;
}
void DestroyQueue(SqQueue *&q)
{
    free(q);
}
bool QueueEmpty(SqQueue *q)
{
    return (q->front==q->rear);
}
bool enQueue(SqQueue *&q,ElemType e)
{
    if((q->rear+1)%MaxSize==q->front)
        return false;
    q->rear=(q->rear+1)%MaxSize;//如果队满，rear值为0，未满，rear相当于++
    q->data[q->rear]=e;//元素从队尾进队
    return true;
}
bool deQueue(SqQueue *&q,ElemType &e)
{
    if(q->front==q->rear)
        return false;
    q->front=(q->front+1)%MaxSize;
    e=q->data[q->front];//队头元素出队
    return true;
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
