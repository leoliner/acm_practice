#include<iostream>
#include<malloc.h>
#include<stdio.h>
#define MaxSize 100
using namespace std;
typedef int ElemType;

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
void LastNumber(int n,int m);

int main(void)
{
    int N,M;
    cin>>N>>M;
    LastNumber(N,M);
    return 0;
}
void LastNumber(int n,int m)
{
    int i,j;
    ElemType e;
    SqQueue *q;
    InitQueue(q);
    for(i=1;i<=n;i++)
        enQueue(q,i);
    i=0;
    while(!QueueEmpty(q))
    {
        deQueue(q,e);
        i++;
        if(i%m!=0)
        {
            enQueue(q,e);
        }
        if(QueueEmpty(q))
            cout<<e;
    }
    DestroyQueue(q);
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
