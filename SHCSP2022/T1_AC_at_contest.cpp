#include<bits/stdc++.h>
using namespace std;

const int N=109,M=509,TIME=1e7+9;

struct Ppl{
    int T,S;
} other[M];

bool cmp(const Ppl&a,const Ppl&b){
    return a.T<b.T;
}

int n,m,total,f[TIME],t[N],s[N],os[M],f2[TIME];

int main(){
    cin>>n>>m>>total;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>s[i];
    }
    for(int i=1;i<=m;i++){
        cin>>other[i].T>>other[i].S;
        os[i]=other[i].S;
    }
    sort(other+1,other+m+1,cmp);
    sort(os+1,os+m+1,greater<int>());
    // f[t]: t时间内做题最大分数 
    for(int i=1;i<=n;i++){
        for(int j=total;j>=t[i];j--){
            f[j]=max(f[j],f[j-t[i]]+s[i]);
        }
    }
    memcpy(f2,f,sizeof f);
    int total2=unique(f2,f2+total+1)-f2-1;
    int r=114514;
    for(int iTm=0;iTm<=total2;iTm++){
        int tm=lower_bound(f+1,f+total+1,f2[iTm])-f;
        int tm2=total-tm;
        int p=lower_bound(os+1,os+m+1,f[tm],greater<int>())-os;
        for(int i=1;i<=m;i++){
            if(tm2>=other[i].T&&other[i].S>f[tm]){
                tm2-=other[i].T;
                p--;
            }
            if(tm2<other[i].T)break;
        }
        if(p<=0)p=1;
        r=min(r,p);
    }
    cout<<r<<endl;
    return 0;
}
