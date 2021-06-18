#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    vector<int>minweights(int s,int n,vector<int>adj[])
    {
        vector<int>dis(n,INT_MAX);
        queue<int>q;
        dis[s]=0;
        q.push(s);
        while(!q.empty())
        {
            int n=q.front();
            int d=dis[n];
            q.pop();
            for(auto it:adj[n])
            {
                if((d+1)<dis[it])
                {
                    dis[it]=d+1;
                    q.push(it);
                }
            }
        }
        return dis;
    }

};
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>adj[n];
    for(int i=0;i<e;i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    int source;
    cin>>source;
    Solution ob;
    vector<int>ans=ob.minweights(source,n,adj);
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}