#include<bits/stdc++.h>
using namespace std;

vector<int> c;

void dfs(int n,int last)
{
    for(int i=last;i+i<=n;i++)
    {
        c.push_back(i);
        dfs(n-i,i);
        c.pop_back();
    }
    cout<<c[0];
    for(int i=1;i<c.size();i++)cout<<"+"<<c[i];
    cout<<"+"<<n<<endl;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i+i<=n;i++)
    {
        c.push_back(i);
        dfs(n-i,i);
        c.pop_back();
    }
    return 0;
}