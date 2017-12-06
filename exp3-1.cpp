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
}SqStack;//顺序栈类型
void InitStack(SqStack *&s);//初始化栈
void DestoryStack(SqStack *&s);//销毁栈
bool StackEmpty(SqStack *s);//判断栈是否为空
bool Push(SqStack *&s,ElemType e);//进栈
bool Pop(SqStack *&s,ElemType &e);//出栈
bool GetTop(SqStack *s,ElemType &e);//取栈顶元素
bool symmetry(ElemType str[])//判断回文
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
    gets(a);//也可写scanf("%s",a);(a前面不需要再加&)
    //getchar()有一个int型的返回值.
    //当程序调用getchar时.程序就等着用户按键.用户输入的字符被存放在键盘缓冲区中.直到用户按回车为止(回车字符也放在缓冲区中).当用户键入回车之后,getchar才开始从stdin流中每次读入一个字符.
    //getchar函数的返回值是用户输入的第一个字符的ASCII码,如出错返回-1,且将用户输入的字符回显到屏幕.如用户在按回车之前输入了不止一个字符,其他字符会保留在键盘缓存区中,等待后续getchar调用读取.也就是说,后续的getchar调用不会等待用户按键,而直接读取缓冲区中的字符,直到缓冲区中的字符读完为后,才等待用户按键.
    //最重要的区别是gets读一行，getchar()读一个字符。
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

