//【问题描述】已知A[n]为整数数组，试写出实现下列运算的递归算法：（1）求数组A中的最大整数。（2）求n个整数的和。（3）求n个整数的平均值。
//【输入形式】一维数组的n个元素

//【输出形式】（1）数组A中的最大整数。（2）n个整数的和。（3）求n个整数的平均值。

//【样例输入】1 2 3 4 5
//【样例输出】5  15  3
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
