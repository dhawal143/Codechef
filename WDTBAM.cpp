#include<bits/stdc++.h>
using namespace std;
char a[1010],b[1010];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,sum=0,i;
        //char b;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        //cout<<"\n";
        //for(i=0;i<n;i++)
        //{
          //  cout<<a[i];
        //}
        //cout<<" ";
        for(i=0;i<n;i++)
        {
            cin>>b[i];
        }
        for(i=0;i<n;i++)
        {
            if((int)a[i]==(int)b[i])
            {
                sum++;
            }
        }
       // cout<<sum<<"\n";
        long long w, max=0;
        if(sum==n)
        {
            for(i=0;i<=n;i++)
            {
                cin>>w;
            }
            max=w;
        }
        else
        {
            for(i=0;i<=n;i++)
            {
                cin>>w;
                if(i<=sum)
                {
                    if(max<w)
                        max=w;
                }
            }
        }
        cout<<max<<"\n";
    }
}
