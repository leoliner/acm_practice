#include<iostream>
#include<stdio.h>
using namespace std;
#define MAXSIZE 100
typedef struct
{
	int data[MAXSIZE];
	int len;
}sqlist;
int main()
{
	sqlist A;
	int i=0,j=0,k=0,temp=0;
	char opt;
	A.len=0;
    while(1){
        cin>>A.data[k];
        scanf("%c",&opt);
        k++;
        A.len++;
        if(opt=='\n')break;
    }//输入一串按顺序结构且互不相等的整数
   i=-1;
   for(j=0;j<=A.len-1;j++)
     {
         if(A.data[j]%2==1)//当j指向奇数时
         {
             i++;//奇数区间个数加一
             temp=A.data[j];//保存该奇数值
             for(k=j;k<A.len;k++)//将该奇数从顺序表中删除，后面的值往前移
                 A.data[k]=A.data[k+1];
                 A.len--;
             for(k=A.len;k>i;k--)//将i处元素及后面元素后移一个单位
                 A.data[k]=A.data[k-1];
                 A.data[i]=temp;//将该奇数插入位置i
                 A.len++;
         }
     }
    for(i=0;i<A.len;i++)
        cout<<A.data[i]<<" ";
	return 0;

}
