#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define si(n)  scanf("%d", &n)
    #define sc(n)  scanf("%c", &n)
    #define sl(n) scanf("%lld", &n)
    #define sf(n) scanf("%f", &n)
    #define ss(n) scanf("%s", n);
#define ll long long

ll a[1010][1010]={0};
ll c[1000010],d[1000010];
int gcd(ll a, ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    ll t;
    sl(t);
    ll n,k,i,j;
    sl(n);
    sl(k);
    ll a1,b,m;
    sl(a1);
    sl(b);
    sl(m);
    for(i=2;i<=t;i++)
    {
        sl(c[i]);
    }
    for(i=2;i<=t;i++)
    {
        sl(d[i]);
    }

    for(i=1;i<1010;i++)
    {
        a[i][1]=i;
    }
    for(i=2;i<1010;i++)
    {
        for(j=2;j<=i;j++)
        {
            if(a[i][j-1]!=a[i-1][j-1])
           a[i][j]=(((a[i-1][j-1]*a[i][j-1])%MOD)/abs(a[i][j-1]-a[i-1][j-1]));
           else
           a[i][j]=0;
        }
    }
    for(i=2;i<1010;i++)
    {
        for(j=2;j<=i;j++)
        {
            cout<<a[i][j]<<" ";
        }
        ll x;
        sl (x);
        cout<<"\n";
    }
    j=1;
    ll x,y;
    ll res=1;
    while(j<=t)
    {
        if(j>1)
        {
            n=1+(a1 * res + c[j])% m;
            k=1+(b*res + d[j])%n;
        }
        /*for(x=1;x<=n;x++)
        {
            for(y=1;y<=x;y++)
            {
                cout<<a[x][y]<<" ";
            }
            cout<<"\n";
        }*/
        //cout<<n<<" "<<k<<"\n";
        res=1;
        for(i=1;i<=k;i++)
        {
            res=(((res*a[n][i]))/(gcd(res,a[n][i])));
        }
        cout<<res<<"\n";
        j++;
    }
}
