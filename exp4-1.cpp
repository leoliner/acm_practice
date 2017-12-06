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
int main(void)
{
    SqString s,s1,s2,s3,s4;
    string a,b;
    cin>>a>>b;
    StrAssign(s,a);
    StrAssign(s1,b);
    cout<<"The string s is: ";
    DispStr(s);
    cout<<"The length of this string is: "<<StrLength(s)<<endl;
    s2=InsStr(s,9,s1);
    cout<<"The string s2 after inserting string s1 into the 9th place of string s is:"<<endl;
    DispStr(s2);
    s2=DelStr(s,2,5);
    cout<<"The string s2 after deleting 5 elements of string s beginning from its 2th place is:"<<endl;
    DispStr(s2);
    s2=RepStr(s,2,5,s1);
    cout<<"The string s2 after replacing 5 elements of string s with string s1 beginning from its 2th place is:"<<endl;
    DispStr(s2);
    s3=SubStr(s,2,10);
    cout<<"The string s3 after extracting 10 elements from string s beginning from its 2th place is:"<<endl;
    DispStr(s3);
    s4=Concat(s1,s2);
    cout<<"The string s4 after concatenating string s1 with string s2 is:"<<endl;
    DispStr(s4);
    return 0;
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
