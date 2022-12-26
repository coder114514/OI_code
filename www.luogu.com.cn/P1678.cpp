#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int m,n,a[100010],b[100010];

int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    sort(a+1,a+1+m);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int pos=lower_bound(a+1,a+1+m,b[i])-a;
        if(pos==1)ans+=a[1]-b[i];
        else if(pos==m+1)ans+=b[i]-a[m];
        else ans+=(min(b[i]-a[pos-1],a[pos]-b[i]));
    }
    cout<<ans<<endl;
    return 0;
}