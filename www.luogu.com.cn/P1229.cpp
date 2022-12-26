#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string s1,s2;

ll count(int l1,int r1,int l2,int r2){
//    cout<<"debug:"<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
    assert(s1[l1]==s2[r2]);
    assert(r1-l1==r2-l2);
    if(l1==r1&&l2==r2)return 1;
//    char root=s1[l1];
    if(s1[l1+1]==s2[r2-1]){
        return 2*count(l1+1,r1,l2,r2-1);
    }
    char ls=s1[l1+1];
    int ils=l2;
    while(s2[ils]!=ls)++ils;
    int llt=ils-l2+1;
    return count(l1+1,l1+llt,l2,ils)*count(l1+llt+1,r1,ils+1,r2-1);
}

int main(){
    cin>>s1>>s2;
    cout<<count(0,s1.size()-1,0,s2.size()-1)<<endl;
    return 0;
}
