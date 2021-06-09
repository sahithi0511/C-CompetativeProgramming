#include<bits/stdc++.h>
using namespace std;
vector<int>graph_dfs(int i,int V,vector<int>&dfs,vector<int>&visited,vector<int>adj[])
{
    dfs.push_back(i);
    visited[i]=1;
    for(auto it:adj[i])
    {
        if(!visited[it])
        {
            graph_dfs(it,V,dfs,visited,adj);
        }
    }
    return dfs;
}
class Solution 
{
    public:
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int>dfs;
	    vector<int>visited(V+1,0);
	    vector<int>ans=graph_dfs(0,V,dfs,visited,adj);
	    return ans;
	}
};
int main()
{
    int V,E;
    cin>>V>>E;
    vector<int>adj[V+1];
    for(int i=0;i<E;i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    Solution s;
    vector<int>res=s.dfsOfGraph(V,adj);
    for(auto it:res)
    {
        cout<<it<<" ";
    }
}
