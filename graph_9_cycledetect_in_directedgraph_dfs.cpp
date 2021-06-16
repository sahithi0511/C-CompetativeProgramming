#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    bool detectcycle(int node,int vis[],int cydet[],vector<int>adj[])
    {
        vis[node]=1;
        cydet[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(detectcycle(it,vis,cydet,adj)) return true;
            }
            else if(cydet[it])
            return true;
        }
        cydet[node]=0;
        return false;
    }
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	int vis[V];
	   	int cydet[V];
	   	memset(vis,0,sizeof vis);
	   	memset(cydet,0,sizeof cydet);
	   	for(int i=0;i<V;i++)
	   	{
	   	    if(!vis[i])
	   	    {
	   	        if(detectcycle(i,vis,cydet,adj)){
	   	            return true;
	   	        }
	   	    }
	   	}
	   	return false;
	}
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int V,E;
    vector<int>adj[V];
    cin>>V>>E;
    for(int i=0;i<E;i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        adj[n1].push_back(n2);

    }
    Solution ob;
   cout<<ob.isCyclic(V,adj)<<"\n";
    }
    return 0;
}