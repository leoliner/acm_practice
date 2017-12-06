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
void GetLongestStr(SqString s,int &loc,int &maxlen);//求第一个最长重复子串(BF算法)
void GetLongestStr2(SqString s,int &loc,int &maxlen);//求第一个最长重复子串(KMP算法 似乎有点小问题)
int main(void)
{
    string a;
    int loc,maxlen;
    cin>>a;
    SqString s,t;
    StrAssign(s,a);
    GetLongestStr(s,loc,maxlen);
    t=SubStr(s,loc,maxlen);
    DispStr(t);
    //GetLongestStr2(s,loc,maxlen);
    //t=SubStr(s,loc,maxlen);
    //DispStr(t);
    return 0;
}
void GetLongestStr(SqString s,int &loc,int &maxlen)//求第一个最长重复子串
{
    //BF算法
    loc=0;
    maxlen=0;
    int length;
    int i,j,k;
    for(i=0;i<s.length;i++)
    {
        j=i+1;
        while(j<=s.length)
        {
            if(s.data[i]==s.data[j])//若匹配成功，开始求最长子串
            {
                length=1;
                for(k=1;s.data[i+k]==s.data[j+k]&&j+k<s.length;k++)//求最长子串长度
                    length++;
                //这一步中，i、j的值并没有改变，相当漂亮
                if(maxlen<length)//判断是否为当前最长长度
                {
                    loc=i+1;//记录子串的当前位置，对应串中第loc个字符
                    maxlen=length;//记录当前最长长度
                }
                j+=length;//将j直接后移到最长子串之后继续比较
            }
            else
                j++;//匹配失败，j后移一位
        }
    }
}
void GetLongestStr2(SqString s,int &loc,int &maxlen)////求第一个最长重复子串(KMP算法)
{
     int i,j,k,length;
     length = 0;
     maxlen = 0;
     int next[MaxSize];
     for(k = 1; k <= s.length; ++k){
        i = k;
        j = k - 1;
        next[k] = k - 1;
        while(i <= s.length){
            if(j == k - 1 || s.data[i] == s.data[j]){//模式匹配
                ++i;++j;
                next[i] = j;
                if(s.data[i] == s.data[j])
                    length = j - k + 1;
                else
                    length = j - k;
            }
            else
                j = next[j];//模式串向右移
            if(length > maxlen){
                loc = k+1;    //记录出现第一个最长重复子串的位置
                maxlen = length;  //记录最长重复子串的长度
            }
         }
     }
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


