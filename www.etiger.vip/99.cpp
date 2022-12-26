#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	int a,b,c,d,ans=0;
	cin>>a>>b>>c>>d;
	ans+=a+d;
	cin>>a>>b>>c>>d;
	ans+=b+c;
	cin>>a>>b>>c>>d;
	ans+=b+c;
	cin>>a>>b>>c>>d;
	ans+=a+d;
	cout<<ans<<endl;
	return 0;
}
