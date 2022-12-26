#include<bits/stdc++.h>
using namespace std;

int n,m,h[109][109];

const int dir[5][2]={{0,0},{0,1},{0,-1},{1,0},{-1,0}};

int f[109][109];
bool vis[109][109];
int F(int x,int y)
{
    if(vis[x][y])return f[x][y];
    int ans=1;
    for(int d=1;d<=4;d++)
    {
        int nx=x+dir[d][0],ny=y+dir[d][1];
        if(nx<1||nx>n||ny<1||ny>m)continue;
        if(h[nx][ny]<h[x][y])ans=max(ans,F(nx,ny)+1);
    }
    vis[x][y]=1;
    return f[x][y]=ans;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>h[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ans=max(ans,F(i,j));
        }
    }
    cout<<ans<<endl;
    return 0;
}