#include<bits/stdc++.h>
using namespace std;

const int LEN=1e5+10;

int nQ;
string S,T;

void input(){
    cin>>S>>T;
}

char mp[256];
bool vis[256],_vis[256];
int nCyc,iCyc[256];

void trace(char c){
    memset(_vis,0,sizeof _vis);
    while(mp[c]){
        vis[c]=true;
        _vis[c]=true;
        c=mp[c];
        if(_vis[c]){
            ++nCyc;
            char d=c;
            iCyc[c]=nCyc;
            c=mp[c];
            while(c!=d){
                iCyc[c]=nCyc;
                c=mp[c];
            }
            return;
        }
        if(vis[c])return;
    }
    vis[c]=true;
}

void solve(){
    memset(mp,0,sizeof mp);
    memset(vis,0,sizeof vis);
    memset(iCyc,0,sizeof iCyc);
    nCyc=0;
    for(int i=0;i<S.size();i++){
        if(!mp[S[i]])mp[S[i]]=T[i];
        if(mp[S[i]]!=T[i]){
            cout<<-1<<endl;
            return;
        }
    }
    int ans=0;
    for(char c='a';c<='z';c++){
        if(mp[c]==c)mp[c]=0;
        else if(mp[c])++ans;
    }
    for(char c='A';c<='Z';c++){
        if(mp[c]==c)mp[c]=0;
        else if(mp[c])++ans;
    }
    //孤立的环需要一个中间字符
    for(char c='a';c<='z';c++){
        if(!vis[c]){
            trace(c);
        }
    }
    for(char c='A';c<='Z';c++){
        if(!vis[c]){
            trace(c);
        }
    }
    int nC=0;
    for(int iC=1;iC<=nCyc;iC++){
        bool valid=true;
        for(char c='a';c<='z';c++){
            if(iCyc[c]!=iC&&iCyc[mp[c]]==iC){
                valid=false;
                break;
            }
        }
        for(char c='A';c<='Z';c++){
            if(iCyc[c]!=iC&&iCyc[mp[c]]==iC){
                valid=false;
                break;
            }
        }
        if(!valid)continue;
        ++nC;
    }
    if(nC>0&&ans==52){
        cout<<-1<<endl;
        return;
    }
    ans+=nC;
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin>>nQ;
    for(int iQ=1;iQ<=nQ;iQ++){
        input();
        solve();
    }
    return 0;
}
