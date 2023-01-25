/*
ID: 18817371
LANG: C++11
PROB: fact4
*/

#include<bits/stdc++.h>
using namespace std;

int calc_n2(int x){
    int cnt=0;
    while(x%2==0)x/=2,++cnt;
    return cnt;
}

int calc_n5(int x){
    int cnt=0;
    while(x%5==0)x/=5,++cnt;
    return cnt;
}

int main(){
    freopen("fact4.in","r",stdin);
    freopen("fact4.out","w",stdout);
    int n;
    cin>>n;
    int n2=0,n5=0;
    for(int i=1;i<=n;i++){
        n2+=calc_n2(i);
        n5+=calc_n5(i);
    }
    int x=1;
    for(int i=1;i<=n;i++){
        int j=i;
        while(j%2==0)j/=2;
        while(j%5==0)j/=5;
        x*=j;
        x%=10;
    }
    // there are always more 2s than 5s in a factorial
    for(int i=1;i<=n2-n5;i++){
        x*=2;
        x%=10;
    }
    cout<<x<<endl;
    return 0;
}
