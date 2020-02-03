#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

int *input,*counter,*state,*final,i,j,n,maxn=0,minn=1,temp;

void init();

int main()
{
    init();

    /////////////////////////////////////////

    clock_t start, end;
     double cpu_time_used;
     start = clock();

    for(i=0;i<n;i++)
        counter[input[i]]++;

    for(i=1;i<=maxn;i++)
        state[i]=state[i-1]+counter[i];

    for(i=1;i<=maxn;i++)
        for(j=0;j<counter[i];j++)
        {
            final[state[i]]=i;
            state[i]--;
        }

    if(minn<=0)
        for(i=1;i<=n;i++)
            final[i]-=temp;

     end = clock();
     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

     cout<<"\n\n\nTIME="<<cpu_time_used<<"\n\n\n";


    ///////////////////////////////////////////////

    cout<<"\n\nOUTPUT=";
    for(i=1;i<=n;i++)
        cout<<"\t"<<final[i];


    return 1;
}

void init()
{
    cout<<"Enter size of Array: ";
    cin>>n;

    input=new int[n];
    final=new int[n+1];

    for(i=0;i<n;i++)
    {
        //cout<<"\nEnter value= ";
        //cin>>input[i];
        input[i]=rand()%1000;
    }

    for(i=0;i<n;i++)
        {
            if(input[i]>maxn)
                maxn=input[i];
            if(input[i]<minn)
                minn=input[i];
        }

    if(minn<=0)
    {
        temp=minn*(-1) +1;

        for(i=0;i<n;i++)
            input[i]+=temp;

        maxn+=temp;
    }

    counter=new int[maxn+1];
    state=new int[maxn+1];

    for(i=0;i<=maxn;i++)
        counter[i]=state[i]=0;
}
