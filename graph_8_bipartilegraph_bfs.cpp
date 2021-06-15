#include<bits/stdc++.h>
using namespace std;
bool checkbigraph(int s,vector<int>adj[],int color[])
{
    queue<int>q;
    color[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int n=q.front();
        q.pop();
        for(auto it:adj[n])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[n];
                q.push(it);
            }
            else if(color[it]==color[n]) return false;
        }
    }
    return true;
}
bool bipartile(vector<int>adj[],int N)
{
    int color[N];
    memset(color,-1,sizeof color);
    for(int i=1;i<=N;i++)
    {
        if(color[i]==-1)
        {
            if(!checkbigraph(i,adj,color))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int N,E;
    cin>>N>>E;
    vector<int>adj[N+1];
    for(int i=0;i<E;i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);

    }
    if(bipartile(adj,N))
    {
         cout<<"yes";
    }
    else 
    {
        cout<<"no";
    }

}