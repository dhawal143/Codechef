#include<bits/stdc++.h>

    using namespace std;
    #define ll long long
    #define MOD 1000000007
    #define infi (int)1e9

string w[30];
int count[1000];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        string x,x1;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>w[i];
        }
        x=w[0];
        if(n>1)
        {
            int m=0;
            x1=w[1];
            int l=x.length(), l1=x1.length();
            if(l<l1)
            {
                for(i=0;i<l;i++)
                {
                    if(x1[i]==x[i])
                    {
                        count[m]=count[m]+1;
                    }
                    else
                    {
                        m++;
                    }
                }
            }

        }
        for(i=1;i<n;i++)
        {

        }
    }
}
