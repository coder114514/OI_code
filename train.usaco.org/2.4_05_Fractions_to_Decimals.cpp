/*
ID: 18817371
LANG: C++11
PROB: fracdec
*/

#include<bits/stdc++.h>
using namespace std;

int x,y,k,len;
map<int,int> occur;

stringstream str;
string str2;

int main() {
    freopen("fracdec.in","r",stdin);
    freopen("fracdec.out","w",stdout);
    cin>>x>>y;
    if(x%y==0){
        cout<<x/y<<".0"<<endl;
        return 0;
    }
    str<<x/y<<".";
    len=str.str().size();
    x=(x%y)*10;
    while(occur[x]==0) {
        occur[x]=len++;
        str<<x/y;
        x=(x%y)*10;
    }
    str2=str.str();
    int cnt=0;
    for(int i=0;i<str2.size();i++){
        if(i==occur[x]&&x==0){
            cout<<endl;
            return 0;
        }
        if(i==occur[x])cout<<'(',++cnt;
        cout<<str2[i],++cnt;
        if(cnt==76){
            cout<<endl;
            cnt=0;
        }
    }
    cout<<')'<<endl;
    return 0;
}
