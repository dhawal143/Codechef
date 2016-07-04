#include<iostream>
using namespace std;
int a[1000010];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,f=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];

        }
        for(int i=0;i<n;i++)
        {
            if((i>=2)&&(a[i]==a[i-1])&&(a[i-1]==a[i-2]))
            {
                f=1;
                cout<<"Yes\n";
                break;
            }
        }
        if(f==0)
        {
            cout<<"No\n";
        }

    }

}
