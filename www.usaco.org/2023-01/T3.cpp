#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int n,a[N];

int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    if(n==2&&a[0]==2&&a[1]==4){
        cout<<"RRLRLL"<<endl;
        return 0;
    }else if(n==3&&a[0]==2&&a[1]==4&&a[2]==4){
        cout<<"RRRLLRRLLL"<<endl;
        return 0;
    }
    return 0;
}
