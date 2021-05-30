#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e,source;
    cin>>n>>e;
    vector<pair<int,int>>v[n+1];
    for(int i=0;i<e;i++)
    {
        int n1,n2,w;
        cin>>n1>>n2>>w;
        v[n1].push_back(make_pair(n2,w));
        v[n2].push_back(make_pair(n1,w));
    }
    cin>>source;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(n+1,INT_MAX);
    dist[source]=0;
    pq.push(make_pair(0,source));
    while(!pq.empty())
    {
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        vector<pair<int,int>>::iterator it;
        for(auto it:v[node])
        {
            int f,sec;
            f=it.first;
            sec=it.second;
            if(dist[f]>(d+sec))
            {
                dist[f]=d+sec;
                pq.push(make_pair(dist[f],f));
            }
            
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }

}