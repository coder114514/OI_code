#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=3e4+10;

int w,n,p[N];

int main()
{
    cin>>w>>n;
    for(int i=1;i<=n;i++)cin>>p[i];
    sort(p+1,p+1+n);
    int ans=0,head=1,tail=n;
    while(head<tail)
    {
        if(p[head]+p[tail]<=w)head++;
        ans++;
        tail--;
    }
    if(head==tail)ans++;
    cout<<ans<<endl;
    return 0;
}