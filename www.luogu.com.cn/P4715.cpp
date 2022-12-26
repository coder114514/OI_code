#include<bits/stdc++.h>
using namespace std;

const int N=7+3;
int n,a[1<<N];

int main(){
    cin>>n;
    for(int i=1;i<=(1<<n);i++)cin>>a[i];
    int m1=max_element(a+1,a+(1<<n-1)+1)-a;
    int m2=max_element(a+(1<<n-1)+1,a+(1<<n)+1)-a;
    cout<<(a[m1]<a[m2]?m1:m2)<<endl;
    return 0;
}
