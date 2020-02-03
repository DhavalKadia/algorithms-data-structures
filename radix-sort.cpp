#include<iostream>
using namespace std;

int *input,**bucket,**counter,top[10],n,digit=0,i,j,temp;

void init();
void show();

int main()
{
    int z,div=1,extract,t;

    init();

    for(z=0;z<digit;z++)
    {

        bucket=new int*[10];
        for(i=0;i<10;i++)
            bucket[i]=new int[counter[z][i]];

        for(i=0;i<10;i++)
            top[i]=0;

        for(i=0;i<n;i++)
        {
            extract=(input[i]/div)%10;
            bucket[extract][top[extract]]=input[i];
            top[extract]++;
        }

        div*=10;
        t=0;

        for(i=0;i<10;i++)
            for(j=0;j<counter[z][i];j++)
                {
                    input[t]=bucket[i][j];
                    t++;
                }
    }

    cout<<"\nOUTPUT=";
    for(i=0;i<n;i++)
        cout<<"  "<<input[i];

    return 1;
}

void init()
{
    int maxn=0;
    cout<<"Enter size of Array: ";
    cin>>n;

    input=new int[n];

    for(i=0;i<n;i++)
    {
        cout<<"\nEnter value= ";
        cin>>input[i];
    }

    for(i=0;i<n;i++)
        if(input[i]>maxn)
            maxn=input[i];

    while(maxn>0)
    {
        maxn/=10;
        digit++;
    }

    counter=new int*[digit];
    for(i=0;i<digit;i++)
        counter[i]=new int[10];

    for(i=0;i<digit;i++)
        for(j=0;j<10;j++)
            counter[i][j]=0;

    for(i=0;i<n;i++)
    {
        temp=input[i];
        for(j=0;j<digit;j++)
            {
                counter[j][temp%10]++;
                temp/=10;
            }
    }
}

void show()
{
    cout<<"\nDEBUG : ";
        for(i=1;i<n;i++)
        cout<<"  "<<input[i];
}
