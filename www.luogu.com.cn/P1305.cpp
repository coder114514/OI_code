#include<bits/stdc++.h>
using namespace std;

int son[256][2],n;

void dfs(char u){
    if(!u)return;
    cout<<u;
    dfs(son[u][0]);
    dfs(son[u][1]);
}

int main(){
    cin>>n;
    char root;
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        if(i==1)root=str[0];
        if(str[1]!='*')son[str[0]][0]=str[1];
        if(str[2]!='*')son[str[0]][1]=str[2];
    }
    dfs(root);
    cout<<endl;
    return 0;
}
