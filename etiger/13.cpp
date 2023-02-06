#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("ceasar.in","r",stdin);
	freopen("ceasar.out","w",stdout);
	for(int i=0;i<3;i++)
	{
		char c;
		cin>>c;
		if(c<'z')cout<<(char)(c+1)<<" ";
		else cout<<"a ";
	}
	cout<<endl;
	return 0;
}
