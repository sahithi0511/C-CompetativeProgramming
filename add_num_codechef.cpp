#include<bits/stdc++.h>
using namespace std;
void add()
{
    string n1,n2;
    cin>>n1>>n2;
    int l_n1=n1.size()-1,l_n2=n2.size()-1,c=0;
     stack<int>v;
     while(l_n1!=0 || l_n2!=0)
     {
         if(l_n1!=0)
         {
             c+=n1[l_n1]-'0';
             l_n1--;
         }
         if(l_n2!=0)
         {
             c+=n2[l_n2]-'0';
             l_n2--;
         }
         if(c>9)
         {
             v.push(c-10);
             c=1;
         }
         else
         {
             v.push(c);
             c=0;
         }
     }
     if(c>0)
     {
         v.push(c);
     }
     for(int i=v.size()-1;i>=0;i--)
     {
         cout<<v.top();
         v.pop();
     }
     cout<<"\n";
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        add();
    }
    return 0;
}