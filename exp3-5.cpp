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
}SqStack;//顺序栈类型

void InitStack(SqStack *&s);//初始化栈
void DestoryStack(SqStack *&s);//销毁栈
bool StackEmpty(SqStack *s);//判断栈是否为空
bool Push(SqStack *&s,ElemType e);//进栈
bool Pop(SqStack *&s,ElemType &e);//出栈
bool GetTop(SqStack *s,ElemType &e);//取栈顶元素
//void trans(SqStack *&s,char *a,char b[]);//转化后缀表达式
void compvalue(SqStack *&s,char *a);//求后缀表达式的值
//样例输入：10 5 2 3 * - 2 * + #
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
    while(*b!='#')//去掉表达式里的#
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
        case '+'://若是+号，取栈顶两个元素相加，结果进栈
            Pop(s,a);
            Pop(s,b);
            c=a+b;
            Push(s,c);
            break;
        case '-'://若是-号，取栈顶前后两个元素相减，结果进栈
            Pop(s,a);
            Pop(s,b);
            c=b-a;
            Push(s,c);
            break;
        case '*'://若是*号，取栈顶两个元素相乘，结果进栈
            Pop(s,a);
            Pop(s,b);
            c=a*b;
            Push(s,c);
            break;
        case '/'://若是/号，取栈顶前后两个元素相除，结果进栈
            Pop(s,a);
            Pop(s,b);
            if(a!=0)
            {
                c=b/a;
               Push(s,c);
            }
            else
            {
                cout<<"出零错误！"<<endl;
                exit(0);
            }
            break;
        default://处理数字字符和空格
            if(*exp!=' ')
            {
                d=0;//将连续的数字字符转化为对应数值存放在d中
                while(*exp>='0'&&*exp<='9')//是数字字符
                {
                    d=10*d+*exp-'0';
                    exp++;
                }
                Push(s,d);
            }
            break;
        }
        exp++;//继续处理其他字符
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

