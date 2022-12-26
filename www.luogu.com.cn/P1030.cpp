#include<bits/stdc++.h>
using namespace std;

string s1,s2;

void dfs(int l1,int r1,int l2,int r2){
    assert(r1-l1==r2-l2);
    char root=s2[r2];
    cout<<root;
    if(l1==r1&&l2==r2)return;
    int ir1=l1;
    while(s1[ir1]!=root)++ir1;
    int len=ir1-l1;
    if(ir1>l1)dfs(l1,ir1-1,l2,l2+len-1);
    if(ir1<r1)dfs(ir1+1,r1,l2+len,r2-1);
}

int main(){
    cin>>s1>>s2;
    dfs(0,s1.size()-1,0,s2.size()-1);
    return 0;
}
