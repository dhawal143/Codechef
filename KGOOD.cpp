#include<iostream>
using namespace std;
#include<cstring>
#include<algorithm>
#define ll long long
ll a[30],b[100000];
int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        fill_n(a,30,0);
        fill_n(b,100000,0);
        string str;
        cin>>str;
        ll k,len;
        cin>>k;
        len=str.length();
        for(int i=0;i<len;i++)
        {
            char ch=str[i];
            int c=(int)ch;
            c=c-97;
            a[c]++;
        }
        sort(a,a+26);
        int i;
        for(i=0;i<26;i++)
        {
            if(a[i]>0)
            {
                break;
            }
        }
        int j=i;
        ll s;
        for(;i<26;i++)
        {
            if(a[i]>a[j]+k)
            {
                s+=a[i]-a[j]-k;
            }
        }
       int m=25;
        ll s1=0;
        for(i=25;i>=j;i--)
        {
            if(a[m]>a[i]+k)
            {
                s1+=a[i];
                }
        }
        if(s1<s)
            s=s1;
        cout<<s<<"\n";
    }
}
