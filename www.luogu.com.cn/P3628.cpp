#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=1e6+10,INF=1e18;

ll n,a,b,c,x[N],s[N],f[N],q[N];

// f[i]=min{f[j]+a*s[j]*s[j]-b*s[j]-2*a*s[j]*s[i]+a*s[i]*s[i]+b*s[i]+c}
// b:f[i]+a*s[i]*s[i]-b*s[i]
// k:-2*a*s[i]

struct Line{
	ll b,k;
} lines[N];

ld X(ll u,ll v){
	return -(ld)(lines[u].b-lines[v].b)/(lines[u].k-lines[v].k);
}

int main(){
	scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
	for(ll i=1;i<=n;i++)scanf("%lld",&x[i]);
	for(ll i=1;i<=n;i++)s[i]=s[i-1]+x[i];
	ll l=1,r=2;
	lines[0]=(Line){0,0};
	q[1]=0;
	for(ll i=1;i<=n;i++){
		while(r-l>=2&&X(q[l],q[l+1])<s[i])l++;
		ll j=q[l];
		f[i]=f[j]+a*s[j]*s[j]-b*s[j]-2*a*s[j]*s[i]+a*s[i]*s[i]+b*s[i]+c;
		lines[i]=(Line){f[i]+a*s[i]*s[i]-b*s[i],-2*a*s[i]};
		while(r-l>=2&&X(i,q[r-1])<X(q[r-1],q[r-2]))r--;
		q[r++]=i;
	}
	printf("%lld\n",f[n]);
	return 0;
}
