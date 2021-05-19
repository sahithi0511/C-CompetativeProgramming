#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int Modex(int x,int y,int m)
{
    if(y==0)
    {
        return 1;
    }
    int k=Modex(x,y/2,m);
    if(y%2==1)
    {
        return ((((1LL*k*k)%m)*x)%m);
    }
    else
    {
        return ((1LL*k*k)%m);
    }
}
int main()
{
    int x,y,m;
    cin>>x>>y>>m;
    cout<<Modex(x,y,m);
    return 0;
}