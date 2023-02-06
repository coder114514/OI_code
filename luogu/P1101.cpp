#include<bits/stdc++.h>
using namespace std;

int n;
string yizhong="yizhong";
bool mp[309][309]; // 搜索反对角线的代码可能会越界
char mat[309][309];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>(mat[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j+6<=n;j++)
        {
            bool yes=true;
            for(int k=0;k<7;k++)
                if(mat[i][j+k]!=yizhong[k])
                {
                    yes=false;
                    break;
                }
            bool yes2=true;
            for(int k=0;k<7;k++)
                if(mat[i][j+k]!=yizhong[6-k])
                {
                    yes2=false;
                    break;
                }
            if(yes||yes2)
                for(int k=0;k<7;k++)
                    mp[i][j+k]=1;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j+6<=n;j++)
        {
            bool yes=true;
            for(int k=0;k<7;k++)
                if(mat[j+k][i]!=yizhong[k])
                {
                    yes=false;
                    break;
                }
            bool yes2=true;
            for(int k=0;k<7;k++)
                if(mat[j+k][i]!=yizhong[6-k])
                {
                    yes2=false;
                    break;
                }
            if(yes||yes2)
                for(int k=0;k<7;k++)
                    mp[j+k][i]=1;
        }
    for(int k=8;k<2*n;k++)
    {
        for(int s=1;s+6<k;s++)
        {
            bool yes=true;
            for(int i=s;i<=s+6;i++)
            {
                int j=k-i;
                if(mat[i][j]!=yizhong[i-s])
                {
                    yes=false;
                    break;
                }
            }
            bool yes2=true;
            for(int i=s;i<=s+6;i++)
            {
                int j=k-i;
                if(mat[i][j]!=yizhong[6-i+s])
                {
                    yes2=false;
                    break;
                }
            }
            if(yes||yes2)
            {
                for(int i=s;i<=s+6;i++)
                {
                    mp[i][k-i]=1;
                }
            }
        }
    }
    for(int k=7-n;k<=n-7;k++)
    {
        for(int s=1;s+6<=n-abs(k);s++)
        {
            bool yes=true;
            for(int i=max(k,0)+s;i<=max(k,0)+s+6;i++)
            {
                int j=i-k;
                if(mat[i][j]!=yizhong[i-max(k,0)-s])
                {
                    yes=false;
                    break;
                }
            }
            bool yes2=true;
            for(int i=max(k,0)+s;i<=max(k,0)+s+6;i++)
            {
                int j=i-k;
                if(mat[i][j]!=yizhong[6-i+max(k,0)+s])
                {
                    yes2=false;
                    break;
                }
            }
            if(yes||yes2)
            {
                for(int i=max(k,0)+s;i<=max(k,0)+s+6;i++)
                {
                    mp[i][i-k]=1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(mp[i][j])cout<<mat[i][j];
            else cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}