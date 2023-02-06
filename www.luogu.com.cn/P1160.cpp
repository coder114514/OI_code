#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int n,m;
int head,nxt[N],prv[N];

void del(int id)
{
	if(id==head)
	{
		head=nxt[id];
		prv[head]=0;
		return;
	}
	nxt[prv[id]]=nxt[id];
	prv[nxt[id]]=prv[id];
	nxt[id]=prv[id]=0;
}

void insL(int id,int nid)
{
	if(id==head)
	{
		nxt[nid]=id;
		prv[id]=nid;
		prv[nid]=0;
		head=nid;
		return;
	}
	nxt[nid]=id;
	prv[nid]=prv[id];
	nxt[prv[id]]=nid;
	prv[id]=nid;
}

void insR(int id,int nid)
{
	prv[nid]=id;
	nxt[nid]=nxt[id];
	prv[nxt[id]]=nid;
	nxt[id]=nid;
}

int main()
{
	cin>>n;
	head=1;
	for(int i=2;i<=n;i++)
	{
		int k,p;
		cin>>k>>p;
		if(p==0)
		{
			insL(k,i);
		}
		else
		{
			insR(k,i);
		}
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		del(x);
	}
	int no=head;
	while(no!=0)
	{
		if(no!=head)cout<<" ";
		cout<<no;
		no=nxt[no];
	}
	return 0;
}
