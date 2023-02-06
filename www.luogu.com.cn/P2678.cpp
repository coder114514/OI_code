#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;

int L,n,m,D[N],d[N];

bool check(int mid){
	int cnt=0,sum=0;
	for(int i=1;i<=n+1;i++){
		sum+=d[i];
		if(sum<mid)cnt++;
		else sum=0;
	}
	return cnt<=m;
}

int main(){
	cin>>L>>n>>m;
	for(int i=1;i<=n;i++)cin>>D[i];
	D[n+1]=L;
	for(int i=1;i<=n+1;i++)d[i]=D[i]-D[i-1];
	int l=1,r=L;
	while(l<r){
		int mid=l+(r-l+1)/2;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}
