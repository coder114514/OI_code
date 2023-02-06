#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,s;
int a,b;

struct Apple
{
    int x,y;
} c[5010];
int nD;

bool cmp(const Apple& a1, const Apple& a2)
{
    return a1.y<a2.y;
}

int main()
{
    cin>>n>>s>>a>>b;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x>a+b)continue;
        c[++nD]=(Apple){x,y};
    }
    sort(c+1,c+1+nD,cmp);
    int ans=0,i=1;
    while(s>=0&&i<=n)
    {
        s-=c[i].y;
        ans++;
        i++;
    }
    cout<<(ans==0?0:ans-1)<<endl;
    return 0;
}