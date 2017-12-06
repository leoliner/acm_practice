#include<iostream>
#include<string.h>
using namespace std;
#define MaxSize 100
typedef struct
{
    char data[MaxSize];
    int length;
}SqString;
void StrAssign(SqString &s,string cstr);//生成串
void DestoryStr(SqString &s);//销毁串
void StrCopy(SqString &s,SqString t);//复制串
bool StrEqual(SqString s,SqString t);//判断串相等
int StrLength(SqString s);//求串长
SqString Concat(SqString s,SqString t);//串的连接
SqString SubStr(SqString s,int i,int j);//返回s从第i个字符开始的由连续j个字符组成的字串
SqString InsStr(SqString s1,int i,SqString s2);//将顺序串s2插入到串s1的第i个位置上
SqString DelStr(SqString s,int i,int j);//子串的删除
SqString RepStr(SqString s,int i,int j,SqString t);//将s从i开始j个字符的子串用t替换
void DispStr(SqString s);//输出串
int BF(SqString s,SqString t);//暴力穷举算法
void GetNext(SqString s,int next[]);//求next数组
int KMPIndex(SqString s,SqString t,int next[]);//KMP算法
void GetNextval(SqString t,int nextval[]);//求nextval数组
int KMPIndex1(SqString s,SqString t,int nextval[]);//改进的KMP算法
int main(void)
{
    string a,b;
    SqString s,t;
    int next[MaxSize],nextval[MaxSize];
    cin>>a>>b;
    StrAssign(s,a);
    StrAssign(t,b);
    cout<<"The index of string t in string s by using Brute-Force algorithm is: "<<BF(s,t)<<endl;
    cout<<"The next array of t is:"<<endl;
    GetNext(t,next);
    cout<<"The index of string t in string s by using KMP algorithm is: "<<KMPIndex(s,t,next)<<endl;
    cout<<"The nextval array of t is:"<<endl;
    GetNextval(t,nextval);
    cout<<"The index of string t in string s by using improved KMP algorithm is: "<<KMPIndex1(s,t,nextval)<<endl;
    return 0;
}
int BF(SqString s,SqString t)//暴力穷举算法
{
    int i=0,j=0;
    while(i<s.length && j<t.length)//两个串均没有扫描完时循环
    {
        if(s.data[i]==t.data[j])
            {
                i++;j++;
            }
        else
            {
                i=i-j+1;
                j=0;
            }
    }
    if(j>=t.length)
        return (i-t.length);
    else
        return -1;
}
void GetNext(SqString t,int next[])//求next数组
{
    int j,k;
    j=0;k=-1;
    next[0]=-1;
    while(j<t.length-1)
    {
        if(k==-1 || t.data[j]==t.data[k])
        {
            j++;k++;
            next[j]=k;
        }
        else
            k=next[k];
    }
    for(int i=0;i<=j;i++)
        cout<<next[i]<<" ";
    cout<<"\n";
}
int KMPIndex(SqString s,SqString t,int next[])//KMP算法
{
    int i=0,j=0;
    while(i<s.length &&j<t.length)
    {
        if(j==-1 || s.data[i]==t.data[j])
        {
            i++;j++;
        }
        else j=next[j];//i不变，j后退
    }
    if(j>=t.length)
        return i-t.length;
    else
        return -1;
}
void GetNextval(SqString t,int nextval[])//求nextval数组
{
    int j=0,k=-1;
    nextval[0]=-1;
    while(j<t.length)
    {
        if(k==-1 || t.data[j]==t.data[k])
        {
            j++;k++;
            if(t.data[j]!=t.data[k])
                nextval[j]=k;
            else
                nextval[j]=nextval[k];
        }
        else
            k=nextval[k];
    }
    for(int i=0;i<j;i++)
        cout<<nextval[i]<<" ";
    cout<<"\n";
}
int KMPIndex1(SqString s,SqString t,int nextval[])//改进的KMP算法
{
    int i=0,j=0;
    while(j<t.length)
    {
        if(j==-1 || s.data[i]==t.data[j])
        {
            i++;j++;
        }
        else
            j=nextval[j];
    }
    if(j>=t.length)
        return i-t.length;
    else
        return -1;
}
void StrAssign(SqString &s,string cstr)//生成串
{
    int i;
    for(i=0;cstr[i]!='\0';i++)
    {
        s.data[i]=cstr[i];
    }
    s.length=i;
}
void DestoryStr(SqString &s)//销毁串
{

}
void StrCopy(SqString &s,SqString t)//复制串
{
    int i;
    for(i=0;i<s.length;i++)
    {
        s.data[i]=t.data[i];
    }
    s.length=t.length;
}
bool StrEqual(SqString s,SqString t)//判断串相等
{
    bool same=true;
    int i;
    if(s.length!=t.length)
        same=false;
    else{
        for(i=0;i<s.length;i++)
        {
            if(s.data[i]!=t.data[i])
            {
                same=false;
                break;
            }
        }
    }
    return same;
}
int StrLength(SqString s)//求串长
{
    return s.length;
}
SqString Concat(SqString s,SqString t)//串的连接
{
    SqString str;//定义结果串
    int i;
    str.length=s.length+t.length;
    for(i=0;i<s.length;i++)
        str.data[i]=s.data[i];
    for(i=0;i<t.length;i++)
        str.data[s.length+i]=t.data[i];
    return str;
}
SqString SubStr(SqString s,int i,int j)//返回s从第i个字符开始的由连续j个字符组成的字串
{
    int k;
    SqString str;
    str.length=0;
    if(i<=0||i>s.length||j<0||i+j-1>s.length)
        return str;//参数不正确时返回空串
    for(k=i-1;k<i+j-1;k++)
        str.data[k-i+1]=s.data[k];
    str.length=j;
    return str;
}
SqString InsStr(SqString s1,int i,SqString s2)//将顺序串s2插入到串s1的第i个位置上
{
    int j;
    SqString str;
    str.length=0;
    if(i<=0||i>s1.length+1)
        return str;
    for(j=0;j<i-1;j++)
        str.data[j]=s1.data[j];
    for(j=0;j<s2.length;j++)
        str.data[i+j-1]=s2.data[j];
    for(j=i-1;j<s1.length;j++)
        str.data[s2.length+j]=s1.data[j];
    str.length=s1.length+s2.length;
    return str;
}
SqString DelStr(SqString s,int i,int j)//子串的删除
{
    int k;
    SqString str;
    str.length=0;
    if(i<=0||i>s.length||i+j>s.length+1)
        return str;
    for(k=0;k<i-1;k++)
        str.data[k]=s.data[k];
    for(k=i+j-1;k<s.length;k++)
        str.data[k-j]=s.data[k];
    str.length=s.length-j;
    return str;
}
SqString RepStr(SqString s,int i,int j,SqString t)//将s从i开始j个字符的子串用t替换
{
    int k;
    SqString str;
    str.length=0;
    if(i<=0||i>s.length||i+j-1>s.length)
        return str;
    for(k=0;k<i-1;k++)
        str.data[k]=s.data[k];
    for(k=0;k<t.length;k++)
        str.data[i+k-1]=t.data[k];
    for(k=i+j-1;k<s.length;k++)
        str.data[t.length+k-j]=s.data[k];
    str.length=s.length-j+t.length;
    return str;
}
void DispStr(SqString s)//输出串
{
    int i;
    if(s.length>0)
    {
        for(i=0;i<s.length;i++)
            cout<<s.data[i];
        cout<<"\n";
    }
}

