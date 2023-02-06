#include<bits/stdc++.h>
using namespace std;

int n,m;
bool mp[109][109],v[109][109];
int dx[]={0,1,-1,0,0 ,1,1,-1,-1};
int dy[]={0,0,0 ,1,-1,-1,1,-1,1};

void dfs(int x,int y)
{
    if(v[x][y]||!mp[x][y])return;
    v[x][y]=1;
    for(int d=1;d<=8;d++)
    {
        dfs(x+dx[d],y+dy[d]);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char c;
            cin>>c;
            mp[i][j]=(c=='W'?1:0);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]&&!v[i][j])
            {
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}