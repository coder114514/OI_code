#include<bits/stdc++.h>
using namespace std;

string s;
stack<char> stk;

int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='('||s[i]=='[')stk.push(s[i]),cout<<s[i];
        else if(s[i]==')')
        {
            if(!stk.empty()&&stk.top()=='(')stk.pop(),cout<<')';
            else cout<<"()";
        }
        else if(s[i]==']')
        {
            if(!stk.empty()&&stk.top()=='[')stk.pop(),cout<<']';
            else cout<<"[]";
        }
    }
    while(!stk.empty())
    {
        if(stk.top()=='(')stk.pop(),cout<<')';
        else if(stk.top()=='[')stk.pop(),cout<<']';
    }
    return 0;
}
