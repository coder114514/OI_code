#include<bits/stdc++.h>
using namespace std;

string mid,pre;

void proc(int l1,int r1,int l2,int r2){
    char root=pre[l2];
    int idx=l1;
    for(;idx<=r1;idx++)
        if(mid[idx]==root)
            break;
    if(idx>l1)proc(l1,idx-1,l2+1,l2+idx-l1);
    if(idx<r1)proc(idx+1,r1,l2+idx-l1+1,r2);
    cout<<root;
}

int main(){
    cin>>mid>>pre;
    int L=mid.size();
    proc(0,L-1,0,L-1);
    cout<<endl;
    return 0;
}
