#include<bits/stdc++.h>
using namespace std;

const int N=1e6+9;

struct Edge{
    int to,nxt;
}e[N];

int hd[N],nE;

void addedge(int u,int v){
    e[++nE]=(Edge){v,hd[u]};
    hd[u]=nE;
}

int n,d[N];

void dfs(int u){
    for(int i=hd[u];i;i=e[i].nxt){
        int v=e[i].to;
        d[v]=d[u]+1;
        dfs(v);
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        if(l)addedge(i,l);
        if(r)addedge(i,r);
    }
    d[1]=1;
    dfs(1);
    cout<<*max_element(d+1,d+n+1)<<endl;
    return 0;
}
