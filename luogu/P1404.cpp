#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=200010;
double a[N];
int n,k;

double s[N],minS;

bool check(double avg)
{
    memset(s,0,sizeof(s));
    minS=1LL<<60;
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
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i],a[i]*=1000;
    double l=0,r=3000000,ans;
    while(r-l>=0.001)
    {
        double mid=(l+r)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    cout<<(int)r<<endl;
    return 0;
}