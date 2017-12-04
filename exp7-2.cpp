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
void CreateBTree(BTNode *&b,char *str);//生成树
void DestoryBTree(BTNode *&b);//销毁树
BTNode *FindNode(BTNode *b,ElemType x);//查找结点
BTNode *LchildNode(BTNode *p);//返回结点p的左孩子结点
BTNode *RchildNode(BTNode *p);//返回结点p的右孩子结点
int BTHeight(BTNode *b);//求二叉树高度
int BTWidth(BTNode *b);//求二叉树宽度
void DispBTree(BTNode *b);//输出二叉树
void GetNum(BTNode *b,int &num);//求二叉树所有结点个数
void GetLowestLevelNum(BTNode *b,int &num);//求叶子结点个数
void ShowAllLeaves(BTNode *b);//输出所有叶子结点
void ShowAll_L_to_H_Paths(BTNode *b,stack<BTNode *>myStack);//输出所有从叶子节点到根节点的路径
void GetLongestPath(BTNode *b,queue<BTNode *>myQueue,int &PathLength,stack<BTNode *>&LongestStack,int &LongestPath);//输出从叶子节点到根节点的最长路径
//设计一个程序完成如下功能：

//（1）输出所有的叶子节点；

//（2）输出所有从叶子节点到根节点的路径；

//（3）输出（2）中的第一条最长的路径。

//【输入形式】

//二叉树的括号表示

//【输出形式】

//按要求输出各个小题的结果

//【样例输入】

//A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))

//【样例输出】

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
void CreateBTree(BTNode *&b,char *str)//生成树
{
    BTNode *St[MaxSize],*p;//St是顺序栈
    int top =-1,k,j=0;//top是栈顶指针
    //k为1时开始处理左孩子结点
    //k为2时开始处理右孩子结点
    char ch;//ch为临时变量
    ch=str[j];//ch储存str字符串中字符
    b=NULL;//初始时二叉树为空
    while(ch!='\0')//遍历字符串str
    {
        switch(ch)
        {
            case '(':top++;St[top]=p;k=1;break;
            //栈顶指针自增，先前的p进栈，并开始处理左孩子结点
            case ')':top--;break;//栈顶结点的子树处理完毕
            case ',':k=2;break;//开始处理右孩子结点
            default:
                p=(BTNode *)malloc(sizeof(BTNode));//p指向新创建的结点
                p->data=ch;
                p->lchild=p->rchild=NULL;
                if(b==NULL)//若b为空
                    b=p;//b指向p，为根节点
                else
                    {
                        switch(k)
                        {
                            case 1:St[top]->lchild=p;break;//k为1，p为左孩子结点
                            case 2:St[top]->rchild=p;break;//k为2，p为右孩子结点
                        }
                    }
        }
        j++;//j自增
        ch=str[j];//继续扫描str
    }
}
void DestoryBTree(BTNode *&b)//销毁树
{
    if(b!=NULL)
        {
            DestoryBTree(b->lchild);
            DestoryBTree(b->rchild);
            free(b);
        }
}
BTNode *FindNode(BTNode *b,ElemType x)//查找结点
{
    BTNode *p;
    if(b==NULL)
        return NULL;
    else if(b->data==x)
        return b;
    else
        {
            p=FindNode(b->lchild,x);//p查找b的左孩子结点
            if(p!=NULL)//若p不为空，即为找到
                return p;//返回p
            else//否则左孩子结点p为空，查找b的右孩子结点
                return FindNode(b->rchild,x);
        }
}
BTNode *LchildNode(BTNode *p)//返回结点p的左孩子结点
{
    return p->lchild;
}
BTNode *RchildNode(BTNode *p)//返回结点p的右孩子结点
{
    return p->rchild;
}
int BTWidth(BTNode *b)//求二叉树宽度
{
    if(b==NULL)
        return 0;

    int nLastLevelWidth = 0;//记录上一层的宽度
    int nTempLastLevelWidth = 0;
    int nCurLevelWidth = 0;//记录当前层的宽度
    int nWidth = 1;//二叉树的宽度

    queue<BTNode *> myQueue;
    myQueue.push(b);//将根节点入队列
    nLastLevelWidth = 1;
    BTNode *pCur = NULL;

    while (!myQueue.empty())//当队列不空时一直循环
    {
        nTempLastLevelWidth = nLastLevelWidth;  //保存上一级宽度
        while (nTempLastLevelWidth != 0)
        {
            pCur = myQueue.front();//front函数读取队列头元素赋值给pCur
            myQueue.pop();//将队列头元素出队

            if (pCur->lchild != NULL)//结点左孩子不为空
            {
                myQueue.push(pCur->lchild);//将左孩子进队
            }

            if (pCur->rchild != NULL)//结点右孩子不空
            {
                myQueue.push(pCur->rchild);//将右孩子进队
            }

            nTempLastLevelWidth--;//一直遍历到上一层所有结点出队为止
        }

        nCurLevelWidth = myQueue.size();
        //调用size函数，求当前队列长度
        //当前层的宽度就等于目前队列的长度
        //可以说是非常鸡贼的算法了
        nWidth = nCurLevelWidth > nWidth ? nCurLevelWidth : nWidth;
        //将当前队列的宽度与之前储存的二叉树宽度进行比较
        //若当前宽度较大，则当前宽度为新的二叉树宽度
        nLastLevelWidth = nCurLevelWidth;
        //将当前级宽度值赋给上一级宽度 ，进行下一次循环
    }
    return nWidth;//循环结束，返回二叉树宽度
}
int BTHeight(BTNode *b)//求高度
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
void DispBTree(BTNode *b)//输出二叉树
{
    if(b!=NULL)
    {
        cout<<b->data;
        if(b->lchild!=NULL||b->rchild!=NULL)
        {
            cout<<"(";//有孩子结点时输出（
            DispBTree(b->lchild);//递归处理左子树
            if(b->rchild!=NULL)//有右孩子结点时输出，
              cout<<",";
            DispBTree(b->rchild);//递归处理右子树
            cout<<")";//有孩子结点时输出）
        }
    }
}
void GetNum(BTNode *b,int &num)//求二叉树所有结点个数
{
    if(b!=NULL)
    {
        num++;
        GetNum(b->lchild,num);
        GetNum(b->rchild,num);
    }
}
void GetLowestLevelNum(BTNode *b,int &num)//求叶子结点个数
{
    if(b!=NULL)
    {
        if(b->lchild==NULL&&b->rchild==NULL)//是叶子结点
        num++;
        GetLowestLevelNum(b->lchild,num);
        GetLowestLevelNum(b->rchild,num);
    }
}
void ShowAllLeaves(BTNode *b)//输出所有叶子结点
{
    if(b!=NULL)
    {
        if(b->lchild==NULL&&b->rchild==NULL)
            cout<<b->data<<" ";
        ShowAllLeaves(b->lchild);
        ShowAllLeaves(b->rchild);
    }
}
void ShowAll_L_to_H_Paths(BTNode *b,stack<BTNode *>myStack)//输出所有从叶子节点到根节点的路径
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
void GetLongestPath(BTNode *b,queue<BTNode *>myQueue,int &PathLength,stack<BTNode *>&LongestStack,int &LongestPath)//输出从叶子节点到根节点的最长路径
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
