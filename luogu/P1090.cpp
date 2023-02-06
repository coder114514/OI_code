#include<bits/stdc++.h>
using namespace std;

int n,x[10010];
priority_queue<int,vector<int>,greater<int> > q;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i],q.push(x[i]);
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    int ans=0;
    for(int i=1;i<n;i++)
    {
        int a1=q.top();
        q.pop();
        int a2=q.top();
        q.pop();
        ans+=a1+a2;
        q.push(a1+a2);
    }
    cout<<ans<<endl;
    return 0;
}