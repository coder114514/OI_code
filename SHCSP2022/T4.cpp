#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10,A=1e8+9;

int n,m,l[N],r[N],intersect[N],s1[N],s2[N];
bitset<A> v;

bool check_special(){
    for(int i=1;i<n;i++){
        if(l[i]<=l[i+1]&&r[i]<=r[i+1]){
        }else{
            return false;
        }
    }
    return true;
}

void do_special(){
    for(int i=1;i<n;i++){
        if(r[i]>=l[i+1]){
            intersect[i]=r[i]-l[i+1]+1;
        }
    }
    for(int i=1;i<=n;i++){
        s1[i]=s1[i-1]+r[i]-l[i]+1;
        s2[i]=s2[i-1]+intersect[i];
    }
    int ans=0;
    for(int iQ=1;iQ<=m;iQ++){
        int ql,qr;
        cin>>ql>>qr;
        int p1=lower_bound(l+1,l+n+1,ql)-l;
        int p2=upper_bound(r+1,r+n+1,qr)-r-1;
        if(p1>p2)continue;
        int sum=s1[p2]-s1[p1-1]-s2[p2-1]+s2[p1-1];
        ans^=sum;
    }
    cout<<ans<<endl;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>l[i]>>r[i];
    if(check_special()){
        do_special();
        return 0;
    }
    int ans=0;
    for(int iQ=1;iQ<=m;iQ++){
        int ql,qr;
        cin>>ql>>qr;
        v.reset();
        for(int i=1;i<=n;i++){
            if(ql<=l[i]&&r[i]<=qr){
                for(int x=l[i];x<=r[i];x++){
                    v[x]=1;
                }
            }
        }
        int sum=0;
        for(int i=ql;i<=qr;i++)sum+=v[i];
        ans^=sum;
    }
    cout<<ans<<endl;
    return 0;
}
