#include<bits/stdc++.h>
using namespace std;

const int N=109;

struct Edge{
    int to,nxt;
}e[N*2];

int n,nE,head[N],w[N];

void add(int u,int v){
    ++nE;
    e[nE]=(Edge){v,head[u]};
    head[u]=nE;
}

int d[N];

void dfs(int u,int fa){
    d[u]=d[fa]+1;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,u);
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>w[i]>>u>>v;
        if(u)add(u,i),add(i,u);
        if(v)add(v,i),add(i,v);
    }
    d[0]=-1;
    int ans=0x7f7f7f7f;
    for(int u=1;u<=n;u++){
        int sum=0;
        dfs(u,0);
        for(int v=1;v<=n;v++){
            sum+=d[v]*w[v];
        }
        ans=min(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}
