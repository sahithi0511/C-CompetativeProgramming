#include<bits/stdc++.h>
using namespace std;
int main()
{
    int j,n,m,k,ele,max,i=0,index=0,c=0;
    vector<int>v;
    cin>>n;
    for(m=0;m<n;m++)
    {
        cin>>ele;
        v.push_back(ele);
    }
    k=v[0];
    while(index<n)
    {
        if(index!=1)
        {
            i=index;
        }
     while(i<=i+k)
     {
         max=v[i];
         i++;
         if(i<=k)
         {
         if(max<v[i])
         {
             max=v[i];
         }
         }
     }
     k=max-1;
     index+=max;
     cout<<c<<"\n";
     c++;
    }
//cout<<"Ans is"<<c; 
}

   