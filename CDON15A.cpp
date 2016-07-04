#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define si(n)  scanf("%d", &n)
    #define sc(n)  scanf("%c", &n)
    #define sl(n) scanf("%lld", &n)
    #define sf(n) scanf("%f", &n)
    #define ss(n) scanf("%s", n);
#define ll long long

int main()
{
ll x1,y1,x2,y2,r,n,i;
sl(x1);
sl(y1);

sl(n);
bool f=1;
for(i=0;i<n;i++)
{
    cin>>x2;
    cin>>y2;
    sl(r);
    ll a=r*r;
    ll b=(x1*x1)+(x2*x2)-(2*x1*x2)+(y1*y1)+(y2*y2)-(2*y1*y2);
   // cout<<a<<" "<<b;
    if(a>=b)
    {
        f=0;
    }
}
if(f==0)
    cout<<"DEAD";
else
    cout<<"ALIVE";
}
