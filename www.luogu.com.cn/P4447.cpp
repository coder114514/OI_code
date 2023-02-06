#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=100010;

int n,a[N],q[N],sum[N],nGroups;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        int pos=lower_bound(q+1,q+1+nGroups,a[i]-1)-q;
        if(pos<=nGroups&&q[pos]==a[i]-1)
        {
            q[pos]=a[i];
            sum[pos]++;
            while(pos<nGroups&&(q[pos]>q[pos+1]||(q[pos]==q[pos+1]&&sum[pos]>sum[pos+1])))
            {
                swap(q[pos],q[pos+1]);
                swap(sum[pos],sum[pos+1]);
                pos++;
            }
        }
        else
        {
            q[++nGroups]=a[i];
            sum[nGroups]=1;
            int pos=nGroups;
            while(pos>1&&(q[pos]<q[pos-1]||(q[pos]==q[pos-1]&&sum[pos]<sum[pos-1])))
            {
                swap(q[pos],q[pos-1]);
                swap(sum[pos],sum[pos-1]);
                pos--;
            }
        }
    }
    int ans=1<<30;
    for(int i=1;i<=nGroups;i++)ans=min(ans,sum[i]);
    cout<<ans<<endl;
    return 0;
}