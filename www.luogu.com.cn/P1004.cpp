#include<bits/stdc++.h>
using namespace std;

const int N=9+9;

int f[N][N][N][N],a[N][N],n;

int main(){
    cin>>n;
    int x,y,z;
    while(cin>>x>>y>>z){
        if(x==0&&y==0&&z==0)break;
        a[x][y]=z;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                for(int l=1;l<=n;l++){
                    if(i+j!=k+l)continue;
                    if(i!=k||j!=l)f[i][j][k][l]+=a[i][j]+a[k][l];
                    else f[i][j][k][l]+=a[i][j];
                    f[i+1][j][k+1][l]=max(f[i+1][j][k+1][l],f[i][j][k][l]);
                    f[i+1][j][k][l+1]=max(f[i+1][j][k][l+1],f[i][j][k][l]);
                    f[i][j+1][k+1][l]=max(f[i][j+1][k+1][l],f[i][j][k][l]);
                    f[i][j+1][k][l+1]=max(f[i][j+1][k][l+1],f[i][j][k][l]);
//                    cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<f[i][j][k][l]<<endl;
                }
            }
        }
    }
    cout<<f[n][n][n][n]<<endl;
	return 0;
}
