#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    // code here
	    queue<int>q;
	    vector<int>indegree(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    vector<int>topo;
	    int c=0;
	    while(!q.empty())
	    {
	        int n=q.front();
	        c++;
	        q.pop();
	        topo.push_back(n);
	        for(auto it:adj[n])
	        {
	            indegree[it]--;
	            if (indegree[it]==0)
	            {
	                q.push(it);
	            }
	        }
	    }
	   if(c==V) return false;
	   return true;
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
   cout<<ob.isCyclic(V,adj)<<"\n";
    }
    return 0;
}