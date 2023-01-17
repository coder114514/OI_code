/*
ID: 18817371
LANG: C++11
PROB: humble
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF=1LL<<62;

int k,n;
ll s[110],h[100010];
int last[110];

int main(){
    freopen("humble.in","r",stdin);
    freopen("humble.out","w",stdout);
    cin>>k>>n;
    for(int i=1;i<=k;i++)cin>>s[i];
    h[0]=1;
    for(int iH=1;iH<=n;iH++){
        ll next=INF;
        for(int i=1;i<=k;i++){
            for(int j=last[i];j<iH;j++){
                if(s[i]*h[j]>h[iH-1]){
                    last[i]=j;
                    next=min(next,s[i]*h[j]);
                    break;
                }
            }
        }
        h[iH]=next;
    }
    cout<<h[n]<<endl;
    return 0;
}
