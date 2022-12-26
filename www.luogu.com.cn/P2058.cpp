#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n;

typedef pair<int,int> pii;

queue<pii> q;
int cnt[N],ans;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int t,k;
        cin>>t>>k;
        for(int j=1;j<=k;j++)
        {
            int x;
            cin>>x;
            q.push(make_pair(x,t));
            if(cnt[x]==0)ans++;
            cnt[x]++;
        }
        while(!q.empty())
        {
            pii p=q.front();
            if(p.second>t-86400&&p.second<=t)
            {
                break;
            }
            q.pop();
            cnt[p.first]--;
            if(cnt[p.first]==0)ans--;
        }
        cout<<ans<<endl;
    }
    return 0;
}
