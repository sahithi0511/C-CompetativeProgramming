#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        v.push_back(val%m);
    }
    int q;
    cin>>q;
    vector<int>query;
    for(int i=0;i<q;i++)
    {
        int x;
        cin>>x;
        query.push_back(x);
    }
    
    for(int i=0;i<query.size();i++)
    {
        int max=0;
        for(int j=0;j<v.size();j++)
        {
            if(max<((v[j]+query[i])%m))
            {
                max=((v[j]+query[i])%m);
            }
        }
        cout<<max<<"\n";
    }

}
