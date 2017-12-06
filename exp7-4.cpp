#include<iostream>
#include<string>
#include<math.h>
#define MaxSize 1000000000
using namespace std;
//设一特殊二叉树，结点以1~n从左到右赋值
//求根m上的所有节点数。该树为完全二叉树
int main(void)
{
    int n,m;//n为总节点数，m为子树的根
    cin>>m>>n;
    if(m<=n&&m>=1&&n<=MaxSize)
    {
        int deep = 0, sum = 0, temp = m;
        //deep为二叉树子树深度
        //sum为二叉树结点个数
        //temp为临时变量，初值为m

        for (deep = 0; temp <= n; deep++)
            temp *= 2;
        //计算子树深度的for循环
        //巧妙的利用该特殊二叉树某个结点值*2等于左子树值的特点
        //每乘以2，深度便++

        sum = pow(2, deep - 1) - 1;
        //pow(x,y)函数，包含在math.h头文件内，返回x的y次幂。x应大于零
        //统计除叶子节点外，满二叉子树的节点总数

        int limit = m;
        for (int i = deep - 1; i > 0; i--)
            limit = 2 * limit + 1;
        //limit为当前子树的最右边的叶子结点值

        limit = limit > n ? n : limit;
        //判断n结点是否在该子树内
        //若在limit取值为n，否则取值为limit

        sum += limit - temp / 2 + 1;
        //同limit原理一样，temp/2为当前子树的最左边的叶子结点值
        //计算叶子结点个数

        cout <<sum<<endl;
    }
    return 0;
}
