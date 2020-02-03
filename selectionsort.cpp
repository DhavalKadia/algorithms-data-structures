#include<iostream>
using namespace std;

void select(int a[],int);

int main()
{
    int a[100],n,i;
    cout<<"Enter size of Array=";
    cin>>n;

    for(i=0;i<n;i++)
        cin>>a[i];

    select(a,n);

    cout<<"\nSorted elements are : ";
    for(i=0;i<n;i++)
        cout<<"\t"<<a[i];

    return 1;
}

void select(int a[],int n)
{
    int min,loc,temp,i,j;
    min=a[0];

    for(i=0;i<n;i++)
    {
        min=a[i];
        loc=i;

        for(j=i+1;j<n;j++)
        {
            if(a[j]<min)
            {
                min=a[j];
                loc=j;
            }
        }

        if(loc!=i)
        {
            temp=a[i];
            a[i]=a[loc];
            a[loc]=temp;
        }
    }
}
