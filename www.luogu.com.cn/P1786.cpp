#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Id
{
	int id;
	string name;
	ll job,bang,lvl;
} id[120];

int n;

bool cmp1(const Id& a,const Id& b)
{
	if(a.bang!=b.bang)
	{
		return a.bang>b.bang;
	}
	else
	{
		return a.id<b.id;
	}
}

bool cmp2(const Id& a,const Id& b)
{
	if(a.job!=b.job)
	{
		return a.job<b.job;
	}
	else if(a.lvl!=b.lvl)
	{
		return a.lvl>b.lvl;
	}
	else
	{
		return a.id<b.id;
	}
}

string jobs[20]={"BangZhu","FuBangZhu","HuFa","ZhangLao","TangZhu","JingYing","BangZhong"};

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string tmp;
		id[i].id=i;
		cin>>id[i].name>>tmp>>id[i].bang>>id[i].lvl;
	}
	
	sort(id+4,id+1+n,cmp1);
	
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			id[i].job=0;
		}
		else if(2<=i&&i<=3)
		{
			id[i].job=1;
		}
		else if(4<=i&&i<=5)
		{
			id[i].job=2;
		}
		else if(6<=i&&i<=9)
		{
			id[i].job=3;
		}
		else if(10<=i&&i<=16)
		{
			id[i].job=4;
		}
		else if(17<=i&&i<=41)
		{
			id[i].job=5;
		}
		else
		{
			id[i].job=6;
		}
	}
	
	sort(id+1,id+1+n,cmp2);
	
	for(int i=1;i<=n;i++)
	{
		cout<<id[i].name<<" "<<jobs[id[i].job]<<" "<<id[i].lvl<<endl;
	}
	
	return 0;
}
