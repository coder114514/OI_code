#include<bits/stdc++.h>
using namespace std;

multiset<int> S;

void solve1(int x){
    auto it=S.lower_bound(x);
    int cnt=0;
    for(auto i=S.begin();i!=it;++i){
        ++cnt;
    }
    cout<<cnt<<endl;
}

void solve2(int x){
    int cnt=-1;
    for(int i:S){
        ++cnt;
        if(cnt==x){
            cout<<i<<endl;
            break;
        }
    }
}

void solve3(int x){
    cout<<*--S.lower_bound(x)<<endl;
}

void solve4(int x){
    cout<<*S.upper_bound(x)<<endl;
}

int main(){
    S.insert(0x7fffffff);
    S.insert(-0x7fffffff);
    int nQ;
    cin>>nQ;
    for(int iQ=1;iQ<=nQ;iQ++){
        int op,x;
        cin>>op>>x;
        switch(op){
            case 1:
                solve1(x);
                break;
            case 2:
                solve2(x);
                break;
            case 3:
                solve3(x);
                break;
            case 4:
                solve4(x);
                break;
            case 5:
                S.insert(x);
                break;
            default:
                break;
        }
    }
    return 0;
}
