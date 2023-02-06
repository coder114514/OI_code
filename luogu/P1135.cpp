#include<bits/stdc++.h>
using namespace std;

int n,a,b;
int k[209],ans[209];

void bfs()
{
    for(int i=1;i<=n;i++)ans[i]=-1;
    queue<int> q;
    ans[a]=0;
    q.push(a);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(x+k[x]>=1&&x+k[x]<=n&&ans[x+k[x]]==-1)
        {
            q.push(x+k[x]);
            ans[x+k[x]]=ans[x]+1;
        }
        if(x-k[x]>=1&&x-k[x]<=n&&ans[x-k[x]]==-1)
        {
            q.push(x-k[x]);
            ans[x-k[x]]=ans[x]+1;
        }
        if(ans[b]!=-1)break;
    }
    cout<<ans[b]<<endl;
}

int main()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)cin>>k[i];
    bfs();
    return 0;
}