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
void trans(SqStack *&s,char *a,char b[]);//转化后缀表达式
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
            case '('://判定为左括号
                Push(s,'(');//左括号进栈
                a++;//扫描下一个字符
                break;
            case ')'://判定为右括号
                Pop(s,e);//将栈顶元素出栈
                while(e!='(')//当栈顶元素不为左括号时
                {
                    b[i++]=e;//将e存放在b[ ]数组里
                    Pop(s,e);//继续出栈栈顶元素e，最终将左括号出栈
                }
                a++;//扫描下一个字符
                break;
            case '+'://判定为+号
            case '-'://判定为-号
                while(!StackEmpty(s))//栈不为空时循环
                {
                    GetTop(s,e);//取栈顶元素e
                    if(e!='(')//e不为左括号时
                    {
                        b[i++]=e;//将e存放在b[ ]数组里
                        Pop(s,e);//出栈元素e
                    }
                    else//e是左括号时
                        break;
                }
                Push(s,*a);//将+、-入栈
                a++;//扫描下一个字符
                break;
            case '/':
            case '*':
                while(!StackEmpty(s))//将栈顶已有的*或/运算符出栈并存入
                {
                    GetTop(s,e);//取栈顶元素e
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
            default://处理字符数组
                if(*a>='A'&&*a<='Z')//是字母字符
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


