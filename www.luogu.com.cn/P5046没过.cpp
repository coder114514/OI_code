// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {  // ch ��������ʱ
    if (ch == '-') w = -1;        // �ж��Ƿ�Ϊ��
    ch = getchar();               // ��������
  }
  while (ch >= '0' && ch <= '9') {  // ch ������ʱ
    x = x * 10 + (ch - '0');  // ���¶�������֡��ӡ��� x �ĺ���
    // x �� int ���ͣ�char ���͵� ch �� ��0�� �ᱻ�Զ�תΪ���Ӧ��
    // ASCII �룬�൱�ڽ� ch ת��Ϊ��Ӧ����
    // �˴�Ҳ����ʹ�� (x<<3)+(x<<1) ��д�������� x*10
    ch = getchar();  // ��������
  }
  return x * w;  // ���� * ������ = ʵ����ֵ
}

inline void write(ll x) {
  static int sta[100];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + 48);  // 48 �� '0'
}

const int N=1e5+9,NB=709;

int n,m,x[N],y[N],id[N];
//pre[x]��x�������ڿ���׵������ڵ����������
//suf[x]: x�������ڿ��β�������ڵ����������
//F[i][j]: ��i����j����������ڵ����������
//cnt[i][j]: ǰi����С�ڵ���j��Ԫ������ 
ll pre[N],suf[N],F[NB][NB],cnt[NB][N],ans;
//�ֿ� 
int bel[N],L[NB],R[NB],bSize;
///////////////////////BIT
int bit[N];

void clear_bit()
{
	memset(bit,0,sizeof(bit));
}

void add(int p,int d)
{
	for(int i=p;i<=n;i+=i&-i)bit[i]+=d;
}

int psq(int p)
{
	int sum=0;
	for(int i=p;i>0;i-=i&-i)sum+=bit[i];
	return sum;
}
////////////////////////////
int a[N],b[N],la,lb;
ll merge(int*a,int*b,int la,int lb)
{
	ll ia=1,ib=1,res=0;
	while(ia<=la&&ib<=lb)
	{
		if(a[ia]<b[ib])++ia;
		else res+=la-ia+1,++ib;
	}
	return res;
}
////////////////////////////
void init()
{
	/////////�ֿ� 
//	bSize=n/(sqrt(m)+1)+1;
	bSize=350;
	for(int i=1;i<=n;i++)bel[i]=(i-1)/bSize+1;
	for(int i=1;i<=bel[n];i++)
	{
		L[i]=R[i-1]+1;
		R[i]=i*bSize;
	}
	R[bel[n]]=n;
	////////��pre��suf,�������� 
	for(int i=1;i<=bel[n];i++)
	{
		memcpy(cnt[i],cnt[i-1],sizeof(cnt[0]));
		sort(y+L[i],y+R[i]+1);
		ll nrp=0;
		clear_bit();
		for(int j=L[i];j<=R[i];j++)
		{
			cnt[i][x[j]]++;
			add(x[j],1);
			nrp+=psq(n)-psq(x[j]);
			pre[j]=nrp;
		}
		F[i][i]=nrp;
		nrp=0;
		clear_bit();
		for(int j=R[i];j>=L[i];j--)
		{
			add(x[j],1);
			nrp+=psq(x[j]-1);
			suf[j]=nrp;
		}
//		cout<<i<<","<<bel[n]<<endl;
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<L[bel[i]]<<","<<i<<","<<pre[i]<<endl;
//	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<i<<","<<R[bel[i]]<<","<<suf[i]<<endl;
//	}
//	cout<<"MARK"<<endl;
	/////////////����cnt 
	for(int i=1;i<=bel[n];i++)
	{
		for(int j=1;j<=n;j++)
		{
			cnt[i][j]+=cnt[i][j-1];
		}
	}
	/////////////����F
	for(int k=1;k<bel[n];k++)
	{
		for(int i=1;i<=bel[n];i++)
		{
			if(i+k>bel[n])break;
			int j=i+k;
			F[i][j]=F[i+1][j]+F[i][j-1]-F[i+1][j-1]+merge(y+L[i]-1,y+L[j]-1,R[i]-L[i]+1,R[j]-L[j]+1);
		}
	}
//	for(int i=1;i<=bel[n];i++)
//	{
//		for(int j=1;j<=bel[n];j++)
//		{
//			cout<<i<<","<<j<<","<<F[i][j]<<endl;
//		}
//	}
}
/////////////////////
ll solve(int l,int r)
{
	if(bel[l]==bel[r])
	{
		la=lb=0;
		for(int i=L[bel[l]];i<=R[bel[l]];i++)
		{
			if(id[y[i]]>=l&&id[y[i]]<=r)b[++lb]=y[i];
			else if(id[y[i]]<l)a[++la]=y[i];
		}
		ans=pre[r]-(l==L[bel[l]]?0:pre[l-1])-merge(a,b,la,lb);
		return ans;
	}
	else
	{
		ans=F[bel[l]+1][bel[r]-1]+pre[r]+suf[l];
//		cout<<ans<<endl;
		for(int i=l;bel[i]==bel[l];i++)//ͳ��x[i]>���е� 
		{
			ans+=cnt[bel[r]-1][x[i]-1]-cnt[bel[l]][x[i]-1];
		}
//		cout<<ans<<endl;
		for(int i=r;bel[i]==bel[r];i--)//ͳ��x[i]<���е� 
		{
			ans+=cnt[bel[r]-1][n]-cnt[bel[l]][n]-cnt[bel[r]-1][x[i]]+cnt[bel[l]][x[i]];
		}
//		cout<<ans<<endl;
		la=lb=0;
		for(int i=L[bel[l]];i<=R[bel[l]];i++)
		{
			if(id[y[i]]>=l)a[++la]=y[i];
		}
		for(int i=L[bel[r]];i<=R[bel[r]];i++)
		{
			if(id[y[i]]<=r)b[++lb]=y[i];
		}
		ans+=merge(a,b,la,lb);
		return ans;
	}
}

int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)y[i]=x[i]=read(),id[x[i]]=i;
	init();
	for(int i=1;i<=m;i++)
	{
		ll l,r;
		l=read()^ans;
		r=read()^ans;
		printf("%lld\n",solve(l,r));
	}
	return 0; 
}
