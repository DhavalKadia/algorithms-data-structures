#include<iostream>
using namespace std;

int **mat,i,j,*out,sz,cnt=0;

void trvs(int,int);
void init();
int check(int);
void add(int);

int main()
{
    int in;
    cout<<"Enter size=";
    cin>>sz;

    init();

    cout<<"\nEnter Starting Point=" ;
    cin>>in;
    add(in);
    trvs(in,0);

    cout<<"\nOUTPUT= ";
    for(i=0;i<sz;i++)
        cout<<"\t"<<out[i];

    return 1;
}

void trvs(int n,int c)
{
    if(c<sz)
    {
        if(mat[n][c]==1)
        {
            if(check(c)==0)
            {
                add(c);
                trvs(c,0);
            }
        }
        trvs(n,c+1);
    }
}

void init()
{
    out=new int[sz];
    mat=new int*[sz];
    for(i=0;i<sz;i++)
        mat[i]=new int[sz];

    cout<<"Eenter elements :\n";
    for(i=0;i<sz;i++)
    {
        cout<<"\n";
        for(j=0;j<sz;j++)
        {
            cout<<"mat["<<i<<"]["<<j<<"]=";
            cin>>mat[i][j];
        }
    }

    for(i=0;i<sz;i++)
        out[i]=55;
}

int check(int k)
{
    int flag=0;

    for(i=0;i<cnt;i++)
    {
        if(out[i]==k)
            flag=1;
    }
    return flag;
}

void add(int k)
{
    out[cnt]=k;
    cnt++;
}
