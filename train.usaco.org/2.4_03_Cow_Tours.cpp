/*
ID: 18817371
LANG: C++11
PROB: cowtour
*/

#include<bits/stdc++.h>
using namespace std;

const int N=159;

int n,x[N],y[N],G[N][N],iB[N],nIB;
double dist[N][N],max_dist[N],maxDiam;

void dfs(int i,int ib){
    iB[i]=ib;
    for(int j=1;j<=n;j++){
        if(!G[i][j]||iB[j])continue;
        dfs(j,ib);
    }
}

void add(int i,int j){
    G[i][j]=G[j][i]=1;
}

void sub(int i,int j){
    G[i][j]=G[j][i]=0;
}

double d(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
    freopen("cowtour.in","r",stdin);
    freopen("cowtour.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            G[i][j]=c-'0';
            if(G[i][j])dist[i][j]=d(x[i],y[i],x[j],y[j]);
            else dist[i][j]=1e10;
        }
    }
    for(int i=1;i<=n;i++){
        if(!iB[i]){
            ++nIB;
            dfs(i,nIB);
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j&&dist[i][j]<1e10)max_dist[i]=max(max_dist[i],dist[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        maxDiam=max(maxDiam,max_dist[i]);
    }
    double ans=1e10;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(iB[i]>=iB[j])continue;
            double diam=max_dist[i]+max_dist[j]+d(x[i],y[i],x[j],y[j]);
            ans=min(ans,max(maxDiam,diam));
        }
    }
    printf("%.6lf\n",ans);
    return 0;
}
