#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	bool b3=false;
	bool b7=false;
	bool b2=false;
	bool b1=false;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='3')b3=true;
		if(s[i]=='7')b7=true;
		if(s[i]=='2')b2=true;
		if(s[i]=='1')b1=true;
	}
	if(b3&&b7&&b2&&b1)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}
