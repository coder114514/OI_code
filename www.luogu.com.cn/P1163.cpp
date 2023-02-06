#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x,y,t;

bool check(double mid){
	double a=x;
	for(ll i=1;i<=t;i++){
		a=a*(1+mid/100)-y;
	}
	return a<=0;
}

int main(){
	cin>>x>>y>>t;
	double l=0,r=500; //ÓÐ¸ßÀû´û 
	while(r-l>=0.01){
		double mid=l+(r-l)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<fixed<<setprecision(1)<<l<<endl;
	return 0;
}

