#include<bits/stdc++.h>

    using namespace std;
#define s(x) scanf("%d" , &x)
#define M 1000000007
long long int arr[100000];
long long int segment[500000] , lazy1[500000] , lazy2[500000];
long long int get_sum(int index , int start , int end , int low , int high)
{   if(lazy1[index] != 0 || lazy2[index] != 1)
    {
        segment[index] = (segment[index] * lazy2[index]) % M;
        segment[index] = (segment[index] + (lazy1[index]*(end - start + 1))%M) % M;
        if(start != end)
        {
            lazy1[2 * index] = (lazy1[2 * index] * lazy2[index]) % M;
            lazy1[2 *index] = (lazy1[2 * index] + lazy1[index]) % M;
            lazy1[2 * index + 1] = (lazy1[2 * index + 1] * lazy2[index]) % M;
            lazy1[2 * index + 1] = (lazy1[2 * index + 1] + lazy1[index]) % M;
            lazy2[2 *index] = (lazy2[2 * index] * lazy2[index]) % M;
            lazy2[2 * index + 1] = (lazy2[2 * index + 1] * lazy2[index]) % M;
        }
        lazy1[index] = 0;
        lazy2[index] = 1;
    }
if(low > end || high < start)
        return 0;
    if(low <= start && high >= end)
    {
        return segment[index];
    }
    int mid = (start + end) >> 1;
    long long int q1 = get_sum(2 * index , start , mid , low , high);
    long long int q2 = get_sum(2 * index + 1 , mid + 1 , end , low , high);
    return (q1 + q2) % M;
}
void update_segment(long long int val1 , long long int val2 , int index , int start , int end , int low , int high)
{
    if(lazy1[index] != 0 || lazy2[index] != 1)
    {
        segment[index] = (segment[index] * lazy2[index]) % M;
        segment[index] = (segment[index] + (lazy1[index]*(end - start + 1))%M) % M;
        if(start != end)
        {
            lazy1[2 * index] = (lazy1[2 * index] * lazy2[index]) % M;
            lazy1[2 *index] = (lazy1[2 * index] + lazy1[index]) % M;
            lazy1[2 * index + 1] = (lazy1[2 * index + 1] * lazy2[index]) % M;
            lazy1[2 * index + 1] = (lazy1[2 * index + 1] + lazy1[index]) % M;
            lazy2[2 *index] = (lazy2[2 * index] * lazy2[index]) % M;
            lazy2[2 * index + 1] = (lazy2[2 * index + 1] * lazy2[index]) % M;
        }
        lazy1[index] = 0;
        lazy2[index] = 1;
    }
    if(low > end || high < start)
        return;
    if(low <= start && high >= end)
    {
        segment[index] = (segment[index] * val1) % M;
        segment[index] = (segment[index] + (val2 * (end - start + 1))%M) % M;
        if(start != end)
        {
            lazy1[2 * index] = (lazy1[2 * index] * val1) % M;
            lazy1[2 * index] = (lazy1[2 * index] + val2) % M;
            lazy1[2 * index + 1] = (lazy1[2 * index + 1] * val1) % M;
            lazy1[2 * index + 1] = (lazy1[2 * index + 1] + val2) % M;
            lazy2[2 *index] = (lazy2[2 * index] * val1) % M;
            lazy2[2 * index + 1] = (lazy2[2 * index + 1] * val1) % M;
        }
        lazy1[index] = 0;
        lazy2[index] = 1;
        return;
    }
    int mid = (start + end) >> 1;
    update_segment(val1 , val2 , 2 * index , start , mid , low , high);
    update_segment(val1 , val2 , 2 * index + 1 , mid + 1 , end , low , high);
    segment[index] = (segment[2 * index] + segment[2 * index + 1]) % M;
}
void construct(int index , int start , int end)
{
    if(start == end)
    {
        segment[index] = arr[start - 1];
        return;
    }
    int mid = (start + end) >> 1;
    construct(2 * index , start , mid);
    construct(2 * index + 1 , mid + 1 , end);
    segment[index] = (segment[2 * index] + segment[2 * index + 1]) % M;
}
int main()
{
    int n , q , i , j , type , x , y;
    long long int v;
    scanf("%d" , &n);
    scanf("%d" , &q);
    for(i = 0; i < n; i ++)
        scanf("%lld" , &arr[i]);
    construct(1 , 1 , n);
    for(i = 0; i < 500000; i ++)
    {
        lazy1[i] = 0;
        lazy2[i] = 1;
    }
    while(q --)
    {
        scanf("%d%d%d" , &type , &x , &y);
        if(type == 1)
        {
            scanf("%lld" , &v);
           update_segment(1 , v , 1 , 1 , n , x , y);
        }
        else if(type == 2)
        {
            scanf("%lld" , &v);
            update_segment(v , 0 , 1 , 1 , n , x , y);
        }
        else if(type == 3)
        {
            scanf("%lld" , &v);
            update_segment(0 , v , 1 , 1 , n , x , y);
        }
        else
        {
            printf("%lld\n" , (get_sum(1 , 1 , n , x , y))%M);
        }
    }
    return 0;
}
