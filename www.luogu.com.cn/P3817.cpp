#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,x;
ll a[100010];

int main()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++)cin>>a[i];
    ll ans=0;
    for(int i=2;i<=n;i++)
    {
        if(a[i]+a[i-1]>x)
        {
            int delta=a[i]+a[i-1]-x;
            if(a[i]>=delta)a[i]-=delta;
            else a[i-1]-=delta-a[i],a[i]=0;
            ans+=delta;
        }
    }
    cout<<ans<<endl;
    return 0;
}