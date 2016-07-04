#include<bits/stdc++.h>
using namespace std;
#define si(n)  scanf("%d", &n)
    #define sc(n)  scanf("%c", &n)
    #define sl(n) scanf("%lld", &n)
    #define sf(n) scanf("%f", &n)
    #define ss(n) scanf("%s", n);
#define ll long long
bool has[5000009];
bool is[5000009];
int main()
{
    ll t,i,j;
    for (i = 2; i < 5000007;++i) {
        if(has[i])
            continue;
        for(j = i * 2; j < 5000007; j += i)
        {
            if(i%4==1)
                is[j]=1;
            has[j] = 1;
        }
        if(i%4==1)
            is[i]=1;

    }
    sl(t);
    while(t--)
    {
        ll n;
        sl(n);
        if(is[n]==1)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
}
