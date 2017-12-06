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
void trans(SqStack *&s,char *a,char b[]);//ת����׺���ʽ
int main(void)
{
    SqStack *s;
    int i;
    ElemType a[MaxSize],b[MaxSize];
    InitStack(s);
    for(i=0;i<MaxSize;i++)
    {
         cin>>a[i];
         if(a[i]=='#')
            break;
    }
    a[i]='\0';
    trans(s,a,b);
    puts(b);
    return 0;
}
void trans(SqStack *&s,char *a,char b[])
{
        ElemType e;
        int i=0;
        while(*a!='\0')
    {
        switch(*a)
        {
            case '('://�ж�Ϊ������
                Push(s,'(');//�����Ž�ջ
                a++;//ɨ����һ���ַ�
                break;
            case ')'://�ж�Ϊ������
                Pop(s,e);//��ջ��Ԫ�س�ջ
                while(e!='(')//��ջ��Ԫ�ز�Ϊ������ʱ
                {
                    b[i++]=e;//��e�����b[ ]������
                    Pop(s,e);//������ջջ��Ԫ��e�����ս������ų�ջ
                }
                a++;//ɨ����һ���ַ�
                break;
            case '+'://�ж�Ϊ+��
            case '-'://�ж�Ϊ-��
                while(!StackEmpty(s))//ջ��Ϊ��ʱѭ��
                {
                    GetTop(s,e);//ȡջ��Ԫ��e
                    if(e!='(')//e��Ϊ������ʱ
                    {
                        b[i++]=e;//��e�����b[ ]������
                        Pop(s,e);//��ջԪ��e
                    }
                    else//e��������ʱ
                        break;
                }
                Push(s,*a);//��+��-��ջ
                a++;//ɨ����һ���ַ�
                break;
            case '/':
            case '*':
                while(!StackEmpty(s))//��ջ�����е�*��/�������ջ������
                {
                    GetTop(s,e);//ȡջ��Ԫ��e
                    if(e=='*'||e=='/')
                    {
                        b[i++]=e;
                        Pop(s,e);
                    }
                    else
                        break;
                }
                Push(s,*a);
                a++;
                break;
            default://�����ַ�����
                if(*a>='A'&&*a<='Z')//����ĸ�ַ�
                    b[i++]=*a;
                a++;break;
        }
    }
    while(!StackEmpty(s))
    {
        Pop(s,e);
        b[i++]=e;
    }
    b[i]='\0';
    DestoryStack(s);
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


