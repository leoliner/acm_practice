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
bool symmetry(ElemType str[])//�жϻ���
{
    SqStack *st;
    int i;ElemType e;
    InitStack(st);
    for(i=0;str[i]!='\0';i++)
        Push(st,str[i]);
    for(i=0;str[i]!='\0';i++)
    {
        Pop(st,e);
        if(str[i]!=e)
        {
            DestoryStack(st);
            return false;
        }
    }
    DestoryStack(st);
    return true;
}
int main(void)
{
    char a[MaxSize];
    gets(a);//Ҳ��дscanf("%s",a);(aǰ�治��Ҫ�ټ�&)
    //getchar()��һ��int�͵ķ���ֵ.
    //���������getcharʱ.����͵����û�����.�û�������ַ�������ڼ��̻�������.ֱ���û����س�Ϊֹ(�س��ַ�Ҳ���ڻ�������).���û�����س�֮��,getchar�ſ�ʼ��stdin����ÿ�ζ���һ���ַ�.
    //getchar�����ķ���ֵ���û�����ĵ�һ���ַ���ASCII��,�������-1,�ҽ��û�������ַ����Ե���Ļ.���û��ڰ��س�֮ǰ�����˲�ֹһ���ַ�,�����ַ��ᱣ���ڼ��̻�������,�ȴ�����getchar���ö�ȡ.Ҳ����˵,������getchar���ò���ȴ��û�����,��ֱ�Ӷ�ȡ�������е��ַ�,ֱ���������е��ַ�����Ϊ��,�ŵȴ��û�����.
    //����Ҫ��������gets��һ�У�getchar()��һ���ַ���
    if(symmetry(a))
        cout<<"yes";
    else
        cout<<"no";
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

