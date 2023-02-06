#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
pair<int,int> p[1010];

bool cmp(const pair<int,int>& p1,const pair<int,int>& p2)
{
    return p1.first*p1.second<p2.first*p2.second;
}

int prod[5010],nbits;

void print(int num[],int bits)
{
    for(int i=bits;i>=1;i--)cout<<num[i];
    cout<<endl;
}

void times(int x)
{
    for(int i=1;i<=nbits;i++)prod[i]*=x;
    for(int i=1;i<nbits;i++)
    {
        prod[i+1]+=prod[i]/10;
        prod[i]%=10;
    }
    while(prod[nbits]>=10)
    {
        prod[nbits+1]+=prod[nbits]/10;
        prod[nbits]%=10;
        ++nbits;
    }
}

int quo[5010],qbits;
void div(int x)
{
    qbits=0;
    int v=0;
    for(int i=nbits;i>=1;i--)
    {
        v=v*10+prod[i];
        quo[++qbits]=v/x;
        v%=x;
    }
    reverse(quo+1,quo+qbits+1);
    while(qbits>1&&quo[qbits]==0)qbits--;
}

int ans[5010],abits;

bool lesser()
{
    if(abits!=qbits)return abits<qbits;
    for(int i=abits;i>=1;i--)
    {
        if(ans[i]>quo[i])return false;
        if(ans[i]<quo[i])return true;
    }
    return false;
}

void update()
{
    if(lesser())
    {
        abits=qbits;
        for(int i=1;i<=qbits;i++)ans[i]=quo[i];
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<=n;i++)scanf("%d%d",&p[i].first,&p[i].second);
    sort(p+1,p+1+n,cmp);
    prod[1]=1,nbits=1;
    for(int i=1;i<=n;i++)
    {
        times(p[i-1].first);
        div(p[i].second);
        update();
    }
    print(ans,abits);
    return 0;
}