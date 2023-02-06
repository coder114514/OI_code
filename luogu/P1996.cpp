#include<bits/stdc++.h>
using namespace std;

int n,m;
int nxt[110];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        nxt[i]=(i+1>n?1:i+1);
    }
    int start=1;
    for(int i=1;i<=n;i++)
    {
        if(m==1)
        {
            cout<<i<<" ";
            continue;
        }
        int prev=start,no=nxt[start];
        for(int j=1;j<=m-2;j++)
        {
            prev=no;
            no=nxt[no];
        }
        cout<<no<<" ";
        start=nxt[prev]=nxt[no];
    }
    cout<<endl;
    return 0;
}