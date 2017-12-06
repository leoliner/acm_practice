#include<iostream>
#include<malloc.h>
#define MaxSize 100
typedef char ElemType;
using namespace std;
//环形顺序队列
typedef struct
{
    ElemType data[MaxSize];
    int front;//队头
    int rear;//队尾
}SqQueue;
void InitQueue(SqQueue *&q);
void DestroyQueue(SqQueue *&q);
bool QueueEmpty(SqQueue *q);
bool enQueue(SqQueue *&q,ElemType e);
bool deQueue(SqQueue *&q,ElemType &e);
int main(void)
{
    ElemType a;
    SqQueue *q;
    InitQueue(q);
    if(QueueEmpty(q))
        cout<<"This queue is empty!"<<endl;
    else
        cout<<"This queue is not empty!"<<endl;
    for(int i=0;i<3;i++)
    {
        cin>>a;
        enQueue(q,a);
    }
    deQueue(q,a);
    cout<<"The deleted element is "<<a<<"."<<endl;
    for(int i=0;i<3;i++)
    {
        cin>>a;
        enQueue(q,a);
    }
    cout<<"The queue is:";
    while(!QueueEmpty(q))
    {
        deQueue(q,a);
        cout<<a;
    }
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
