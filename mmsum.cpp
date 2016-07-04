#include<iostream>
using namespace std;
#define ll long long
ll a[100010];
int main()
{
    ll t,n,s,max1,m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int i;
        ll nm=-1000000001,max2;
        bool f=0,f1=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]>0)
            {
                f=1;
            }
            if(nm<a[i])
                nm=a[i];
        }
        s=a[0];
        max1=a[0];
        for(int j=1;j<n;j++)
        {
            s=max(a[j],s+a[j]);
            max1=max(max1,s);
        }
        max2=max1;
        if(f==1)
        {
            ll temp;
            for(i=0;i<n;i++)
            {
                if(a[i]<0)
                {
                    temp=a[i];
                    a[i]=0;
                    s=a[0];
                    max1=a[0];
                    for(int j=1;j<n;j++)
                    {
                        s=max(a[j],s+a[j]);
                        max1=max(max1,s);
                    }
                    a[i]=temp;
                }
                if(max1>max2)
                {
                    max2=max1;
                }
            }
        }
        cout<<max2<<"\n";
    }
}
