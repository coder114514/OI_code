/*
ID: 18817371
LANG: C++11
PROB: inflate
*/

#include<bits/stdc++.h>
using namespace std;

const int M=10010,N=10010;

int m,n;
int f[M];
int v[N],c[N];

int main(){
    freopen("inflate.in","r",stdin);
    freopen("inflate.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=c[i];j<=m;j++){
            f[j]=max(f[j],f[j-c[i]]+v[i]);
        }
    }
    cout<<f[m]<<endl;
}
