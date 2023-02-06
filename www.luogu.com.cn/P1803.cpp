#include <bits/stdc++.h>
using namespace std;

struct Match
{
    int a,b;
} x[1000010];
int n;

bool cmp(const Match& x,const Match& y)
{
    return x.b<=y.b;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i].a>>x[i].b;
    sort(x+1,x+1+n,cmp);
    int last=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(x[i].a>=last)
        {
            last=x[i].b;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}