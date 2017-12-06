//【问题描述】设定整数数组B[m+1][n+1]的数据在行列方向上都按从小到大的顺序排序，且整型变量x中的数据在B中存在。
//                        试设计一个算法，找出一对满足B[i][j]=x的i，j值。
//【输入形式】一个二维数组, 一个x值(数组和x值中间以空格作为分隔符)
//【输出形式】x在二维数组的位置，i和j的值
//【样例输入】1 2 3;4 5 6;7 8 9 5
//【样例输出】i=2 j=2
#include<iostream>
#include<stdio.h>
using namespace std;
#define MaxSize 100
int main(void)
{
    //输入矩阵和要查找的元素x
    //x储存在矩阵最后第i行的j+1列中
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
