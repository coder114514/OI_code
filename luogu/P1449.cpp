#include<bits/stdc++.h>
using namespace std;

int st[110],top;

int main()
{
    char c;
    int n;
    while((c=getchar())!='@')
    {
        if(c>='0'&&c<='9')
        {
            n=n*10+c-'0';
        }
        else if (c=='.')
        {
            st[++top]=n;
            n=0;
        }
        else
        {
            int a=st[top--];
            int b=st[top--];
            if(c=='+')st[++top]=a+b;
            else if(c=='-')st[++top]=b-a;
            else if(c=='*')st[++top]=a*b;
            else if(c=='/')st[++top]=b/a;
        }
    }
    cout<<st[top--]<<endl;
    return 0;
}