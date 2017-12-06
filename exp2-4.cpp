#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef char ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LinkList;
//使用头插法
void CreateListF(LinkList *&L,ElemType a[],int n)
{
    LinkList *s;
    int i;
    L=(LinkList *)malloc(sizeof(LinkList));
    L->next=NULL;
    for(i=0; i<n; i++)
    {
        s=(LinkList *)malloc(sizeof(LinkList));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
    }
}
//使用尾插法
void CreateListR(LinkList *&L,ElemType a[],int n)
{
    LinkList *s,*r;
    int i;
    L=(LinkList *)malloc(sizeof(LinkList));
    r=L;
    for(i=0; i<n; i++)
    {
        s=(LinkList *)malloc(sizeof(LinkList));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;
}
//初始化线性表
void InitList(LinkList *&L)
{
    L=(LinkList *)malloc(sizeof(LinkList));
    L->next=NULL;
}
//销毁线性表
void DestroyList(LinkList *&L)
{
    LinkList *pre=L,*p=L->next;
    while(p!=NULL)
    {
        free(pre);
        pre=p;
        p=pre->next;
    }
    free(pre);
}
//判断线性表是否为空表
bool ListEmpty(LinkList *L)
{
    return (L->next==NULL);
}
//求线性表的长度
int ListLength(LinkList *L)
{
    int n=0;
    LinkList *p=L;
    while(p->next!=NULL)
    {
        n++;
        p=p->next;
    }
    return (n);
}
//输出线性表
void DispList(LinkList *L)
{
    LinkList *p=L->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    printf("\n");
}
//求线性表中某个数据元素值
bool GetElem(LinkList *L,int i,ElemType &e)
{
    int j=0;
    LinkList *p=L;
    while(j<i&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else
    {
        e=p->data;
        return true;
    }
}
//按元素值查找
int LocateElem(LinkList *L,ElemType e)
{
    int i=1;
    LinkList *p=L->next;
    while(p!=NULL&&p->data!=e)
    {
        p=p->next;
        i++;
    }
    if(p==NULL)
        return (0);
    else
        return(i);
}
//插入数据元素
bool ListInsert(LinkList *&L,int i,ElemType e)
{
    int j=0;
    LinkList *p=L,*s;
    while(j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else
    {
        s=(LinkList *)malloc(sizeof(LinkList));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return true;
    }

}
//删除数据元素
bool ListDelete(LinkList *&L,int i,ElemType &e)
{
    int j=0;
    LinkList *p=L,*q;
    while(j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else
    {
        q=p->next;
        if(q==NULL)
            return false;
        e=q->data;
        p->next=q->next;
        free(q);
        return true;
    }
}

int main()
{
    LinkList *L;
    ElemType s[6];
    ElemType e;
    int i,j;
    InitList(L);//初始化单链表
    for(int i=0;i<6;i++)
    cin>>s[i];
    CreateListR(L,s,6);//使用尾插法建立单链表
    DispList(L);//输出单链表
    //cout<<ListLength(L)<<endl;//求单链表的长度

    if(ListEmpty(L))
    {
        cout<<"The list is empty!"<<endl;
    }
    else
    {
        cout<<"The list is not empty!"<<endl;
    }

    GetElem(L,3,e);
    cout<<"The third element is "<<e<<"."<<endl;

    j=LocateElem(L,'a');
    printf("The location of element 'a' is: %d\n",j); //输出a的位置

    ListInsert(L,4,'f');//插入元素f到第四个元素
    DispList(L);//输出线性表L

    ListDelete(L,3,e);//删除第三个元素
    DispList(L);//输出单链表L

    DestroyList(L);//销毁释放单链表
}
