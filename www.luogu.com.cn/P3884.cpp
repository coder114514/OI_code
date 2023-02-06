#include<bits/stdc++.h>
using namespace std;

const int N=109;

struct Edge{
    int to,nxt;
}e[N*2];

int nE,head[N];

void add(int u,int v){
    e[++nE]=(Edge){v,head[u]};
    head[u]=nE;
}

int top[N],son[N],sz[N],dep[N],fat[N],wid[N];

void dfs_son(int u,int fa){
    dep[u]=dep[fa]+1;
    wid[dep[u]]++;
    fat[u]=fa;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(v==fa)continue;
        dfs_son(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]){
            son[u]=v;
        }
    }
}

void dfs_top(int u,int fa){
    if(son[fa]==u)top[u]=top[fa];
    else top[u]=u;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(v==fa)continue;
        dfs_top(v,u);
    }
}

int LCA(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])v=fat[top[v]];
        else u=fat[top[u]];
    }
    return (dep[u]<dep[v]?u:v);
}

int n;

int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dep[0]=-1;
    dfs_son(1,0);
    dfs_top(1,0);
    int depth=*max_element(dep+1,dep+n+1)+1;
    int width=*max_element(wid+1,wid+depth+1);
    int x,y;
    cin>>x>>y;
    cout<<depth<<endl;
    cout<<width<<endl;
    cout<<dep[x]*2+dep[y]-dep[LCA(x,y)]*3<<endl;
    return 0;
}
