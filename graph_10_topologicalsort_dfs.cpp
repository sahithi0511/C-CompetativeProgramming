#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //dfs for topological sort
    void dfstopo(int node,stack<int>&st,vector<int>&vis,vector<int>adj[])
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfstopo(it,st,vis,adj);
            }
        }
        st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>vis(V,0);
	    stack<int> st;
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==0)
	        {
	            dfstopo(i,st,vis,adj);
	        }
	    }
	    vector<int>sorttopo;
	    while(!st.empty())
	    {
	        sorttopo.push_back(st.top());
	        st.pop();
	    }
	    return sorttopo;
	}
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int V,E;
    cin>>V>>E;
    vector<int>adj[V];
    for(int i=0;i<E;i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        adj[n1].push_back(n2);

    }
    Solution ob;
   vector<int>ans=ob.topoSort(V,adj);
   for(int i=0;i<ans.size();i++)
   {
       cout<<ans[i]<<" ";
   }
   
    }
    return 0;

}