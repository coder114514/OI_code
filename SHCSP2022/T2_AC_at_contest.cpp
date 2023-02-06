#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M=1009;
const ll MOD=1e9+7;

struct Seg{
    ll x,y1,y2,mark;
} seg[M*2];

bool cmp(const Seg&a,const Seg&b){
    if(a.x!=b.x)return a.x<b.x;
    return a.mark<b.mark;
}

struct Matrix{
    ll data[10][10];
    int nR,nC;
    Matrix(int nR,int nC):nR(nR),nC(nC){
        memset(data,0,sizeof data);
    }
};

Matrix operator*(Matrix a,Matrix b){
    Matrix res(a.nR,b.nC);
    for(int i=1;i<=a.nR;i++){
        for(int j=1;j<=b.nC;j++){
            for(int k=1;k<=b.nR;k++){
                res.data[i][j]+=a.data[i][k]*b.data[k][j]%MOD;
                res.data[i][j]%=MOD;
            }
        }
    }
    return res;
}

Matrix mat_power(Matrix m,ll k){
    Matrix res(m.nR,m.nC);
    for(int i=1;i<=m.nR;i++)res.data[i][i]=1;
    while(k){
        if(k&1){
            res=res*m;
        }
        Matrix m2=m*m;
        m=m2;
        k>>=1;
    }
    return res;
}

void print(Matrix m){
    cout<<"MATRIX:"<<endl;
    for(int i=1;i<=m.nR;i++){
        for(int j=1;j<=m.nC;j++){
            cout<<m.data[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"END"<<endl;
}

int m;
ll n;
Matrix f(6,1),g(6,1);
int invalid[10];

// f[i][j]: i列j行方案数 

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x1,y1,x2,y2;
        cin>>y1>>x1>>y2>>x2; //x列 y行 
        seg[i]=(Seg){x1,y1,y2,1};
        seg[i+m]=(Seg){x2+1,y1,y2,-1};
    }
    sort(seg+1,seg+2*m+1,cmp);
    for(int j=1;j<=6;j++)g.data[j][1]=1;
    seg[2*m+1]=(Seg){n,0,0,0};
    int iSeg=1;
    for(ll i=1;i<=n&&iSeg<=2*m;i=seg[iSeg].x){
        f=g;
        while(iSeg<=2*m&&seg[iSeg].x==i){
            for(int j=seg[iSeg].y1;j<=seg[iSeg].y2;j++){
                invalid[j]+=seg[iSeg].mark;
            }
            ++iSeg;
        }
        Matrix M(6,6);
        for(int j=1;j<=6;j++){
            M.data[j][j-1]=1;
            M.data[j][j]=1;
            M.data[j][j+1]=1;
        }
        for(int j=1;j<=6;j++){
            if(!invalid[j])continue;
            for(int k=1;k<=6;k++){
                M.data[k][j]=0;
            }
        }
        Matrix M2=mat_power(M,seg[iSeg].x-i);
        g=M2*f;
    }
    if(m==0){
        Matrix M(6,6);
        for(int j=1;j<=6;j++){
            M.data[j][j-1]=1;
            M.data[j][j]=1;
            M.data[j][j+1]=1;
        }
        Matrix M2=mat_power(M,n-1);
        f=M2*g;
        g=f;
    }
    ll ans=0;
    for(int j=1;j<=6;j++)ans=(ans+g.data[j][1])%MOD;
    cout<<ans<<endl;
    return 0;
}
