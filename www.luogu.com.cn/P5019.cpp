#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,d[100010],a[100010];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&d[i]);
        a[i]=d[i]-d[i-1];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>0)ans+=a[i];
    }
    cout<<ans<<endl;
    return 0;
}