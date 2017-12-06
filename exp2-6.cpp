#include<stdio.h>
#include<malloc.h>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LinkList;
LinkList *InitList(LinkList *L);//初始化链表
void DispList(LinkList *L);//输出线性表
LinkList *ListInsert(LinkList *L,int i,ElemType e);//向链表插入元素
ElemType GetElem(LinkList *L,int i);//求线性表中某个数据元素值
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
LinkList *InitList(LinkList *L)//新建链表
{
    L=(LinkList *)malloc(sizeof(LinkList));
    L->next=NULL;
    return L;
}
void DispList(LinkList *L)//输出线性表
{
    LinkList *p=L->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
LinkList *ListInsert(LinkList *L,int i,ElemType e)//插入元素
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
ElemType GetElem(LinkList *L,int i)//求线性表中某个数据元素值
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
