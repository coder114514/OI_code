#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("capitalization.in","r",stdin);
	freopen("capitalization.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if('A'<=s[i]&&s[i]<='Z')cout<<s[i];
		else if('a'<=s[i]&&s[i]<='z')cout<<(char)(s[i]-'a'+'A');
		else cout<<s[i];
	}
	cout<<endl;
	return 0;
}
