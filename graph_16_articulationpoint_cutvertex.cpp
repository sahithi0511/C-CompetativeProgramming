#include<bits/stdc++.h>
using namespace std;
void dfs(int node,int parent,int timer,vector<int>adj[],vector<int>&vis,vector<int>&low,vector<int>&time,vector<int>&articulation)
{
    vis[node]=1;
    low[node]=time[node]=timer++;
    int child=0;
    for(auto it:adj[node])
    {
        if(it==parent)continue;
        if(!vis[it])
        {
            dfs(it,node,timer,adj,vis,low,time,articulation);
            low[node]=min(time[node],time[it]);
            if((low[it]>=time[node])&& (parent!=-1))
            {
                articulation[it]=1;
            }
            child++;
        }
        else
        {
            low[node]=min(time[node],time[it]);
        }
        

    }
    if ((parent==-1) && (child>1))
    {
        articulation[node]=1;
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
    vector<int>articulation(v,0);
    int timer=0;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            dfs(i,-1,timer,adj,vis,low,time,articulation);
        }
    }
    for(int i=0;i<v;i++)
    {
        if(articulation[i]==1)
        {
            cout<<i<<"\n";
        }
    }
}