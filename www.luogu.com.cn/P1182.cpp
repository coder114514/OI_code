#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+10;

int n,m,a[N];

bool check(int mid){
	int s=0,cnt=0;
	for(int i=1;i<=n;i++){
		s+=a[i];
		if(s>mid){
			cnt++;
			s=a[i];
		}
	}
	if(s<mid)cnt++; // left over stuff
	return cnt<=m;
}

int main(){
	cin>>n>>m;
	int l=0,r=0;
	for(int i=1;i<=n;i++)cin>>a[i],r+=a[i],l=max(l,a[i]);
	while(l<r){
		int mid=l+(r-l)/2;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}

