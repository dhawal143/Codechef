#include<iostream>
#include<algorithm>
#include<cstdio>
#include<array>
#include<algorithm>
using namespace std;

#define gc getchar_unlocked
void readInt(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

struct data{
    	int s;
    	int f;
    };

    bool operator<(data const &a,data const &b)
    {
        return(a.f!=b.f)?(a.f<b.f):(a.s<b.s);
    }
    int a[1000010];
    int b[1000010];
    int main()
    {
        int n,q,i;
        readInt(n);readInt(q);
        data arr[n];
        fill_n(a,1000010,0);
        fill_n(b,1000010,0);
        for(i=0;i<n;i++)
        {
            readInt(arr[i].s);
            readInt(arr[i].f);
        }
    		sort(arr,arr+n);
    		for(i=0;i<n;i++)
            {
                if(a[i]==0)
                {
                    a[i]=arr[i].s;
         //           b[i]
                }
                else
                {
                    while(a[i]!=0)
                        i++;
                    a[i]=arr[i].s;
                }
            }
    		for(i=0;i<q;i++)
    		{
    		    int start,finish;
    			readInt(start);
    			readInt(finish);
                int cnt=0;
                int cur=0;
                int first=0,no=0;
                for(int j=0;j<n;j++)
                {
                    if(first==0)
                    {
                        if(arr[j].s>=start)
                        {
                            if(arr[j].f<=finish)
                            {
                                cur=j;cnt++;
                                first=1;
                            }
                            else
                            {
                                no=1;
                            }
                        }
                    }
                    if(no==1)
                    {
                        break;
                    }
                    if(first==1)
                    {
                        if(arr[j].s>=arr[cur].f)
                        {
                            if(arr[j].f<=finish)
                            {
                                cur=j;cnt++;
                            }
                            else
                            {
                                no=1;
                            }
                        }
                    }
                }
                printf("%d\n",cnt);
    		}
    	return 0;
    }

