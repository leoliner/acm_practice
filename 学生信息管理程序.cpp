#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct List
{
    int no;
    char name[20];
    int data;
    List *next;
}L;
void put_in(L * &head)
{
    L *s;
    s=(L *)malloc(sizeof(L));
    cin>>s->no;
    cin>>s->name;
    cin>>s->data;
    s->next=NULL;
    head->next=s;
}
void score_solt(L * &head)
{
    L *p,*pre,*q;
    p=head->next->next;
    head->next->next=NULL;
    while(p!=NULL)
    {
        q=p->next;
        pre=head;
        while(pre->next!=NULL&&pre->next->data>p->data)
            pre=pre->next;
        p->next=pre->next;
        pre->next=p;
        p=q;
    }
}
void score_out(L * &head)
{
    score_solt(head);
    L *p=head->next;
    while(p!=NULL)
    {
        cout<<p->no<<","<<p->name<<","<<p->data<<"\n";
        p=p->next;
    }
}
void save_data_exit(L * &head)
{

}
int main()
{
    int a;
    L *head;
    head=(L *)malloc(sizeof(L));
    head->next=NULL;
    do
    {
        cin>>a;
        switch(a){
                            /*case 1:putin(head);break;
                            case 2:putout();break;
                            case 3:no_solt();break;
                            case 4:no_out();break;
                            case 5:classno_solt();break;
                            case 6:classno_out();break;
                            case 7:score_solt();break;*/
                            case 1:put_in(head);break;
                            case 2:break;
                            case 3:break;
                            case 4:break;
                            case 5:break;
                            case 6:break;
                            case 7:score_solt(head);break;
                            case 8:score_out(head);break;
                            case 0:save_data_exit(head);break;}
    }while(a!=0);

}
