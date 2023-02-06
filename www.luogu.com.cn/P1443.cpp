#include<bits/stdc++.h>
using namespace std;

int n,m,x,y;
int mp[409][409];

void bfs()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            mp[i][j]=-1;
    mp[x][y]=0;
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        int drow[]={-2,-2,-1,-1, 1,1, 2,2};
        int dcol[]={-1, 1,-2, 2,-2,2,-1,1};
        for(int d=0;d<8;d++)
        {
            int r=row+drow[d];
            int c=col+dcol[d];
            if(r<1||r>n||c<1||c>m)continue;
            if(mp[r][c]!=-1)continue;
            q.push(make_pair(r,c));
            mp[r][c]=mp[row][col]+1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%-5d", mp[i][j]);
        }
        cout<<endl;
    }
}

int main()
{
    cin>>n>>m>>x>>y;
    bfs();
    return 0;
}