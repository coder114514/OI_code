#include<bits/stdc++.h>
using namespace std;

int n;
double x[21],y[21];

double dist(int i,int j)
{
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

double f[1<<16][21];
bool mem[1<<16][21];

double F(int state,int i)
{
    if(mem[state][i])return f[state][i];
    if(state==(state&-state))
    {
        for(int i=1;i<=n;i++)
        {
            if(1<<i-1&state)
            {
                return dist(0,i);
            }
        }
    }
    mem[state][i]=1;
    f[state][i]=1e10;
    for(int j=1;j<=n;j++)
    {
        if((1<<j-1&(state-(1<<i-1)))==(1<<j-1))
        {
            f[state][i]=min(f[state][i],F(state-(1<<i-1),j)+dist(j,i));
        }
    }
    return f[state][i];
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
    double ans=1e10;
    for(int i=1;i<=n;i++)ans=min(ans,F((1<<n)-1,i));
    cout<<fixed<<setprecision(2)<<ans<<endl;
    return 0;
}