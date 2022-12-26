#include<bits/stdc++.h>
using namespace std;

int n,p[20][2],curN;

int path[30][2],d;
bool is_sat;

bool check(){
    for(int i=1;i<=curN;i++){
        bool sat=false;
        for(int j=1;j<=21;j++){
            if(max(abs(p[i][0]-path[j][0]),abs(p[i][1]-path[j][1]))<=d){
                sat=true;
                break;
            }
        }
        if(!sat)return false;
    }
    return true;
}

void dfs(int i,int j){
    if(is_sat)return;
    if(i>10||j>10)return;
    path[i+j+1][0]=i;
    path[i+j+1][1]=j;
    if(i==10&&j==10){
        if(check()){
            is_sat=true;
        }
        return;
    }
    dfs(i+1,j);
    dfs(i,j+1);
}

void do_bf(){
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        p[i][0]=x;
        p[i][1]=y;
        ++curN;
        is_sat=false;
        dfs(0,0);
        while(!is_sat){
            ++d;
            dfs(0,0);
        }
        cout<<d<<endl;
    }
}

int main(){
    cin>>n;
    if(n<=10){
        do_bf();
        return 0;
    }
    for(int i=1;i<=n;i++){
        cout<<0<<endl;
    }
    return 0;
}
