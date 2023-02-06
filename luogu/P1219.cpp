#include<bits/stdc++.h>
using namespace std;

int n;
bool col[21];
int ans[21];
int cnt;

void dfs(int row)
{
    if(row>n)
    {
        cnt++;
        if(cnt>3)return;
        for(int i=1;i<=n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(col[i])continue;
        bool valid=true;
        for(int j=1;j<row;j++)
        {
            if(row-j==abs(i-ans[j]))
            {
                valid=false;
                break;
            }
        }
        if(!valid)continue;
        col[i]=1;
        ans[row]=i;
        dfs(row+1);
        col[i]=0;
    }
}

int main()
{
    cin>>n;
    dfs(1);
    cout<<cnt<<endl;
    return 0;
}