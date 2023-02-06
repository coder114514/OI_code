#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

typedef long long ll;

ll n,k,L[N];

bool valid(ll l){
	ll x=0;
	for(ll i=1;i<=n;i++)x+=L[i]/l;
	return x>=k;
}

int main(){
	cin>>n>>k;
	ll r=0;
	for(ll i=1;i<=n;i++)cin>>L[i],r=max(r,L[i]);
	if(!valid(1)){
		cout<<0<<endl;
		return 0;
	}
	ll l=1;
	while(l<r){
		ll mid=l+(r-l+1)/2;
		if(valid(mid))l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}
