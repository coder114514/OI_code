#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
int m;

struct Milk
{
    int p;ll a;
}x[2000010];

bool cmp(const Milk& m1,const Milk& m2)
{
    return m1.p<m2.p;
}

int main()
{
    scanf("%lld%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%lld",&x[i].p,&x[i].a);
    }
    sort(x+1,x+1+m,cmp);
    int ans=0;
    for(int i=1;i<=m&&n>0;i++)
    {
        ans+=x[i].p*min(n,x[i].a);
        n=max(0LL,n-x[i].a);
    }
    cout<<ans<<endl;
    return 0;
}