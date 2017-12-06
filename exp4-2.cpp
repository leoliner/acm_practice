#include<iostream>
#include<string.h>
using namespace std;
#define MaxSize 100
typedef struct
{
    char data[MaxSize];
    int length;
}SqString;
void StrAssign(SqString &s,string cstr);//���ɴ�
void DestoryStr(SqString &s);//���ٴ�
void StrCopy(SqString &s,SqString t);//���ƴ�
bool StrEqual(SqString s,SqString t);//�жϴ����
int StrLength(SqString s);//�󴮳�
SqString Concat(SqString s,SqString t);//��������
SqString SubStr(SqString s,int i,int j);//����s�ӵ�i���ַ���ʼ��������j���ַ���ɵ��ִ�
SqString InsStr(SqString s1,int i,SqString s2);//��˳��s2���뵽��s1�ĵ�i��λ����
SqString DelStr(SqString s,int i,int j);//�Ӵ���ɾ��
SqString RepStr(SqString s,int i,int j,SqString t);//��s��i��ʼj���ַ����Ӵ���t�滻
void DispStr(SqString s);//�����
int BF(SqString s,SqString t);//��������㷨
void GetNext(SqString s,int next[]);//��next����
int KMPIndex(SqString s,SqString t,int next[]);//KMP�㷨
void GetNextval(SqString t,int nextval[]);//��nextval����
int KMPIndex1(SqString s,SqString t,int nextval[]);//�Ľ���KMP�㷨
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
int BF(SqString s,SqString t)//��������㷨
{
    int i=0,j=0;
    while(i<s.length && j<t.length)//��������û��ɨ����ʱѭ��
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
void GetNext(SqString t,int next[])//��next����
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
int KMPIndex(SqString s,SqString t,int next[])//KMP�㷨
{
    int i=0,j=0;
    while(i<s.length &&j<t.length)
    {
        if(j==-1 || s.data[i]==t.data[j])
        {
            i++;j++;
        }
        else j=next[j];//i���䣬j����
    }
    if(j>=t.length)
        return i-t.length;
    else
        return -1;
}
void GetNextval(SqString t,int nextval[])//��nextval����
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
int KMPIndex1(SqString s,SqString t,int nextval[])//�Ľ���KMP�㷨
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
void StrAssign(SqString &s,string cstr)//���ɴ�
{
    int i;
    for(i=0;cstr[i]!='\0';i++)
    {
        s.data[i]=cstr[i];
    }
    s.length=i;
}
void DestoryStr(SqString &s)//���ٴ�
{

}
void StrCopy(SqString &s,SqString t)//���ƴ�
{
    int i;
    for(i=0;i<s.length;i++)
    {
        s.data[i]=t.data[i];
    }
    s.length=t.length;
}
bool StrEqual(SqString s,SqString t)//�жϴ����
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
int StrLength(SqString s)//�󴮳�
{
    return s.length;
}
SqString Concat(SqString s,SqString t)//��������
{
    SqString str;//��������
    int i;
    str.length=s.length+t.length;
    for(i=0;i<s.length;i++)
        str.data[i]=s.data[i];
    for(i=0;i<t.length;i++)
        str.data[s.length+i]=t.data[i];
    return str;
}
SqString SubStr(SqString s,int i,int j)//����s�ӵ�i���ַ���ʼ��������j���ַ���ɵ��ִ�
{
    int k;
    SqString str;
    str.length=0;
    if(i<=0||i>s.length||j<0||i+j-1>s.length)
        return str;//��������ȷʱ���ؿմ�
    for(k=i-1;k<i+j-1;k++)
        str.data[k-i+1]=s.data[k];
    str.length=j;
    return str;
}
SqString InsStr(SqString s1,int i,SqString s2)//��˳��s2���뵽��s1�ĵ�i��λ����
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
SqString DelStr(SqString s,int i,int j)//�Ӵ���ɾ��
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
SqString RepStr(SqString s,int i,int j,SqString t)//��s��i��ʼj���ַ����Ӵ���t�滻
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
void DispStr(SqString s)//�����
{
    int i;
    if(s.length>0)
    {
        for(i=0;i<s.length;i++)
            cout<<s.data[i];
        cout<<"\n";
    }
}

