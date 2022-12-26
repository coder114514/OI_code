#include<bits/stdc++.h>
using namespace std;

const int NR=1024,NC=2048;
const int M=12;

int m,n,nrows,ncols;
bool rem[M][1<<M];
char convas[NR][NC]; 

//nrows=3*2^(m-2)
//ncols=6*2^(m-2)-1

void dfs(int i,int j,int&row,int&col,bool draw=true){
    if(i==m){
        row=nrows;
        if(j%2)col=3*j-2;
        else col=3*j-1;
        if(draw)convas[row][col]='o';
        return;
    }
    int l_r,l_c,r_r,r_c;
    dfs(i+1,2*j-1,l_r,l_c,!rem[i+1][2*j-1]&&draw);
    dfs(i+1,2*j,r_r,r_c,!rem[i+1][2*j]&&draw);
    col=(l_c+r_c)/2;
    row=l_r-(r_c-l_c)/2;
    if(draw){
        convas[row][col]='o';
        if(!rem[i+1][2*j-1]){
            for(int i=row+1;i<l_r;i++){
                convas[i][row+col-i]='/';
            }
        }
        if(!rem[i+1][2*j]){
            for(int i=row+1;i<r_r;i++){
                convas[i][i-row+col]='\\';
            }
        }
    }
}

int main(){
    cin>>m>>n;
    for(int iP=1;iP<=n;iP++){
        int i,j;
        cin>>i>>j;
        rem[i][j]=1;
    }
    nrows=3*(1<<(m-2));
    ncols=6*(1<<(m-2))-1;
    for(int i=1;i<=nrows;i++){
        for(int j=1;j<=ncols;j++){
            convas[i][j]=' ';
        }
    }
    int r,c;
    dfs(1,1,r,c);
    for(int i=1;i<=nrows;i++){
        for(int j=1;j<=ncols;j++){
            cout<<convas[i][j];
        }
        cout<<endl;
    }
    return 0;
}
