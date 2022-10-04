#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		bool prime=true;
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				prime=false;
				break;
			}
		}
		if(prime)cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}
