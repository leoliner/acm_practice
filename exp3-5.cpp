#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MaxSize 100
using namespace std;
typedef float ElemType;
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
//void trans(SqStack *&s,char *a,char b[]);//ת����׺���ʽ
void compvalue(SqStack *&s,char *a);//���׺���ʽ��ֵ
//�������룺10 5 2 3 * - 2 * + #
int main(void)
{
    SqStack *s;
    ElemType e;
    int i;
    char *b;
    char a[MaxSize];
    b=a;
    InitStack(s);
    gets(a);
    while(*b!='#')//ȥ�����ʽ���#
    {
        b++;
    }
    *b='\0';
    compvalue(s,a);
    GetTop(s,e);
    cout<<e<<endl;
    return 0;
}
void compvalue(SqStack *&s,char *exp)
{
    ElemType a,b,c,d;
    while(*exp!='\0')
    {
        switch(*exp)
        {
        case '+'://����+�ţ�ȡջ������Ԫ����ӣ������ջ
            Pop(s,a);
            Pop(s,b);
            c=a+b;
            Push(s,c);
            break;
        case '-'://����-�ţ�ȡջ��ǰ������Ԫ������������ջ
            Pop(s,a);
            Pop(s,b);
            c=b-a;
            Push(s,c);
            break;
        case '*'://����*�ţ�ȡջ������Ԫ����ˣ������ջ
            Pop(s,a);
            Pop(s,b);
            c=a*b;
            Push(s,c);
            break;
        case '/'://����/�ţ�ȡջ��ǰ������Ԫ������������ջ
            Pop(s,a);
            Pop(s,b);
            if(a!=0)
            {
                c=b/a;
               Push(s,c);
            }
            else
            {
                cout<<"�������"<<endl;
                exit(0);
            }
            break;
        default://���������ַ��Ϳո�
            if(*exp!=' ')
            {
                d=0;//�������������ַ�ת��Ϊ��Ӧ��ֵ�����d��
                while(*exp>='0'&&*exp<='9')//�������ַ�
                {
                    d=10*d+*exp-'0';
                    exp++;
                }
                Push(s,d);
            }
            break;
        }
        exp++;//�������������ַ�
    }
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

