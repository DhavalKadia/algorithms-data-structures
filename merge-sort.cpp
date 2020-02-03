#include<iostream>
using namespace std;

int *test,*tmp,*temp,a,b,c,d,state=1,cnt=0,z,zz,k,siz;

void split(int,int);
void merge(int,int);
void show();

int main()
{
   cout<<"Enter size of Array= ";
   cin>>siz;
   test=new int [2*siz+1];
   for(zz=1;zz<=siz;zz++)
   {
       cout<<"element["<<zz<<"]= ";
       cin>>test[zz];
   }

    cout<<"\nINPUT= ";
    for(zz=1;zz<=siz;zz++)
        cout<<"  "<<test[zz];

    split(1,2*siz);

    cout<<"\nOUTPUT= ";
    for(zz=1;zz<=siz;zz++)
        cout<<"  "<<test[zz];

    return 1;
}

void split(int i,int j)
{
    if(j>i)
    {
        tmp=new int[j-i+1];
        temp=new int[j-i+1];
        split(i,(i+j)/2);
        merge(i,(i+j)/2);
        split(((i+j)/2)+1,j);
        merge(((i+j)/2)+1,j);
    }
}

void merge(int i,int j)
{
    show();
    if(state)
    {
        a=i;         b=((i+j)/2)+1;
        c=b-1;       d=j;
        state=0;     cnt=0;
    }

    if((j-i)==1)
    {
        if(test[i]<test[j])
        {  tmp[0]=test[i];    tmp[1]=test[j]; }
        else
        {  tmp[0]=test[j];    tmp[1]=test[i]; }
    }
    else
    {
        if(test[a]>test[b])
        {
            if(b==(d+1))
                for( z=a; z<b; z++,cnt++)
                    tmp[cnt]=test[z];
            else
            {
                tmp[cnt]=test[b];
                cnt++;
                b++;
                merge(i,j);
            }
        }
        else
        {
            if(a==(c+1))
                for( z=b; z<=j; z++,cnt++)
                    tmp[cnt]=test[z];
            else
            {
                tmp[cnt]=test[a];
                cnt++;
                a++;
                merge(i,j);
            }
        }
    }

    for(k=i,z=0;z<j-i+1;z++,k++)
        test[k]=tmp[z];
    state=1;
}

void show()
{
    cout<<"\nDEBUG : ";
        for(zz=1;zz<=siz;zz++)
        cout<<"  "<<test[zz];
}
