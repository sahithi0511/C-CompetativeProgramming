# include<bits/stdc++.h>
using namespace std;
class Graph
{
    public:
    vector<int>bfs_graph(int k,int n,vector<int>v[])
    {
        vector<int>bfs;
        vector<int>visited(n+1,0);
        queue<int>q;
        visited[k]=1;
        q.push(k);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            bfs.push_back(node);           
            for(auto it:v[node])
            {
                if(!visited[it])
                {

                    q.push(it);
                    visited[it]=1;
                }
            }
        }
            return bfs;

    }

};
int main()
{
    int n,e,k;
    cin>>n>>e;
    vector<int>v[n+1];
    for(int i=0;i<e;i++)
    {
        if(i==0)
        {
            
            int n1,n2;
            cin>>n1>>n2;
            k=n1;
            v[n1].push_back(n2);
            v[n2].push_back(n1);
        }
        else
        {
            int n1,n2;
            cin>>n1>>n2;
            v[n1].push_back(n2);
            v[n2].push_back(n1);
        }
        

    }
    Graph g;
    vector<int>ans=g.bfs_graph(k,n,v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}