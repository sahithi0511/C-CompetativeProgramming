#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    bool checkCycle(int node,int par,vector<int>&vis,vector<int>adj[])
    {
       vis[node]=1;
       for(auto it:adj[node])
       {
           if(!vis[it])
           {
               if(checkCycle(it,node,vis,adj))return true;
           }
           else if(it!=par)return true;
       }
       return false;
    }
    public:
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<int>vis(V,0);
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	           if(checkCycle(i,-1,vis,adj)) return true; 
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
        cin>>V>>E;
        vector<int>adj[V];
        for(int i=0;i<E;i++)
        {
            int n1,n2;
            cin>>n1>>n2;
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }
        Solution ob;
        bool res=ob.isCycle(V,adj);
        if (res)
        cout<<"1"<<"\n";
         else cout<<"0"<<"\n";
    }
    return 0;
}