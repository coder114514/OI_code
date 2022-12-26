#include<bits/stdc++.h>
using namespace std;

const int N=200010;
double a[N];
int n,k;

double s[N],minS;

bool check(double avg)
{
    memset(s,0,sizeof(s));
    minS=1e10;
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i]-avg;
        if(i>=k)
        {
            minS=min(minS,s[i-k]);
            if(s[i]>minS)return true;
        }
    }
    return false;
}

int main()
{
    freopen("god6.in","r",stdin);
    freopen("god6.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    double l=0,r=1e10;
    while(r-l>=0.0001)
    {
        double mid=l+(r-l)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    cout<<fixed<<setprecision(2)<<l<<endl;
    return 0;
}