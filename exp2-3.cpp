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
    }//����һ����˳��ṹ�һ�����ȵ�����
   i=-1;
   for(j=0;j<=A.len-1;j++)
     {
         if(A.data[j]%2==1)//��jָ������ʱ
         {
             i++;//�������������һ
             temp=A.data[j];//���������ֵ
             for(k=j;k<A.len;k++)//����������˳�����ɾ���������ֵ��ǰ��
                 A.data[k]=A.data[k+1];
                 A.len--;
             for(k=A.len;k>i;k--)//��i��Ԫ�ؼ�����Ԫ�غ���һ����λ
                 A.data[k]=A.data[k-1];
                 A.data[i]=temp;//������������λ��i
                 A.len++;
         }
     }
    for(i=0;i<A.len;i++)
        cout<<A.data[i]<<" ";
	return 0;

}
