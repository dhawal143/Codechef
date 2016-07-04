#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s="";
        int n,i=97;
        scanf("%d",&n);
        while(n>0)
        {
            s=s+char(i);
            n--;
            i++;
            if(i==123)
                i=97;
        }
        cout<<s<<"\n";
    }
}
