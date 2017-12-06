#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int N=31;
typedef struct BitNode
{
	char value;
	BitNode *lchild,*rchild;
}BitNode,*BiTree;

void CreatTree(BitNode *&root,char *pre,int l1,int r1,char *in,int l2,int r2)
{
	if(l1<=r1&&l2<=r2)
	{
		int key=pre[l1];
		int midIndex=-1;
		for(int i=l2;i<=r2;i++)
		{
			if(in[i]==key)
			{
				midIndex=i;
				break;
			}
		}
		root=(BitNode *)malloc(sizeof(BitNode));
		root->value=key;
		root->lchild=NULL;
		root->rchild=NULL;
		int llen=midIndex-l2;
		CreatTree(root->lchild, pre, l1+1, l1+llen, in, l2, midIndex-1);
		CreatTree(root->rchild, pre, l1+llen+1, r1, in, midIndex+1, r2);
	}
}

void postOrderTraverse(BitNode *&root)
{
	if(root->lchild)
		postOrderTraverse(root->lchild);
	if(root->rchild)
		postOrderTraverse(root->rchild);
	printf("%c",root->value);
}

int main()
{
	char pre[N],in[N];
    scanf("%s",pre);
    scanf("%s",in);
    int len1=strlen(pre);
    int len2=strlen(in);
    BitNode *root=NULL;
    CreatTree(root,pre,0,len1-1,in,0,len2-1);
    postOrderTraverse(root);
    printf("\n");
    return 0;
}

