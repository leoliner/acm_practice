#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LinkList;
//ʹ��ͷ�巨
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
//ʹ��β�巨
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
//��ʼ�����Ա�
void InitList(LinkList *&L)
{
    L=(LinkList *)malloc(sizeof(LinkList));
    L->next=NULL;
}
//�������Ա�
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
//�ж����Ա��Ƿ�Ϊ�ձ�
bool ListEmpty(LinkList *L)
{
    return (L->next==NULL);
}
//�����Ա�ĳ���
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
//������Ա�
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
//�����Ա���ĳ������Ԫ��ֵ
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
//��Ԫ��ֵ����
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
//��������Ԫ��
bool ListInsert(LinkList *&L,int i,ElemType e)
{
    int j=0;
    LinkList *p=L,*s;
    if(i<=0)return false;
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
//ɾ������Ԫ��
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

//��·�鲢�㷨
void UnionList(LinkList *L1,LinkList *L2,LinkList *&L3)
{
    LinkList *pa=L1->next,*pb=L2->next,*r,*s;
    L3=(LinkList *)malloc(sizeof(LinkList));
    r=L3;
    while(pa!=NULL &&pb!=NULL)
    {
        if(pa->data<pb->data)
        {
            s=(LinkList *)malloc(sizeof(LinkList));
            s->data=pa->data;
            r->next=s;r=s;
            pa=pa->next;
        }
        else
        {
            s=(LinkList *)malloc(sizeof(LinkList));
            s->data=pb->data;
            r->next=s;r=s;
            pb=pb->next;
        }
    }
        while(pa!=NULL)
        {
            s=(LinkList *)malloc(sizeof(LinkList));
            s->data=pa->data;
            r->next=s;r=s;
            pa=pa->next;
        }
        while(pb!=NULL)
        {
            s=(LinkList *)malloc(sizeof(LinkList));
            s->data=pb->data;
            r->next=s;r=s;
            pb=pb->next;
        }
        r->next=NULL;
}
int main()
{
    LinkList *L1,*L2,*L3;
    ElemType a;
    int k=1;char opt;
    InitList(L1);
    InitList(L2);
    InitList(L3);
    while(1){
        cin>>a;
        ListInsert(L1,k,a);
        scanf("%c",&opt);
        k++;
        if(opt=='\n')break;
    }//����һ������������
    //DispList(L1);
    k=1;
    while(1){
        cin>>a;
        ListInsert(L2,k,a);
        scanf("%c",&opt);
        k++;
        if(opt=='\n')break;
    }//����ڶ�������������
     UnionList(L1,L2,L3);
     DispList(L3);
}

