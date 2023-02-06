#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=150009;

struct Task
{
    ll t,d;
    bool operator<(const Task&o) const
    {
        return d<o.d;
    }
} task[N];

int n,T;
ll f[5009][5009];

void solveDP()
{
    sort(task+1,task+n+1);
    T=task[n].d;
    for(int i=1;i<=n;i++)
    {
        for(ll t=task[i].t;t<=T;t++)
        {
            f[i][t]=max(f[i-1][t],f[i-1][min(t,task[i].d)-task[i].t]+1);
        }
    }
    cout<<f[n][T]<<endl;
}

int main()
{
    freopen("schedule.in","r",stdin);
    freopen("schedule.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>task[i].t>>task[i].d;
    sort(task+1,task+n+1);
    priority_queue<ll> q;
    ll t=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!q.empty()&&t+task[i].t>task[i].d)
        {
            ll max_=q.top();
            if(task[i].t>max_)continue;
            t-=max_;
            ans--;
            q.pop();
        }
        t+=task[i].t;
        q.push(task[i].t);
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}