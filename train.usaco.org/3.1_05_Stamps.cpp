/*
ID: 18817371
LANG: C++11
PROB: stamps
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXV = 2e6+10;

int k,n,v[60],f[MAXV];

int main(){
    freopen("stamps.in","r",stdin);
    freopen("stamps.out","w",stdout);
    cin>>k>>n;
    for(int i=1;i<=n;i++)cin>>v[i];
    int ans=1;
    while(true){
        f[ans]=1<<30;
        for(int i=1;i<=n;i++){
            if(ans>=v[i]){
                f[ans]=min(f[ans],f[ans-v[i]]+1);
            }
        }
        if(f[ans]>k)break;
        ++ans;
    }
    cout<<--ans<<endl;
    return 0;
}
