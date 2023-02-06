/*
ID: 18817371
LANG: C++11
PROB: comehome
*/

#include<bits/stdc++.h>
using namespace std;

const int NE=10010*2;
const int INF=0x3f3f3f3f;

struct Edge{
    int to,nxt,c;
}e[NE];

int nE,hd[256];

void add(int u,int v,int c){
    e[++nE]=(Edge){v,hd[u],c};
    hd[u]=nE;
}

int f[256];
bool vis[256];

struct Cmp{
    bool operator()(int u,int v){
        return f[u]>f[v];
    }
};

void Dijkstra(){
    memset(f,0x3f,sizeof f);
    f[90]=0;
    priority_queue<int,vector<int>,Cmp> q;
    q.push(90);
    while(!q.empty()){
        int u=q.top(); q.pop();
        if(vis[u])continue;
        vis[u]=true;
        for(int i=hd[u];i;i=e[i].nxt){
            int v=e[i].to,c=e[i].c;
            if(f[v]>f[u]+c){
                f[v]=f[u]+c;
                q.push(v);
            }
        }
    }
}

int main(){
    freopen("comehome.in","r",stdin);
    freopen("comehome.out","w",stdout);
    int P;
    cin>>P;
    for(int iE=1;iE<=P;iE++){
        char u,v;int c;
        cin>>u>>v>>c;
        add((int)u,(int)v,c);
        add((int)v,(int)u,c);
    }
    Dijkstra();
    char ans_c;
    int ans_d=INF;
    for(int u=65;u<90;u++){
        if(f[u]<ans_d){
            ans_d=f[u];
            ans_c=u;
        }
    }
    cout<<ans_c<<" "<<ans_d<<endl;
    return 0;
}
