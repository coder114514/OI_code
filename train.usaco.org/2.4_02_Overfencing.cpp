/*
ID: 18817371
LANG: C++11
PROB: maze1
*/

#include<bits/stdc++.h>
using namespace std;

int W,H;

string mp[2*100+9];
int path[109][43],d[109][43];
bool vis[109][43];

int bfs(int sr,int sc){
    queue<pair<int,int> > q;
    q.push(make_pair(sr,sc));
    memset(d,0,sizeof d);
    memset(vis,0,sizeof vis);
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        if(r<1||r>H||c<1||c>W)return d[r][c];
        if(vis[r][c])continue;
        vis[r][c]=1;
        if(path[r][c]&1){
            d[r-1][c]=d[r][c]+1;
            q.push(make_pair(r-1,c));
        }
        if(path[r][c]&2){
            d[r][c-1]=d[r][c]+1;
            q.push(make_pair(r,c-1));
        }
        if(path[r][c]&4){
            d[r+1][c]=d[r][c]+1;
            q.push(make_pair(r+1,c));
        }
        if(path[r][c]&8){
            d[r][c+1]=d[r][c]+1;
            q.push(make_pair(r,c+1));
        }
    }
}

int main(){
    freopen("maze1.in","r",stdin);
    freopen("maze1.out","w",stdout);
    cin>>W>>H;
    getline(cin,mp[0]);
    for(int i=1;i<=2*H+1;i++){
        getline(cin,mp[i]);
        mp[i]=" "+mp[i];
    }
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            if(mp[i*2-1][j*2]==' ')path[i][j]|=1;
            if(mp[i*2][j*2-1]==' ')path[i][j]|=2;
            if(mp[i*2+1][j*2]==' ')path[i][j]|=4;
            if(mp[i*2][j*2+1]==' ')path[i][j]|=8;
        }
    }
    int ans=0;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            ans=max(ans,bfs(i,j));
        }
    }
    cout<<ans<<endl;
    return 0;
}
