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
void GetLongestStr(SqString s,int &loc,int &maxlen);//���һ����ظ��Ӵ�(BF�㷨)
void GetLongestStr2(SqString s,int &loc,int &maxlen);//���һ����ظ��Ӵ�(KMP�㷨 �ƺ��е�С����)
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
void GetLongestStr(SqString s,int &loc,int &maxlen)//���һ����ظ��Ӵ�
{
    //BF�㷨
    loc=0;
    maxlen=0;
    int length;
    int i,j,k;
    for(i=0;i<s.length;i++)
    {
        j=i+1;
        while(j<=s.length)
        {
            if(s.data[i]==s.data[j])//��ƥ��ɹ�����ʼ����Ӵ�
            {
                length=1;
                for(k=1;s.data[i+k]==s.data[j+k]&&j+k<s.length;k++)//����Ӵ�����
                    length++;
                //��һ���У�i��j��ֵ��û�иı䣬�൱Ư��
                if(maxlen<length)//�ж��Ƿ�Ϊ��ǰ�����
                {
                    loc=i+1;//��¼�Ӵ��ĵ�ǰλ�ã���Ӧ���е�loc���ַ�
                    maxlen=length;//��¼��ǰ�����
                }
                j+=length;//��jֱ�Ӻ��Ƶ���Ӵ�֮������Ƚ�
            }
            else
                j++;//ƥ��ʧ�ܣ�j����һλ
        }
    }
}
void GetLongestStr2(SqString s,int &loc,int &maxlen)////���һ����ظ��Ӵ�(KMP�㷨)
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
            if(j == k - 1 || s.data[i] == s.data[j]){//ģʽƥ��
                ++i;++j;
                next[i] = j;
                if(s.data[i] == s.data[j])
                    length = j - k + 1;
                else
                    length = j - k;
            }
            else
                j = next[j];//ģʽ��������
            if(length > maxlen){
                loc = k+1;    //��¼���ֵ�һ����ظ��Ӵ���λ��
                maxlen = length;  //��¼��ظ��Ӵ��ĳ���
            }
         }
     }
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


