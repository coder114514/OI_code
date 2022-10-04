#include<bits/stdc++.h>
using namespace std;

string from,to;
string A[11],B[11];
int nRules,ans=-1;
queue<string> q;
map<string,int> vis;

string trans(string str,string from,string to,int start_pos)
{
    // cout<<str<<" "<<from<<" "<<to<<endl;
    if(start_pos+from.size()>str.size())return "";
    bool found=true;
    for(int i=0;i<from.size();i++)
    {
        if(str[start_pos+i]!=from[i])
        {
            found=false;
            break;
        }
    }
    if(!found)return "";
    string seg1=str.substr(0,start_pos);
    string seg3=str.substr(start_pos+from.size());
    return seg1+to+seg3;
}

int main()
{
    cin>>from>>to;
    while(cin>>A[nRules+1]>>B[nRules+1])
    {
        ++nRules;
    }
    q.push(from);
    vis[from]=0;
    while(!q.empty())
    {
        string cur=q.front();
        q.pop();
        // cout<<cur<<endl;
        if(cur==to)
        {
            ans=vis[cur];
            break;
        }
        for(int iRule=1;iRule<=nRules;iRule++)
        {
            for(int u=0;u<cur.size();u++)
            {
                string res=trans(cur,A[iRule],B[iRule],u);
                // if(res!="")cout<<vis.count(res)<<endl;
                if(res!=""&&vis.count(res)==0)
                {
                    // cout<<res<<endl;
                    vis[res]=vis[cur]+1;
                    q.push(res);
                }
            }
        }
    }
    if(ans==-1)cout<<"NO ANSWER!"<<endl;
    else cout<<ans<<endl;
    return 0;
}