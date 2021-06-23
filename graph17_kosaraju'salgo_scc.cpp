#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>&vis,stack<int>&st,vector<int>adj[])
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,st,adj);
        }
    }
    st.push(node);
}
void revdfs(int node,vector<int>&vis,vector<int>transpose[])
{
    
    cout<<node<<" ";
    vis[node]=1;
    for(auto it:transpose[node])
    {
        if(!vis[it])
        {
            revdfs(it,vis,transpose);
        }
    }
}
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
    }
    stack<int>st;
    vector<int>vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,st,adj);
        }
    }
    vector<int>transpose[n];
    for(int i=0;i<n;i++){
        vis[i]=0;
        for(auto it:adj[i])
        {
            transpose[it].push_back(i);
    }
    }
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(!vis[node])
        {
            revdfs(node,vis,transpose);
            cout<<"\n";
        }
        
    }
    return 0;
}