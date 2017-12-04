#include<iostream>
#include<malloc.h>
#include<queue>
#include<stack>
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
void ShowAllLeaves(BTNode *b);//�������Ҷ�ӽ��
void ShowAll_L_to_H_Paths(BTNode *b,stack<BTNode *>myStack);//������д�Ҷ�ӽڵ㵽���ڵ��·��
void GetLongestPath(BTNode *b,queue<BTNode *>myQueue,int &PathLength,stack<BTNode *>&LongestStack,int &LongestPath);//�����Ҷ�ӽڵ㵽���ڵ���·��
//���һ������������¹��ܣ�

//��1��������е�Ҷ�ӽڵ㣻

//��2��������д�Ҷ�ӽڵ㵽���ڵ��·����

//��3�������2���еĵ�һ�����·����

//��������ʽ��

//�����������ű�ʾ

//�������ʽ��

//��Ҫ���������С��Ľ��

//���������롿

//A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))

//�����������

//(1)all the leaf nodes are:D J L N F
//(2)all the paths from leaf node to root node are:

//D B A ;

//F C A;

//I G C A;

//J H E B A;

//L K H E B A;

//N M K H E B A;

//(3)the first longest path of the result of problem (2) is:

//N M K H E B A
int main(void)
{
    BTNode *b,*t;
    stack<BTNode *>myStack;
    stack<BTNode *>LongestStack;
    queue<BTNode *>myQueue;
    BTNode *pCur=NULL;
    int PathLength=0,LongestPath=0;
    char s[MaxSize];
    cin>>s;
    CreateBTree(b,s);
    cout<<"(1)all the leaf nodes are:";
    ShowAllLeaves(b);
    cout<<"\n"<<"(2)all the paths from leaf node to root node are:"<<endl;
    ShowAll_L_to_H_Paths(b,myStack);
    cout<<"(3)the first longest path of the result of problem (2) is:"<<endl;
    GetLongestPath(b,myQueue,PathLength,LongestStack,LongestPath);
    while(!LongestStack.empty())
            {
                pCur=LongestStack.top();
                LongestStack.pop();
                cout<<pCur->data<<" ";
            }
    DestoryBTree(b);
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
void ShowAllLeaves(BTNode *b)//�������Ҷ�ӽ��
{
    if(b!=NULL)
    {
        if(b->lchild==NULL&&b->rchild==NULL)
            cout<<b->data<<" ";
        ShowAllLeaves(b->lchild);
        ShowAllLeaves(b->rchild);
    }
}
void ShowAll_L_to_H_Paths(BTNode *b,stack<BTNode *>myStack)//������д�Ҷ�ӽڵ㵽���ڵ��·��
{
    BTNode *pCur = NULL;
    if(b!=NULL)
    {
        if(b->lchild==NULL&&b->rchild==NULL)
        {
           myStack.push(b);
            while(!myStack.empty())
            {
                pCur=myStack.top();
                myStack.pop();
                cout<<pCur->data;
                if(myStack.empty())
                    cout<<";\n";
                else
                    cout<<" ";
            }
        }
       else
       {
           myStack.push(b);
           ShowAll_L_to_H_Paths(b->lchild,myStack);
           ShowAll_L_to_H_Paths(b->rchild,myStack);
       }
    }
}
void GetLongestPath(BTNode *b,queue<BTNode *>myQueue,int &PathLength,stack<BTNode *>&LongestStack,int &LongestPath)//�����Ҷ�ӽڵ㵽���ڵ���·��
{
    BTNode *pCur = NULL;
    if(b!=NULL)
    {
        if(b->lchild==NULL&&b->rchild==NULL)
        {
           myQueue.push(b);
           PathLength++;
           if(PathLength>LongestPath)
           {
               while(!LongestStack.empty())
                LongestStack.pop();
               while(!myQueue.empty())
               {
                   pCur=myQueue.front();
                   myQueue.pop();
                   LongestStack.push(pCur);
               }
           }
           LongestPath=PathLength;
           PathLength=0;
        }
       else
       {
           myQueue.push(b);
           GetLongestPath(b->lchild,myQueue,++PathLength,LongestStack,LongestPath);
           GetLongestPath(b->rchild,myQueue,++PathLength,LongestStack,LongestPath);
       }
    }
}
