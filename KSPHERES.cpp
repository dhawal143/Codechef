#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define si(n)  scanf("%d", &n)
    #define sc(n)  scanf("%c", &n)
    #define sl(n) scanf("%lld", &n)
    #define sf(n) scanf("%f", &n)
    #define ss(n) scanf("%s", n);
#define ll long long
ll a[1010]={0},c1[1010]={0},b[1010]={0};
ll s;

int main()
{
    ll n,m,c,i;
    sl(n);
    sl(m);
    sl(c);
    int x,k=0;
    for(i=1;i<=n;i++)
    {
        si(x);
        b[x]++;
    }
    for(i=1;i<=m;i++)
    {
        si(x);
        a[x]++;
    }
    for(i=1;i<=1008;i++)
    {
        if(a[i]!=0&&b[i]!=0)
        {
            c1[k]=a[i]*b[i];
            //cout<<c1[k]<<" ";
            k++;
        }
    }
    //for(i=)
    ll d[1010][1010]={0};
    ll j;
    for(i=0;i<=k;i++)
    {
        d[i][0]=1;
    }
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=i;j++)
        {
            d[i][j]=((c1[i-1]*d[i-1][j-1])+d[i-1][j])%MOD;
            //cout<<d[i][j];
        }
        //cout<<"\n";
    }
    for(i=2;i<=c+1;i++)
    {
        cout<<d[k][i]<<" ";
    }
}
