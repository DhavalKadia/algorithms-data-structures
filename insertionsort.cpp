#include<iostream>
using namespace std;

int main()
{
    int a[100],n,k,i,j,temp;
    cout<<"Enter size if Array=";
    cin>>n;

    cout<<"\nEnter elements of array=";
    for(i=0;i<n;i++)
        cin>>a[i];

    for(k=1;k<n;k++)
    {
        temp=a[k];
        j=k-1;

        while((temp<a[j])&(j>=0))
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }

    cout<<"\nSorted elements are : ";
    for(i=0;i<n;i++)
        cout<<"\t"<<a[i];

    return 1;
}
