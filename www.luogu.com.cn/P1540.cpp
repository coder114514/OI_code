#include<bits/stdc++.h>
using namespace std;

int q[1010],l,r;
bool mem[1010];
int n,m;

int main()
{
	cin>>m>>n;
	int ans=0;
	l=r=1;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(mem[x])continue;
		ans++;
		q[r++]=x;
		mem[x]=true;
		if(r-l>m)mem[q[l++]]=false;
	}
	cout<<ans<<endl;
	return 0;
}
