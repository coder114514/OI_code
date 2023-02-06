#include<bits/stdc++.h>
using namespace std;

double a,b,c,d;

double f(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}

void solve(double l,double r)
{
    if(f(l)*f(r)>=0)
    {
        if(f(l)==0)cout<<fixed<<setprecision(2)<<l<<" ";
        return;
    }
    while(r-l>0.001)
    {
        double mid=(l+r)/2;
        if(f(l)*f(mid)<=0)r=mid;
        else if(f(mid)*f(r)<0)l=mid;
        // cout<<l<<" "<<r<<endl;
    }
    cout<<fixed<<setprecision(2)<<l<<" ";
}

int main()
{
    cin>>a>>b>>c>>d;
    for(int l=-100;l<100;l++)
    {
        solve(l,l+1);
    }
    cout<<endl;
    return 0;
}