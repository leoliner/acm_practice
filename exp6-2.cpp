//��������������֪A[n]Ϊ�������飬��д��ʵ����������ĵݹ��㷨����1��������A�е������������2����n�������ĺ͡���3����n��������ƽ��ֵ��
//��������ʽ��һά�����n��Ԫ��

//�������ʽ����1������A�е������������2��n�������ĺ͡���3����n��������ƽ��ֵ��

//���������롿1 2 3 4 5
//�����������5  15  3
#include<iostream>
#include<stdio.h>
using namespace std;
int GetMax(int *a,int max,int n);
int GetSum(int *a,int n);
double GetAve(int *a,int n);
int main(void)
{
    int n=0,max=0,sum=0;
    double ave=0;
    int a[1000];
    char x;
    do
        {
            scanf("%d%c",&a[n],&x);
            n++;
        }while(x!='\n');
    n--;
    max=GetMax(a,0,n);
    sum=GetSum(a,n);
    ave=GetAve(a,n);
    cout<<max<<" "<<sum<<" "<<ave<<endl;
    return 0;
}
int GetMax(int *a,int max,int n)
{
    if(n==-1)
        return max;
    else
    {
        if(max<a[n])
        {
            max=a[n];
            return GetMax(a,max,--n);
        }
        else
            return GetMax(a,max,--n);
    }
}
int GetSum(int *a,int n)
{
        if(n==-1)
          return 0;
        else
          return a[n]+GetSum(a,--n);
}
double GetAve(int *a,int n)
{
        return 1.0*(GetSum(a,n))/(n+1);
}
