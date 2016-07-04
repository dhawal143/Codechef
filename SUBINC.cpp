#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,x,k,m,i,sum=0;
        cin>>n;
        cin>>x;
        k=x;
        m=0;
        for(i=2;i<=n;i++)
        {
            cin>>x;
            if(k<=x)
            {
                m=m+1;
            }
            else
            {
                m=0;
            }
            sum=sum+m;
            k=x;
        }
        sum=sum+n;
        cout<<sum<<"\n";
    }
}
