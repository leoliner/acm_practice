#include<iostream>
#include<malloc.h>
#include<stdio.h>
#define MaxSize 100
using namespace std;
typedef int ElemType;

//����˳�����
typedef struct
{
    ElemType data[MaxSize];
    int front;//��ͷ
    int rear;//��β
}SqQueue;
void InitQueue(SqQueue *&q);//��ʼ������
void DestroyQueue(SqQueue *&q);//���ٶ���
bool QueueEmpty(SqQueue *q);//�ж϶����Ƿ�Ϊ��
bool enQueue(SqQueue *&q,ElemType e);//���
bool deQueue(SqQueue *&q,ElemType &e);//����
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
    q->rear=(q->rear+1)%MaxSize;//���������rearֵΪ0��δ����rear�൱��++
    q->data[q->rear]=e;//Ԫ�شӶ�β����
    return true;
}
bool deQueue(SqQueue *&q,ElemType &e)
{
    if(q->front==q->rear)
        return false;
    q->front=(q->front+1)%MaxSize;
    e=q->data[q->front];//��ͷԪ�س���
    return true;
}
