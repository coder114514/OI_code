#include<bits/stdc++.h>
using namespace std;

char convas[1030][1030];

void draw(int x,int y,int k)
{
	if(k==1)
	{
		convas[y][x+1]='/';
		convas[y][x+2]='\\';
		convas[y+1][x]='/';
		convas[y+1][x+1]=convas[y+1][x+2]='_';
		convas[y+1][x+3]='\\';
		return;
	}
	draw(x+(1<<k-1),y,k-1);
	draw(x,y+(1<<k-1),k-1);
	draw(x+(1<<k),y+(1<<k-1),k-1);
}

int main()
{
	memset(convas,' ',sizeof(convas));
	int n;cin>>n;
	draw(1,1,n);
	for(int y=1;y<=(1<<n);y++)
	{
		for(int x=1;x<=(1<<n+1);x++)
		{
			cout<<convas[y][x];
		}
		cout<<endl;
	}
	return 0;
}
