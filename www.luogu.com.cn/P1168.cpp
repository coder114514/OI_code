// wait for submit

#include<bits/stdc++.h>
using namespace std;

int n,a[100009],a2[100009],b[100009],bit[100009],mp[100009];

void add(int p)
{
    for(int i=p;i<=n;i+=i&-i)bit[i]++;
}

int sum(int p)
{
    int ans=0;
    for(int i=p;i;i-=i&-i)ans+=bit[i];
    return ans;
}

void search(int k)
{
    int l=1,r=n,ans;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(sum(mid)>=(k+1)/2)ans=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<mp[ans]<<endl;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],a2[i]=a[i];
    sort(a2+1,a2+n+1);
    int n1=unique(a2,a2+n+1)-a2-1;
    for(int i=1;i<=n;i++)b[i]=lower_bound(a2+1,a2+n1+1,a[i])-a2,mp[b[i]]=a[i];
    // for(int i=1;i<=n;i++)cout<<b[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;i+=2)
    {
        if(i==1)add(b[1]);
        else add(b[i-1]),add(b[i]);
        search(i);
    }
    return 0;
}