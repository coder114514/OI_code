#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,h[310];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>h[i];
    sort(h+1,h+n+1);
    int head=0,tail=n;ll ans=0;
    while(head<tail)
    {
        ans+=(h[tail]-h[head])*(h[tail]-h[head]);
        head++;
        ans+=(h[tail]-h[head])*(h[tail]-h[head]);
        tail--;
    }
    cout<<ans<<endl;
    return 0;
}