#include<bits/stdc++.h>
using namespace std;

int n;
int mp[39][39];

const int dx[]={0,1,0,-1,0};
const int dy[]={0,0,1,0,-1};

void flood(int x,int y)
{
    if(x<1||x>n||y<1||y>n)return;
    if(mp[x][y]==1||mp[x][y]==2)return;
    mp[x][y]=2;
    for(int d=1;d<=4;d++)
    {
        flood(x+dx[d],y+dy[d]);
    }
}

bool v[39][39],out;

void dfs(int x,int y)
{
    if(x<1||x>n||y<1||y>n)
    {
        out=true;
        return;
    }
    if(mp[x][y]==1||v[x][y])return;
    v[x][y]=1;
    for(int d=1;d<=4;d++)dfs(x+dx[d],y+dy[d]);
}

int x,y;
void find()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(mp[i][j]==1)continue;
            out=false;
            memset(v,0,sizeof(v));
            dfs(i,j);
            if(!out)
            {
                x=i,y=j;
                return;
            }
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>mp[i][j];
    find();
    flood(x,y);
    for(int i=1;i<=n;i++)
    {
        cout<<mp[i][1];
        for(int j=2;j<=n;j++)
        {
            cout<<" "<<mp[i][j];
        }
        cout<<endl;
    }
    return 0;
}