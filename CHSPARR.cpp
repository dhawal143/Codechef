#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define mod 1000000007
ll a[100010];
ll pw3[40],pw2[40];
void powr3()
{
    pw3[0]=1;
    for(int i=1;i<=30;i++)
    {
       pw3[i]=(pw3[i-1]*3)%mod;
    }
}
void powr2()
{
    pw2[0]=1;
    for(int i=1;i<=30;i++)
    {
       pw2[i]=(pw2[i-1]*2)%mod;
    }
}

ll tsum(ll m,ll a,ll b)
{
    return (((pw3[m]-1)*(a+b))%mod)/2;
}
ll v(ll m,ll a,ll b,ll x)
{
    if(x==0)
        return 0;
   else if(x<=(pw2[m-1]-1))
      return v(m-1,a,a+b,x);
    else
        return (tsum(m-1,a,a+b)+(a+b+v(m-1,a+b,b,x-pw2[m-1]))%mod)%mod;
}
int main()
{
    powr2();
    powr3();
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,x,y,xsum=0,ysum=0,ans;
        sl(n);
        sl(m);
        sl(y);
        sl(x);
        fill_n(a,100010,0);
        for(int i=0;i<n;i++)
        {
            sl(a[i]);
        }
        a[n]=0;
        int i=0;
        while(x>=pw2[m])
        {
            x=x-pw2[m];
            xsum=(xsum+(a[i]+tsum(m,a[i],a[i+1])))%mod;
            i++;
        }
        if(x!=0)
        xsum=(xsum+(a[i]+v(m,a[i],a[i+1],x-1)))%mod;
        i=0;
        y=y-1;
        while(y>=pw2[m])
        {
            y=y-pw2[m];
            ysum=(ysum+(a[i]+tsum(m,a[i],a[i+1])))%mod;
            i++;
        }
        if(y!=0)
        ysum=(ysum+(a[i]+v(m,a[i],a[i+1],y-1)))%mod;
        cout<<xsum-ysum<<"\n";

    }
}
