#include<bits/stdc++.h>
using namespace std;
void dfs(int node,int parent,int timer,vector<int>adj[],vector<int>&vis,vector<int>&low,vector<int>&time)
{
    vis[node]=1;
    low[node]=time[node]=timer++;
    for(auto it:adj[node])
    {
        if(it==parent)continue;
        if(!vis[it])
        {
            dfs(it,node,timer,adj,vis,low,time);
            low[node]=min(time[node],time[it]);
            if(low[it]>low[node])
            {
                cout<<it<<" "<<node;
            }
        }
        else
        {
            low[node]=min(time[node],time[it]);
        }
        

    }
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<int>adj[v];
    for(int i=0;i<e;i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    vector<int>vis(v,0);
    vector<int>low(v,-1);
    vector<int>time(v,-1);
    int timer=0;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            dfs(i,-1,timer,adj,vis,low,time);
        }
    }
}