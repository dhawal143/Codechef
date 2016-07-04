#include<bits/stdc++.h>

    using namespace std;
    #define ll long long
    #define MOD 1000000007
    #define infi (int)1e9

    #define si(n)  scanf("%d", &n)
    #define sc(n)  scanf("%c", &n)
    #define sl(n) scanf("%lld", &n)
    #define sf(n) scanf("%f", &n)
    #define ss(n) scanf("%s", n);
    #define all(a) a.begin(), a.end()
    #define f first
    #define s second
    #define pb push_back
    #define mp make_pair
    #define fill(a, v) memset(a, v, sizeof(a))
    #define PI 3.1415926535897932384626
    #define mem(x) memset(x, -1, sizeof(x))
    #define memz(x) memset(x, 0, sizeof(x))
    #define FOR(i,n) for(i=0;i<=n;i++)
    #define FORD(j,n) for(j=n;j>=0;j++)
    #define MAX2(a,b) a>b?a:b
    #define MIN2(a,b) a>b?b:a
    #define REP(i,a,b) for(i=a;i<=b;i++)
    #define REPD(i,a,b) for(i=a;i>=b;i--)

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,d;
        sl(a);
        sl(b);
        sl(c);
        sl(d);
        a=a%c;
        b=b%d;
        ll max,min,add1,add2,val,min1=100000000000001LL;
        if(c>d)
        {
            max=c;
            add1=a;
            min=d;
            add2=b;
        }
        else
        {
            max=d;
            add1=b;
            min=c;
            add2=a;
        }
        if(gcd(max,min)==1)
        {
            min1=0;
        }
        else
        {
            val=gcd(max,min);
            ll val1=abs(add1-add2);
            //cout<<val1<<" ";
            add1=add1%val;
            add2=add2%val;
            min1=abs(add1-add2);
            //cout<<min1<<" ";
            if(add1<add2)
            {
                add1=val+add1;
            }
            else
            {
                add2=val+add2;
            }
            if(min1>abs(add1-add2))
            {
                min1=abs(add1-add2);
            }
            //cout<<min1<<" ";
            if(val1<min1)
            {
                min1=val1;
            }

        }
        cout<<min1<<"\n";
    }
}
