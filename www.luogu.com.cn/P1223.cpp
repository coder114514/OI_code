#include<bits/stdc++.h>
using namespace std;

int n;
double sum;

struct S{
	int t,i;
}s[1010];

bool cmp(const S&a,const S&b){
	if(a.t!=b.t)return a.t<b.t;
	return a.i<b.i;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i].t,s[i].i=i;
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)sum+=(n-i)*s[i].t;
	for(int i=1;i<=n;i++)cout<<s[i].i<<" ";
	cout<<endl<<fixed<<setprecision(2)<<sum/n<<endl;
	return 0;
}
