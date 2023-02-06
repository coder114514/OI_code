#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
int n,a[N],x;

void input()
{
    while(cin>>x)
    {
        a[n++]=x;
    }
}

namespace Sol1
{
    int f[N];
    void solve()
    {
        //最长上升 
        memset(f,0x3f,sizeof f);
        for(int i=0;i<n;i++)
        {
            *lower_bound(f,f+n,a[i])=a[i];
        }
        int ans2=lower_bound(f,f+n,0x3f3f3f3f)-f;
        //最长不升
        reverse(a,a+n);
        memset(f,0x3f,sizeof f);
        for(int i=0;i<n;i++)
        {
            *upper_bound(f,f+n,a[i])=a[i];
        }
        int ans1=lower_bound(f,f+n,0x3f3f3f3f)-f;
        printf("%d\n%d\n",ans1,ans2);
    }
}

namespace Sol2BIT
{
    int bit[N+1];
    
    int query(int x)
    {
        int res=0;
        for(;x>0;x-=x&-x)
        {
            res=max(res,bit[x]);
        }
        return res;
    }
    
    void change(int x,int y)
    {
        for(;x<=n;x+=x&-x)
        {
            bit[x]=max(bit[x],y);
        }
    }
    
    typedef pair<int,int> pii;
    pii b[N];
    void solve()
    {
        //最长不升 
        for(int i=0;i<n;i++)
        {
            b[i].first=-a[i];
            b[i].second=i+1;
        }
        sort(b,b+n);
        for(int i=0;i<n;i++)
        {
            int u=query(b[i].second);
            change(b[i].second,u+1);
        }
        printf("%d\n",query(n));
        //最长上升
        for(int i=1;i<=n;i++)bit[i]=0;
        for(int i=0;i<n;i++)
        {
            b[i].first=a[i];
            b[i].second=-i-1;
        }
        sort(b,b+n);
        for(int i=0;i<n;i++)b[i].second=-b[i].second;
        for(int i=0;i<n;i++)
        {
            int u=query(b[i].second);
            change(b[i].second,u+1);
        }
        printf("%d\n",query(n));
    }
}

namespace Sol2MAP
{
    map<int,int> f;
    void solve()
    {
        //最长不升
        f.clear();
        f[-1e9]=0; 
        for(int i=0;i<n;i++)
        {
            auto it=f.upper_bound(-a[i]);
            int len=prev(it)->second+1;
            while(it!=f.end()&&it->second<len)
            {
                f.erase(it++);
            }
            f[-a[i]]=len;
        }
//        printf("%d %d\n",f.rbegin()->first,f.rbegin()->second);
        printf("%d\n",f.rbegin()->second);
        //最长上升
        f.clear();
        f[-1e9]=0;
        for(int i=0;i<n;i++)
        {
            auto it=f.lower_bound(a[i]);
            int len=prev(it)->second+1;
            while(it!=f.end()&&it->second<len)
            {
                f.erase(it++);
            }
            f[a[i]]=len;
        }
//        printf("%d %d\n",f.rbegin()->first,f.rbegin()->second);
        printf("%d\n",f.rbegin()->second);
    }
}

int main()
{
    input();
    Sol2MAP::solve();
    return 0;
}
