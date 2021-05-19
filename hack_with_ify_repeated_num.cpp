#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,n,i,j,ele,g,k,m,max=0,number=0,c=0;
    cin>>t;
    for(i=0;i<t;i++)
    {
       vector<int> arr;
       vector<int> numarr;
       cin>>n;
       for(j=0;j<n;j++)
       {
           cin>>ele;
           arr.push_back(ele);
       }
       for(g=0;g<n;g++)
       {
        for(k=g+1;k<n;k++)
       {
           
           if(k==n-1)
             {
                 if(arr[g]==arr[k] && arr[k-1]==arr[g] && arr[k+1]==arr[g])
                 {
                     c+=1;
                 }
                 else if(arr[g]==arr[k] && arr[k-1]!=arr[g]) 
                   {
                               c+=1;
                    }
                  numarr.push_back(arr[g]);
                  numarr.push_back(c);
                  c=0;
                  break;
             }
         if(arr[g]==arr[k] && arr[k-1]==arr[g] && arr[k+1]==arr[g])
                 {
                     c+=1;
                 }
         else if(arr[g]==arr[k] && arr[k-1]!=arr[g]) 
         {
             c+=1;
         }
         
       }
       
    }
    m=sizeof(numarr)/sizeof(numarr[0]);
//     cout<<"m is"<<m<<"\n";
//     for(g=0;g<m;g++)
//     {
//         cout<<numarr[g]<<" ";
//     }
//     }
// }
    for(g=1;g<m-2;g+=2)
    {
        if(numarr[g]>=numarr[g+2])
        {
            max=numarr[g];
            number=numarr[g-1];
        }
        else{
            max=numarr[g+2];
            number=numarr[g-1];
        }
    }
    cout<<number<<" ";
    
  }
}