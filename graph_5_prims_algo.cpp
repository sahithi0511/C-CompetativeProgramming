/*This is prims algorithm in brute force whcih will take time complexity of o(n)^2
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
    int parent[n];
    int key[n];
    bool mst[n];
    for(int i=0;i<=n;i++)
    {
        parent[i]=-1,mst[i]=false,key[i]=INT_MAX;
    }
    parent[0]=-1;
    key[0]=0;
    for(int i=0;i<n-1;i++)
    {
        int mini=INT_MAX,min_node;
        for(int j=0;j<n;j++)//0 0
        {
            if(mst[j]==false && key[j]<mini)
            {
                mini=key[j];
                min_node=j;
            }
            mst[min_node]=true;
        }
        vector<pair<int,int>>::iterator it;
        for(auto it:v[min_node])
        {
            int node=it.first;
            int wt=it.second;
            if (mst[node]==false && wt<key[node])
            {
                parent[node]=min_node,key[node]=wt;
            }//[0,2,max,6,max]
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<parent[i]<<" ";
    }
}*/
//Now we will write efficient method where we will use priority queue which gives the minimum value at top so that we can reduce a forloop for checking min value
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
    int parent[n];
    int key[n];
    bool mst[n];
    for(int i=0;i<=n;i++)
    {
        parent[i]=-1,mst[i]=false,key[i]=INT_MAX;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    parent[0]=-1;
    key[0]=0;
    pq.push({0,0});
     
    for(int i=0;i<n-1;i++)
    {
        int min_node=pq.top().second;
        pq.pop();
        mst[min_node]=true;
        vector<pair<int,int>>::iterator it;
        for(auto it:v[min_node])
        {
            int node=it.first;
            int wt=it.second;
            if (mst[node]==false && wt<key[node])
            {
                parent[node]=min_node,key[node]=wt,pq.push({key[node],node});
            }//[0,2,max,6,max]
        }

    }
    for(int i=0;i<n;i++)
    {
        cout<<parent[i]<<" ";
    }
}
/*The time complexity of this prims with priority queue (N+E)Nlog(N)
 which is way more efficient than o(n)^2 because we have reduces
 one for loop which takes time of o(n) and placed a priority queue
  which takes time complexity of only logn*/