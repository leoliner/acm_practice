#include<stdio.h>
#include<malloc.h>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LinkList;
LinkList *InitList(LinkList *L);//��ʼ������
void DispList(LinkList *L);//������Ա�
LinkList *ListInsert(LinkList *L,int i,ElemType e);//���������Ԫ��
ElemType GetElem(LinkList *L,int i);//�����Ա���ĳ������Ԫ��ֵ
int main()
{
    LinkList *L;
    ElemType a,number;
    int k,num=1;
    char opt;
    L=InitList(L);
    scanf("%d",&k);
    scanf("%c",&opt);
    while(1){
        scanf("%d",&a);
        L=ListInsert(L,num,a);
        scanf("%c",&opt);
        num++;
        if(opt=='\n')break;
    }
    num--;
    k=num-k+1;
    number=GetElem(L,k);
    if(number==0)
        printf("Not Found\n");
    else
        printf("%d \n",number);
}
LinkList *InitList(LinkList *L)//�½�����
{
    L=(LinkList *)malloc(sizeof(LinkList));
    L->next=NULL;
    return L;
}
void DispList(LinkList *L)//������Ա�
{
    LinkList *p=L->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
LinkList *ListInsert(LinkList *L,int i,ElemType e)//����Ԫ��
{
    int j=0;
    LinkList *p=L,*s;
    if(i<=0)
    {
        return L;
    }
    while(j<i-1 &&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
      {
          return L;
      }
    else
    {
        s=(LinkList *)malloc(sizeof(LinkList));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return L;
    }
}
ElemType GetElem(LinkList *L,int i)//�����Ա���ĳ������Ԫ��ֵ
{
    int j=0;
    ElemType e;
    LinkList *p=L;
    while(j<i&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return 0;
    else
    {
        e=p->data;
        return e;
    }
}
