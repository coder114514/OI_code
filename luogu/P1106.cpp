#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string num;
int k;

int main()
{
    cin>>num>>k;
    int n=num.size();
    int m=n-k;
    num=" "+num;
    string ans;
    int last=0;
    for(int j=1;j<=m;j++)
    {
        char c=num[last+1];
        int pos=last+1;
        for(int i=last+2;i<=n-(m-j);i++)
        {
            if(c>num[i])
            {
                c=num[i];
                pos=i;
            }
        }
        ans+=c;
        last=pos;
    }
    while(ans.size()&&ans[0]=='0')ans=ans.substr(1);
    if(!ans.size())ans='0';
    cout<<ans<<endl;
    return 0;
}