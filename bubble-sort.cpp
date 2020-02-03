#include<iostream>
using namespace std;

void bubble(int a[],int);

int main()
{
    int a[100],n,i;
    cout<<"Enter size of Array=";
    cin>>n;

    for(i=0;i<n;i++)
        cin>>a[i];

    bubble(a,n);

    cout<<"\nSorted elements are : ";
    for(i=0;i<n;i++)
        cout<<"\t"<<a[i];

    return 1;
}

void bubble(int a[],int n)
{
    int temp,i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<(n-(i+1));j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
