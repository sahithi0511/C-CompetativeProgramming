//Using adjacency matrix if the no of nodes are less it takes n*n complexity
/*# include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n+1][n+1]={0};
    for(int i=1;i<=m;i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        arr[n1][n2]=1;
        arr[n2][n1]=1;
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
*/
//Using adjacency list (vector) for large graphs and takes less complexity (N+2E) and (N+2E)+2E for weighted graphs
# include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v[n+1];
    for(int i=0;i<m;i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    for(int j=0;j<n+1;j++)
    {
        cout<<j<<"\t";
        for(int it : v[j])
        {
            cout<<it<<" ";
        }
        cout<<"\n";
    }
    return 0;
}