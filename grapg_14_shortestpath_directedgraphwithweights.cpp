#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    void dfs(int i,stack<int>&st,vector<int>&vis,vector<pair<int,int>>adj[])
    {
        vis[i]=1;
        for(auto it:adj[i])
        {
            int f=it.first;
            if(!vis[f])
            {
               dfs(f,st,vis,adj);
            }
        }
        st.push(i);
    }
    void topo(int s,int n,vector<pair<int,int>>adj[])
    {
        vector<int>vis(n,0);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,st,vis,adj);
            }
        }
        vector<int>dis(n,INT_MAX);
        dis[s]=0;
        while(!st.empty())
        {
            int t=st.top();
            st.pop();
            if(dis[t]!=INT_MAX)
            {
                for(auto it:adj[t])
                {
                    int n=it.first;
                    int we=it.second;
                    if ((dis[t]+we)<dis[n])
                    {
                        dis[n]=dis[t]+we;
                    }
                    
                }
            }
        }
        for(int i=0;i<n;i++)
        {
           (dis[i]==INT_MAX)?cout<<"infinity":cout<<dis[i]<<" ";
        }

    }

};
int main()
{
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>>adj[n];
    for(int i=0;i<e;i++)
    {
        int n1,n2,w;
        cin>>n1>>n2>>w;
        adj[n1].push_back({n2,w});
    }
    int source;
    cin>>source;
    Solution ob;
    ob.topo(source,n,adj);
}