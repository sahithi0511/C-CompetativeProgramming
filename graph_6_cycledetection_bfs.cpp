#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkForCycle(int s, int V, vector<int> adj[], vector<int>& visited)
    {
        vector<int> parent(V, -1);
     
        // Create a queue for BFS
        queue<pair<int,int>> q;
     
        visited[s] = true;
        q.push({s, -1});
     
        while (!q.empty()) {
     
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
     
            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)
                    return true;
            }
        }
        return false;
    }
public:
	bool isCycle(int V, vector<int>adj[]){
	    vector<int> vis(V, 0); 
	    for(int i = 0;i<V;i++) {
	        if(!vis[i]) {
	            if(checkForCycle(i, V, adj, vis)) return true; 
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
        else
            cout<<"0"<<"\n";
    }
    return 0;
}