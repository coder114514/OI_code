#include<bits/stdc++.h>
using namespace std;

int n,m,t;
int sx,sy,fx,fy;
bool mp[11][11];

bool v[11][11];
const int dx[]={0,1,0,-1,0};
const int dy[]={0,0,1,0,-1};
int ans;

void dfs(int x,int y)
{
    if(x<1||x>n||y<1||y>n||v[x][y]||mp[x][y])return;
    if(x==fx&&y==fy)
    {
        ans++;
        return;
    }
    v[x][y]=1;
    for(int d=1;d<=4;d++)
    {
        dfs(x+dx[d],y+dy[d]);
    }
    v[x][y]=0;
}

int main()
{
    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    for(int i=1;i<=t;i++)
    {
        int x,y;
        cin>>x>>y;
        mp[x][y]=1;
    }
    dfs(sx,sy);
    cout<<ans<<endl;
    return 0;
}