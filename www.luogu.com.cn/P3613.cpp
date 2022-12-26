#include<bits/stdc++.h>
using namespace std;

const int N=1e7+10,M=1e5+10;

int n,q;
map<pair<int,int>,int> p;

int main()
{
    cin>>n>>q;
    for(int i=1;i<=q;i++)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int i,j,k;
            cin>>i>>j>>k;
            p[make_pair(i,j)]=k;
        }
        else
        {
            int i,j;
            cin>>i>>j;
            cout<<p[make_pair(i,j)]<<endl;
        }
    }
    return 0;
}