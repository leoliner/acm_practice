//�������������趨��������B[m+1][n+1]�����������з����϶�����С�����˳�����������ͱ���x�е�������B�д��ڡ�
//                        �����һ���㷨���ҳ�һ������B[i][j]=x��i��jֵ��
//��������ʽ��һ����ά����, һ��xֵ(�����xֵ�м��Կո���Ϊ�ָ���)
//�������ʽ��x�ڶ�ά�����λ�ã�i��j��ֵ
//���������롿1 2 3;4 5 6;7 8 9 5
//�����������i=2 j=2
#include<iostream>
#include<stdio.h>
using namespace std;
#define MaxSize 100
int main(void)
{
    //��������Ҫ���ҵ�Ԫ��x
    //x�����ھ�������i�е�j+1����
    int i=0,j=0,x;
    int a[MaxSize][MaxSize];
    char c;
    do
        {
            scanf("%d%c",&a[i][j],&c);
            if(c==';')
            {
                i++;
                j=0;
            }
            else if(c!='\n')
                j++;
        }while(c!='\n');
    for(int m=0;m<=i;m++)
        for(int n=0;n<=j-1;n++)
    {
        if(a[m][n]==a[i][j])
            cout<<"i="<<m+1<<" j="<<n+1;
    }
    return 0;
}
