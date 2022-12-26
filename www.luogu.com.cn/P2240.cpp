#include<bits/stdc++.h>
using namespace std;

int N;int T;
struct Coin{
	double m,v;
}coins[120];

bool cmp(const Coin&a,const Coin&b){
	return a.v/a.m>b.v/b.m;
}

int main(){
	cin>>N>>T;
	for(int i=1;i<=N;i++)cin>>coins[i].m>>coins[i].v;
	sort(coins+1,coins+N+1,cmp);
	double ans=0;
	for(int i=1;i<=N;i++){
		if(T>=coins[i].m){
			T-=coins[i].m;
			ans+=coins[i].v;
		}else{
			ans+=coins[i].v/coins[i].m*T;
			break;
		}
	}
	cout<<fixed<<setprecision(2)<<ans<<endl;
	return 0;
}
