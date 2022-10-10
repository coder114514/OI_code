#include<bits/stdc++.h>
using namespace std;

int a,n,ans;
set<int> s;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(s.empty()){
            ans+=a;
            s.insert(a);
            continue;
        }
        auto it=s.lower_bound(a);
        if(it==s.end()){
            ans+=a-*prev(it);
        }else if(it==s.begin()){
            ans+=*it-a;
        }else{
            ans+=min(*it-a,a-*prev(it));
        }
        s.insert(a);
    }
    printf("%d\n",ans);
    return 0;
}
