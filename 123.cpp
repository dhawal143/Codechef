#include<iostream>

        using namespace std;

        int zero[20][2];    // stores details about locations where we spit a prime number as (prime number = n +1) and then find
                            // the result for n

        int result[101];    // the result array
        int pos = 0,val=0;  //position of result array and value to be stored next in it

        int printno(int no,int index_zero){ // function to represent a number as factors of 2,3,5,7
                                            // index zero represents the current index of the special array used to store details
                                            // of the position where we reduce a prime number

        int count_two =0, count_three =0, count_five =0, count_seven=0,size = 0;

        while(no%2==0)
        {
            count_two++;
            val = val+2;
            for(int i=0;i<2;i++)
                result[pos++] = val - i;   // fill the result array with 2 numbers in decreasing order
            no /= 2;
        }
        while(no%3==0)
        {
            count_three++;
            val = val+3;
            for(int i=0;i<3;i++)
                result[pos++] = val - i;  // fill the result array with 3 numbers in decreasing order
            no /= 3;
        }
        while(no%5==0)
        {
            count_five++;
            val = val+5;
            for(int i=0;i<5;i++)
                result[pos++] = val - i;  // fill the result array with 5 numbers in decreasing order
            no /= 5;
        }
        while(no%7==0)
        {
            count_seven++;
            val = val+7;
            for(int i=0;i<7;i++)
                result[pos++] = val - i;  // fill the result array with 7 numbers in decreasing order
            no /= 7;
        }

        size = size + count_two + count_three + count_five + count_seven;

        if(no>1)   // if the number is  still >1 means it is a prime so we now find for no -1
        {
            result[pos++] = -1*index_zero;  //mark the position of array to add the subsequence in increasing order
            zero[index_zero][0] = printno(no-1,index_zero+1); // stores the size of LIS ahead of no
            size += zero[index_zero][0];

        }

        return size;
    }

        int main(){

        int test;
        cin>>test;

        while(test--){


            int no;
            cin>>no;
            if(no==1)
                cout<<1<<endl<<1<<endl;
            else{
                for(int i=0; i<101;i++)
                    result[i] = 0;
                for(int i=0; i<20;i++)
                    {
                        zero[i][0] = 0;
                        zero[i][1] = 0;
                    }
                pos =0;
                val = 0;
                printno(no,0);
                int new_add = 0;
                for(int i=pos-1; i>=0 ; i--){

                    if(result[i]>new_add)
                            new_add = result[i];

                    if(result[i]<=0)
                    {

                        zero[-1*result[i]][1] = new_add;
                        new_add += zero[-1*result[i]][0];
                    }

                }
                int add=0,temp_add=0,no_zero=0,zero_start=0;;
                cout<<new_add<<endl;
                for(int i=0; i<pos ; i++)
                {
                     if(result[i] <= 0){

                        zero_start = zero[no_zero][1];

                        for(int j=1;j<=zero[no_zero][0];j++)
                            cout<<zero_start+j<<" ";
                        no_zero++;
                        i++;
                    }
                    cout<<result[i]<<" ";
                }
            cout<<endl;
            }
            }
        }
