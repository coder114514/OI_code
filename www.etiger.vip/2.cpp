#include<bits/stdc++.h>
using namespace std;

int a[100010],n,minv,maxv;

int main()
{
	cin>>n;
	minv=100000,maxv=-100000;
	for(int i=1;i<=n;i++)cin>>a[i],minv=min(minv,a[i]),maxv=max(maxv,a[i]);
	for(int i=1;i<=n;i++)if(a[i]!=minv&&a[i]!=maxv)cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
