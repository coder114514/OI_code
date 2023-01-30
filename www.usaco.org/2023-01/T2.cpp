#include<bits/stdc++.h>
using namespace std;

const int N=1510;

int n,q,er[N],ed[N];
string sp[N];

int trace(int i,int j){
    while(i<=n&&j<=n){
        if(sp[i][j]=='R')++j;
        else ++i;
    }
    if(i==n+1)return ed[j];
    else return er[i];
}

int main(){
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>sp[i];
        sp[i]=" "+sp[i];
        cin>>er[i];
    }
    for(int i=1;i<=n;i++)cin>>ed[i];
    int cost=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cost+=trace(i,j);
        }
    }
    cout<<cost<<endl;
    cin>>q;
    for(int iD=1;iD<=q;iD++){
        int i,j;
        cin>>i>>j;
        if(sp[i][j]=='R')sp[i][j]='B';
        else sp[i][j]='R';
        cost=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cost+=trace(i,j);
            }
        }
        cout<<cost<<endl;
    }
    return 0;
}
