#include<iostream>
using namespace std;

int **mat,i,j,*out,sz,cnt=0;

void trvs(int,int);
void init();
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
{   cout<<"\n"<<n<<"-"<<c;
    for(i=0;i<sz;i++)
        if(mat[n][i]==1)
        {
            for(j=0;j<sz;j++)
                if(j!=n)
                    mat[j][i]=0;
            mat[i][n]=0;
            add(i);
        }
    for(int k=0;k<sz;k++)
        if(k!=n)
            if(mat[n][k]==1)
                trvs(k,0);

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
            //cout<<"mat["<<i<<"]["<<j<<"]=";
            //cin>>mat[i][j];
            mat[i][j]=0;
        }
    }
    mat[0][1]=mat[0][2]=mat[0][7]=1;
    mat[1][0]=mat[1][2]=mat[1][4]=mat[1][6]=1;
    mat[2][0]=mat[2][1]=mat[2][3]=mat[2][7]=1;
    mat[3][2]=mat[3][5]=1;
    mat[4][0]=1;
    mat[5][3]=1;
    mat[6][0]=1;
    mat[7][0]=mat[7][2]=1;
    cout<<"\nhhh";

}

void add(int k)
{cout<<"\nadded="<<k;
    out[cnt]=k;
    cnt++;
}
