#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
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
	    while(!q.empty())
	    {
	        int n=q.front();
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
	   return topo;
	}
};
int check(int V,vector<int>&res,vector<int>adj[])
{
    vector<int>map(V,-1);
    for(int i=0;i<V;i++)
    {
        map[res[i]]=i;
    }
    for(int i=0;i<V;i++)
    {
        for(int v:adj[i])
        {
            if(map[i]>map[v]) return 0;
        }
    }
    return 1;
}

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
   vector<int>res=ob.topoSort(V,adj);
   cout<<check(V,res,adj)<<"\n";
    return 0;
}
}