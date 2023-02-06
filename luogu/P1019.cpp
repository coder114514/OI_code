#include<bits/stdc++.h>
using namespace std;

int n;
string word[21];
char start;
int overlap[21][21];

int v[21],ans;

void dfs(int len,int last)
{
    ans=max(ans,len);
    for(int i=1;i<=n;i++)
    {
        if(overlap[last][i]&&v[i]<2)
        {
            v[i]++;
            dfs(len+word[i].length()-overlap[last][i],i);
            v[i]--;
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>word[i];
    cin>>start;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            // if(i==j)continue;
            int k;
            for(k=1;k<min(word[i].length(),word[j].length());k++)
            {
                string sub1=word[i].substr(word[i].length()-k);
                string sub2=word[j].substr(0,k);
                // cout<<k<<","<<sub1<<","<<sub2<<","<<i<<","<<j<<","<<(sub1!=sub2)<<endl;
                if(sub1!=sub2)continue;
                overlap[i][j]=k;
                break;
            }
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         // if(i==j)continue;
    //         cout<<word[i]<<","<<word[j]<<","<<overlap[i][j]<<endl;
    //     }
    // }
    for(int i=1;i<=n;i++)
    {
        if(word[i][0]==start)
        {
            v[i]++;
            dfs(word[i].length(),i);
            v[i]--;
        }
    }
    cout<<ans<<endl;
    return 0;
}