/*
ID: 18817371
LANG: C++11
PROB: contact
*/

#include<bits/stdc++.h>
using namespace std;

int a,b,n;
string seq;

string pat;

typedef pair<int,string> pis;

vector<pis> res;

bool cmp(const pis&a,const pis&b){
    if(a.first==b.first&&a.second.size()==b.second.size()){
        return a.second<b.second;
    }else if(a.first==b.first){
        return a.second.size()<b.second.size();
    }else{
        return a.first>b.first;
    }
}

bool check(int pos,int len){
    for(int i=pos;i<pos+len;i++){
        if(seq[i]!=pat[i-pos]){
            return false;
        }
    }
    return true;
}

void count(int len){
    int cnt=0;
    for(int i=0;i<seq.size()-len+1;i++){
        if(check(i,len)){
            ++cnt;
        }
    }
    if(cnt>0){
        res.push_back(make_pair(cnt,pat.substr(0,len)));
    }
}

void dfs(int len,int i){
    if(i>=len){
        count(len);
        return;
    }
    pat[i]='0';
    dfs(len,i+1);
    pat[i]='1';
    dfs(len,i+1);
}

int main(){
//    freopen("contact.in","r",stdin);
//    freopen("contact.out","w",stdout);
    scanf("%d%d%d",&a,&b,&n);
    pat.resize(b);
    string s;
    while(cin>>s)seq+=s;
    for(int len=a;len<=b&&len<=seq.size();len++){
        dfs(len,0);
    }
    int nOut=0;
    sort(res.begin(),res.end(),cmp);
    for(int i=0;i<res.size()&&nOut<n;i++){
        cout<<res[i].first<<endl<<res[i].second;
        ++nOut;
        while(i+1<res.size()&&res[i].first==res[i+1].first){
            ++i;
            cout<<" "<<res[i].second;
        }
        cout<<endl;
    }
    return 0;
}
