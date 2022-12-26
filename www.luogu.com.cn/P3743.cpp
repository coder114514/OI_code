#include<bits/stdc++.h>
using namespace std;

int n,p;
double a[100010],b[100010];

bool valid(double mid)
{
    double sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=max(a[i]*mid-b[i],0.0);
    }
    return p*mid>=sum;
}

int main()
{
    cin>>n>>p;
    double suma=0;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i],suma+=a[i];
    if(suma<=p)
    {
        cout<<-1<<endl;
        return 0;
    }
    double l=0,r=1e10;
    while(r-l>=1e-6)
    {
        double mid=(l+r)/2;
        if(valid(mid))l=mid;
        else r=mid;
    }
    cout<<l<<endl;
    return 0;
}