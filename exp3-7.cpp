#include<iostream>
#include<malloc.h>
#include<stdio.h>
#define MaxSize 10000
typedef int ElemType;
using namespace std;
//˳��ջ
typedef struct
{
    ElemType data[MaxSize];
    int top;
}SqStack;

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

void InitStack(SqStack *&s);//��ʼ��ջ
void DestoryStack(SqStack *&s);//����ջ
bool StackEmpty(SqStack *s);//�ж�ջ�Ƿ�Ϊ��
bool Push(SqStack *&s,ElemType e);//��ջ
bool Pop(SqStack *&s,ElemType &e);//��ջ
bool GetTop(SqStack *s,ElemType &e);//ȡջ��Ԫ��

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
