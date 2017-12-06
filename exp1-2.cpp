#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char a[100];
    int i,flag=1;
    cin>>a;
    int len=strlen(a);
    for(i=0;i<len/2;i++)
    {
        if(a[i]!=a[len-1-i])
            flag=0;
    }
    if(flag)
        cout<<"is plalindrome";
    else
        cout<<"is not plalindrome";
}
