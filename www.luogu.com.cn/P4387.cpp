#include<bits/stdc++.h>
using namespace std;

const int N=100010;
int x[N],y[N];

stack<int> stk;

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        while(!stk.empty())stk.pop();
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<=n;i++)cin>>y[i];
        int pos=1;
        for(int i=1;i<=n;i++)
        {
            stk.push(x[i]);
            while(!stk.empty()&&stk.top()==y[pos])
            {
                stk.pop();
                ++pos;
            }
        }
        if(!stk.empty())cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
