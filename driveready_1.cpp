#include<bits/stdc++.h>
using namespace std;
/*int main()
{
    int temp;
    cin>>temp;
    if(temp>=16 && temp<=25)
    {
        cout<<"very cool";
    }
    else if(temp>25 && temp<=32)
    {
        cout<<"cool";
    }
    else if(temp>32)
    {
        cout<<"no effect";
    }
    return 0;
}*/
/*int main()
{
    int n,n1,rev,num=0;
    cin>>n;
    n1=n;
    while(n>0)
    {
       rev=n%10;
       num=num*10+rev;
       n=n/10;
    }
   cout<<num;
    
}*/
/*int main()
{
    int t,n1,n2,k;
    cin>>t;
    for(int i=0;i<t;i++)
    {
       cin>>n1>>n2;
       k=n1+n2;
       cout<<k;
       cout<<"\n";
    }
}*/
/*int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        for(int j=n-1;j>=0;j--)
        {
            if((n&j)==0)
            {
                cout<<j;
                cout<<"\n";
                break;
            }
            else
            {
                n=n&j;
            }
            
        }
    }
    return 0;
}
*/
int main()
{
    int N,sum_mot,sum_pat,tot;
    cin>>N;
    tot=N;
    
    for(int i=1;i<N;i++)
    {
        sum_mot=0;
        sum_pat=0;
        if (tot>0)
        {
        cout<<tot<<"\n";
        sum_pat=i;
        tot-=sum_pat;
        }
        else if (tot==0)
        {
            cout<<tot<<"\n";
            cout<<"Patlu";
            break;
        }
        else if(i*2>=tot)
            {
                cout<<tot<<"\n";
                cout<<"Motu";
                break;
            }
        else
        {
            sum_mot=i*2;
            tot-=sum_mot;
          //  cout<<sum_pat<<"   "<<sum_mot<<"\n";

        }

    }
}