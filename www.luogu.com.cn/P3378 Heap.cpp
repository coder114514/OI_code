#include<bits/stdc++.h>
using namespace std;

int n;
int s[1000009],cnt;

void up(int id)
{
	while(id/2>=1)
	{
		if(s[id]>=s[id/2])return;
		swap(s[id],s[id/2]);
		id/=2;
	}
}

void down(int id)
{
	while(id*2<=cnt)
	{
		int son=id*2;
		if(son+1<=cnt&&s[son]>s[son+1])son++;
		if(s[id]<s[son])return;
		swap(s[id],s[son]);
		id=son;
	}
}

void push(int x)
{
	s[++cnt]=x;
	up(cnt);
}

int top()
{
	return s[1];
}

void pop()
{
	s[1]=s[cnt--];
	down(1);
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int op;
		cin>>op;
		switch(op)
		{
			case 1:
				int x;
				cin>>x;
				push(x);
				break;
			case 2:
				cout<<top()<<endl;
				break;
			case 3:
				pop();
				break;
		}
	}
	return 0;
}
