#include<iostream>
#include<malloc.h>
#include<queue>
using namespace std;
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
    ElemType data;
    struct node *lchild;
    struct node *rchild;
}BTNode;
void CreateBTree(BTNode *&b,char *str);//������
void DestoryBTree(BTNode *&b);//������
BTNode *FindNode(BTNode *b,ElemType x);//���ҽ��
BTNode *LchildNode(BTNode *p);//���ؽ��p�����ӽ��
BTNode *RchildNode(BTNode *p);//���ؽ��p���Һ��ӽ��
int BTHeight(BTNode *b);//��������߶�
int BTWidth(BTNode *b);//����������
void DispBTree(BTNode *b);//���������
void GetNum(BTNode *b,int &num);//����������н�����
void GetLowestLevelNum(BTNode *b,int &num);//��Ҷ�ӽ�����
//��дһ������ʵ�ֶ������ĸ������㣬���ڴ˻��������һ������������¹��ܣ�
//��1�������������

//��2�����H�ڵ�����Һ��ӽڵ�ֵ��

//��3���������������ȣ�

//��4������������Ŀ�ȣ�

//��5������������Ľڵ������

//��6�������������Ҷ�ӽڵ�ĸ�����

//��7���ͷŶ�������

//��������ʽ�������������ű�ʾ
//�������ʽ��������ĿҪ�����
//���������롿A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))
int main(void)
{
    BTNode *b,*t;
    int num1=0,num2=0;
    char s[MaxSize];
    cin>>s;
    CreateBTree(b,s);
    cout<<"(1)BTree:";
    DispBTree(b);
    t=FindNode(b,'H');
    cout<<"\n"<<"(2)the lchild and rchild node of H node:"<<LchildNode(t)->data<<","<<RchildNode(t)->data<<endl;
    cout<<"(3)the depth of BTree:"<<BTHeight(b)<<endl;
    cout<<"(4)the width of BTree:"<<BTWidth(b)<<endl;
    GetNum(b,num1);
    cout<<"(5)the number of nodes:"<<num1<<endl;
    GetLowestLevelNum(b,num2);
    cout<<"(6)the number of Leafnodes:"<<num2<<endl;
    DestoryBTree(b);
    cout<<"(7)Destroy BTree;";
    return 0;
}
void CreateBTree(BTNode *&b,char *str)//������
{
    BTNode *St[MaxSize],*p;//St��˳��ջ
    int top =-1,k,j=0;//top��ջ��ָ��
    //kΪ1ʱ��ʼ�������ӽ��
    //kΪ2ʱ��ʼ�����Һ��ӽ��
    char ch;//chΪ��ʱ����
    ch=str[j];//ch����str�ַ������ַ�
    b=NULL;//��ʼʱ������Ϊ��
    while(ch!='\0')//�����ַ���str
    {
        switch(ch)
        {
            case '(':top++;St[top]=p;k=1;break;
            //ջ��ָ����������ǰ��p��ջ������ʼ�������ӽ��
            case ')':top--;break;//ջ�����������������
            case ',':k=2;break;//��ʼ�����Һ��ӽ��
            default:
                p=(BTNode *)malloc(sizeof(BTNode));//pָ���´����Ľ��
                p->data=ch;
                p->lchild=p->rchild=NULL;
                if(b==NULL)//��bΪ��
                    b=p;//bָ��p��Ϊ���ڵ�
                else
                    {
                        switch(k)
                        {
                            case 1:St[top]->lchild=p;break;//kΪ1��pΪ���ӽ��
                            case 2:St[top]->rchild=p;break;//kΪ2��pΪ�Һ��ӽ��
                        }
                    }
        }
        j++;//j����
        ch=str[j];//����ɨ��str
    }
}
void DestoryBTree(BTNode *&b)//������
{
    if(b!=NULL)
        {
            DestoryBTree(b->lchild);
            DestoryBTree(b->rchild);
            free(b);
        }
}
BTNode *FindNode(BTNode *b,ElemType x)//���ҽ��
{
    BTNode *p;
    if(b==NULL)
        return NULL;
    else if(b->data==x)
        return b;
    else
        {
            p=FindNode(b->lchild,x);//p����b�����ӽ��
            if(p!=NULL)//��p��Ϊ�գ���Ϊ�ҵ�
                return p;//����p
            else//�������ӽ��pΪ�գ�����b���Һ��ӽ��
                return FindNode(b->rchild,x);
        }
}
BTNode *LchildNode(BTNode *p)//���ؽ��p�����ӽ��
{
    return p->lchild;
}
BTNode *RchildNode(BTNode *p)//���ؽ��p���Һ��ӽ��
{
    return p->rchild;
}
int BTWidth(BTNode *b)//����������
{
    if(b==NULL)
        return 0;

    int nLastLevelWidth = 0;//��¼��һ��Ŀ��
    int nTempLastLevelWidth = 0;
    int nCurLevelWidth = 0;//��¼��ǰ��Ŀ��
    int nWidth = 1;//�������Ŀ��

    queue<BTNode *> myQueue;
    myQueue.push(b);//�����ڵ������
    nLastLevelWidth = 1;
    BTNode *pCur = NULL;

    while (!myQueue.empty())//�����в���ʱһֱѭ��
    {
        nTempLastLevelWidth = nLastLevelWidth;  //������һ�����
        while (nTempLastLevelWidth != 0)
        {
            pCur = myQueue.front();//front������ȡ����ͷԪ�ظ�ֵ��pCur
            myQueue.pop();//������ͷԪ�س���

            if (pCur->lchild != NULL)//������Ӳ�Ϊ��
            {
                myQueue.push(pCur->lchild);//�����ӽ���
            }

            if (pCur->rchild != NULL)//����Һ��Ӳ���
            {
                myQueue.push(pCur->rchild);//���Һ��ӽ���
            }

            nTempLastLevelWidth--;//һֱ��������һ�����н�����Ϊֹ
        }

        nCurLevelWidth = myQueue.size();
        //����size��������ǰ���г���
        //��ǰ��Ŀ�Ⱦ͵���Ŀǰ���еĳ���
        //����˵�Ƿǳ��������㷨��
        nWidth = nCurLevelWidth > nWidth ? nCurLevelWidth : nWidth;
        //����ǰ���еĿ����֮ǰ����Ķ�������Ƚ��бȽ�
        //����ǰ��Ƚϴ���ǰ���Ϊ�µĶ��������
        nLastLevelWidth = nCurLevelWidth;
        //����ǰ�����ֵ������һ����� ��������һ��ѭ��
    }
    return nWidth;//ѭ�����������ض��������
}
int BTHeight(BTNode *b)//��߶�
{
    int lchildh,rchildh;
    if(b==NULL)
        return 0;
    else
    {
        lchildh=BTHeight(b->lchild);
        rchildh=BTHeight(b->rchild);
        return (lchildh>rchildh)?(lchildh+1):(rchildh+1);
    }
}
void DispBTree(BTNode *b)//���������
{
    if(b!=NULL)
    {
        cout<<b->data;
        if(b->lchild!=NULL||b->rchild!=NULL)
        {
            cout<<"(";//�к��ӽ��ʱ�����
            DispBTree(b->lchild);//�ݹ鴦��������
            if(b->rchild!=NULL)//���Һ��ӽ��ʱ�����
              cout<<",";
            DispBTree(b->rchild);//�ݹ鴦��������
            cout<<")";//�к��ӽ��ʱ�����
        }
    }
}
void GetNum(BTNode *b,int &num)//����������н�����
{
    if(b!=NULL)
    {
        num++;
        GetNum(b->lchild,num);
        GetNum(b->rchild,num);
    }
}
void GetLowestLevelNum(BTNode *b,int &num)//��Ҷ�ӽ�����
{
    if(b!=NULL)
    {
        if(b->lchild==NULL&&b->rchild==NULL)//��Ҷ�ӽ��
        num++;
        GetLowestLevelNum(b->lchild,num);
        GetLowestLevelNum(b->rchild,num);
    }
}
