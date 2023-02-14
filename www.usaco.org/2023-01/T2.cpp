#include<bits/stdc++.h>
using namespace std;

const int N=1510;

int n,q,er[N],ed[N];
string sp[N];

int A[N][N];

int trace(int i,int j,int v){
    while(i<=n&&j<=n){
        A[i][j]+=v;
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
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            A[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (sp[i][j] == 'D') {
                A[i+1][j] += A[i][j];
            }
            else {
                A[i][j+1] += A[i][j];
            }
        }
    }
    int cost=0;
    for (int i = 1; i <= n; i++) {
        if (sp[i][n] == 'R') {
            cost += A[i][n] * er[i];
        }
        if (sp[n][i] == 'D') {
            cost += A[n][i] * ed[i];
        }
    }
    cout<<cost<<endl;
    cin>>q;
    for(int iD=1;iD<=q;iD++){
        int i,j;
        cin>>i>>j;
        if(sp[i][j]=='R'){
            sp[i][j]='D';
            cost-=A[i][j]*trace(i,j+1,-A[i][j]);
            cost+=A[i][j]*trace(i+1,j,A[i][j]);
        }
        else {
            sp[i][j]='R';
            cost-=A[i][j]*trace(i+1,j,-A[i][j]);
            cost+=A[i][j]*trace(i,j+1,A[i][j]);
        }
        cout<<cost<<endl;
    }
    return 0;
}
