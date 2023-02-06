#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+10;

int L,n,k,D[N],d[N];

bool check(int mid){
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=(d[i]-1)/mid;
	}
	return cnt<=k;
}

int main(){
	cin>>L>>n>>k;
	for(int i=0;i<n;i++)cin>>D[i];
	sort(D,D+n);
	n--;
	for(int i=1;i<=n;i++)d[i]=D[i]-D[i-1];
	int l=1,r=L;
	while(l<r){
		int mid=l+(r-l)/2;
		if(check(mid))r=mid;
		else l=mid+1;
	} 
	cout<<l<<endl;
	return 0;
}

