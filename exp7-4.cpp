#include<iostream>
#include<string>
#include<math.h>
#define MaxSize 1000000000
using namespace std;
//��һ����������������1~n�����Ҹ�ֵ
//���m�ϵ����нڵ���������Ϊ��ȫ������
int main(void)
{
    int n,m;//nΪ�ܽڵ�����mΪ�����ĸ�
    cin>>m>>n;
    if(m<=n&&m>=1&&n<=MaxSize)
    {
        int deep = 0, sum = 0, temp = m;
        //deepΪ�������������
        //sumΪ������������
        //tempΪ��ʱ��������ֵΪm

        for (deep = 0; temp <= n; deep++)
            temp *= 2;
        //����������ȵ�forѭ��
        //��������ø����������ĳ�����ֵ*2����������ֵ���ص�
        //ÿ����2����ȱ�++

        sum = pow(2, deep - 1) - 1;
        //pow(x,y)������������math.hͷ�ļ��ڣ�����x��y���ݡ�xӦ������
        //ͳ�Ƴ�Ҷ�ӽڵ��⣬�����������Ľڵ�����

        int limit = m;
        for (int i = deep - 1; i > 0; i--)
            limit = 2 * limit + 1;
        //limitΪ��ǰ���������ұߵ�Ҷ�ӽ��ֵ

        limit = limit > n ? n : limit;
        //�ж�n����Ƿ��ڸ�������
        //����limitȡֵΪn������ȡֵΪlimit

        sum += limit - temp / 2 + 1;
        //ͬlimitԭ��һ����temp/2Ϊ��ǰ����������ߵ�Ҷ�ӽ��ֵ
        //����Ҷ�ӽ�����

        cout <<sum<<endl;
    }
    return 0;
}
