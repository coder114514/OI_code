#include<bits/stdc++.h>
using namespace std;

const int N=32767+10;
const int INF=1<<28;

struct Val
{
    int num,day;
    bool operator<(const Val&o) const
    {
        if(num==o.num)return day<o.day;
        else return num<o.num;
    }
} x[N];

int n;

int check(int pos)
{
    int bef=-INF,aft=INF;
    for(int i=pos-1;i>=1;i--)
    {
        if(x[i].day<x[pos].day)
        {
            bef=x[i].num;
            break;
        }
    }
    for(int i=pos+1;i<=n;i++)
    {
        if(x[i].day<x[pos].day)
        {
            aft=x[i].num;
            break;
        }
    }
    if(bef==-INF&&aft==INF)return x[pos].num;
    return min(x[pos].num-bef,aft-x[pos].num);
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        x[i].day=i;
        cin>>x[i].num;
    }
    sort(x+1,x+n+1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=check(i);
    }
    cout<<ans<<endl;
    return 0;
}
