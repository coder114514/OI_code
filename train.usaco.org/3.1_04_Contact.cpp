/*
ID: 18817371
LANG: C++11
PROB: contact
*/

#include<bits/stdc++.h>
using namespace std;

int a,b,n;
string seq;

vector<pair<int,int>> res;

int cnt[8200];

int pat2num(string p){
    int start_idx=(1<<p.size())-2;
    int x=0;
    for(int i=0;i<p.size();i++){
        x=x*2+p[i]-'0';
    }
    return start_idx+x;
}

string num2pat(int x){
    int len=1;
    while((1<<(len+1))-2<=x){
        ++len;
    }
    x-=(1<<len)-2;
    string p;
    for(int i=0;i<len;i++){
        p=(char)('0'+x%2)+p;
        x/=2;
    }
    return p;
}

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    else{
        return a.first>b.first;
    }
}

int main(){
    freopen("contact.in","r",stdin);
    freopen("contact.out","w",stdout);
    scanf("%d%d%d",&a,&b,&n);
    string s;
    while(cin>>s)seq+=s;
    b=min(b,(int)seq.size());
    if(a>b)return 0;
    for(int i=a-1;i<seq.size();i++){
        for(int len=a;len<=b;len++){
            if(i>=len-1){
                cnt[pat2num(seq.substr(i-len+1,len))]++;
            }
        }
    }
    for(int iPat=(1<<a)-2;iPat<(1<<(b+1))-2;++iPat){
        if(cnt[iPat]){
            res.push_back(make_pair(cnt[iPat],iPat));
        }
    }
    int nOut=0;
    sort(res.begin(),res.end(),cmp);
    for(int i=0;i<res.size()&&nOut<n;i++){
        cout<<res[i].first<<endl<<num2pat(res[i].second);
        ++nOut;
        int num=0;
        while(i+1<res.size()&&res[i].first==res[i+1].first){
            ++i;
            ++num;
            if(num%6==0){
                cout<<endl<<num2pat(res[i].second);
            }else{
                cout<<" "<<num2pat(res[i].second);
            }
        }
        cout<<endl;
    }
    return 0;
}
