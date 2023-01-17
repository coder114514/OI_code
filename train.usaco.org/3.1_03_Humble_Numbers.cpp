/*
ID: 18817371
LANG: C++11
PROB: humble
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int k,n;
ll s[110];
priority_queue<ll,vector<ll>,greater<ll>> q;

int main(){
//    freopen("humble.in","r",stdin);
//    freopen("humble.out","w",stdout);
    cin>>k>>n;
    for(int i=1;i<=k;i++)cin>>s[i],q.push(s[i]);
    int nth=0,last=-1;
    while(true){
        ll x=q.top(); q.pop();
        if(x==last)continue;
        last=x;
        if(++nth==n){
            cout<<x<<endl;
            return 0;
        }
        for(int i=1;i<=k;i++)q.push(x*s[i]);
    }
    return 0;
}
