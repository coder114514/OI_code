#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[100010];int n;

bool dfs(int i,ll s1,ll s2)
{
	if(s1>0&&s2>0&&s1==s2)return true;
	if(i>n)return false;
	return dfs(i+1,s1,s2)||dfs(i+1,s1+a[i],s2)||dfs(i+1,s1,s2+a[i]);
}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(dfs(1,0,0))cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}

int main()
{
	freopen("assemble.in","r",stdin);
	freopen("assemble.out","w",stdout);
	
	int T;
	cin>>T;
	while(T--)solve();
	
	return 0;
}
