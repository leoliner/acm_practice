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

int main()
{
    LinkList *L;
    ElemType s[6];
    ElemType e;
    int i,j;
    InitList(L);//��ʼ��������
    for(int i=0;i<6;i++)
    cin>>s[i];
    CreateListR(L,s,6);//ʹ��β�巨����������
    DispList(L);//���������
    //cout<<ListLength(L)<<endl;//������ĳ���

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
    printf("The location of element 'a' is: %d\n",j); //���a��λ��

    ListInsert(L,4,'f');//����Ԫ��f�����ĸ�Ԫ��
    DispList(L);//������Ա�L

    ListDelete(L,3,e);//ɾ��������Ԫ��
    DispList(L);//���������L

    DestroyList(L);//�����ͷŵ�����
}
