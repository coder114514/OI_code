/*
ID: 18817371
LANG: C++11
PROB: agrinet
*/

#include<bits/stdc++.h>
using namespace std;

const int N=110;
const int INF=1<<30;

int n,G[N][N],dist[N];
bool inTree[N];

int Prim(){
    int ans=0;
    dist[0]=INF;
    inTree[1]=true;
    for(int i=1;i<=n;i++)dist[i]=G[i][1];
    for(int k=2;k<=n;k++){
        int i=0;
        for(int j=1;j<=n;j++)
            if(!inTree[j]&&dist[j]<dist[i])
                i=j;
        ans+=dist[i];
        inTree[i]=true;
        for(int j=1;j<=n;j++)
            if(!inTree[j])
                dist[j]=min(dist[j],G[i][j]);
    }
    return ans;
}

int main(){
    freopen("agrinet.in","r",stdin);
    freopen("agrinet.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>G[i][j];
        }
    }
    cout<<Prim()<<endl;
    return 0;
}
