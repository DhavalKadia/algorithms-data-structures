#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<stdio.h>
using namespace std;

float **a,**temp,**adj,**gen_mat,**alloc_m(int),**adj_temp,ans=1,**inv;
int z=0,i,j,sh_i,sh_j,count=0,x4,m,n,size_m;
unsigned short int x[200000];
double f4=0;
char c;

void init();
void f(float **ap,int,int,int);
void scan(float **ap,int,int,int);
void show(float **ap,int);
float det(float **ap);

FILE *fp;

int main()
{
    fp=fopen("Matrix_Output.txt","w");
    float dt;
    cout<<"Enter Size of Matrix (Greater Than 4) =";
    cin>>size_m;

if(size_m<=10)
{

    a=alloc_m(size_m);
    init();

if(c=='r'||c=='m')
{
    cout<<"\n\nInput Matrix is :\n\n";
    fprintf(fp,"Input Matrix is :\n\n");
    show(a,size_m);
    adj=alloc_m(size_m);
    adj_temp=alloc_m(size_m);

    for(m=0;m<size_m;m++)
    {
       for(n=0;n<size_m;n++)
       {
           f4=0;
           scan(a,m,n,size_m);
           f(gen_mat,size_m-1,0,1);
           adj_temp[m][n]=f4;
       }
    }

    for(m=0;m<size_m;m++)
   {
       for(n=0;n<size_m;n++)
       {
        adj[m][n]=adj_temp[n][m];
        if((m+n)%2==1)
            adj[m][n]*=-1;
       }
   }

    inv=alloc_m(size_m);
    f4=0;
    f(a,size_m,0,1);

    for(m=0;m<size_m;m++)
       for(n=0;n<size_m;n++)
         inv[m][n]=adj[m][n]/f4;


    fprintf(fp,"\n\nADJOINT :\n\n");
    cout<<"\n\nADJOINT :\n\n";
    show(adj,size_m);

    cout<<"\n\nDETERMINANT : "<<f4;
    fprintf(fp,"\n\nDETERMINANT : %f",f4);

    fprintf(fp,"\n\nINVERSE IS:\n\n");
    cout<<"\n\nINVERSE IS :\n\n";
    show(inv,size_m);
}
else
    cout<<"\n\n---------------Select valid Option of Input.---------------";
}
else
    cout<<"\n\n\n*This is Basic Version.\n\nLimited upto MATRIX-RANK<=10 .\n\nFor MORE THAN MATRIX-RANK>10 , e.g. 24 ,etc \n\nFor Buying PRO Version ,\n\n CONTACT Provider (Dhaval Kadia) at dhavalkadiamsu@gmail.com";

cout<<"\n\n\t\t\t\t     By\n\n\n\n\t\t\t\tDhaval Kadia\n\n\n\n\t\t\t\t   BE-II\n\n\n\n\t\t\t   Computer Sci. & Engr.\n\n\n\n       Faculty Of Technology & Engineering - M.S. University  ( INDIA ) \n\n\n\n\t    This was Completed on Early 2014 , Published on 2015\n\n";

getch();
return 1;

}

void init()
{

cout<<"\nPRESS \n\tm=MANUAL \n   OR \n\tr=RANDOMLY GENERATED MATRIX .\n\nSelect Method of INPUT : ";
cin>>c;

if(c=='r')
{
    for(i=0;i<size_m;i++)
	 for(j=0;j<size_m;j++)
		 a[i][j]=rand()%5;
}
else if(c=='m')
{
    cout<<"\n";
    for(i=0;i<size_m;i++)
	 {
	     for(j=0;j<size_m;j++)
         {
            cout<<"["<<i+1<<"]["<<j+1<<"]=";
            cin>>a[i][j];
         }
         cout<<"\n";
	 }
}

}


void scan(float **m,int i,int j,int n)
{
    gen_mat=alloc_m(n-1);
    int s_i,s_j,g_i=0,g_j;
    for(s_i=0;s_i<n;s_i++)
    {
      if(s_i!=i)
      {
        g_j=0;
        for(s_j=0;s_j<n;s_j++)
        {
            if(s_j!=j)
            {
            gen_mat[g_i][g_j]=m[s_i][s_j];
            g_j++;
            }
        }
        g_i++;
      }
    }
}

void show(float **mx,int n)
{
    for(sh_i=0;sh_i<n;sh_i++)
    {
        for(sh_j=0;sh_j<n;sh_j++)
        {
            cout<<mx[sh_i][sh_j]<<"\t";
            fprintf(fp,"%f\t",mx[sh_i][sh_j]);
        }
        cout<<"\n\n";
        fprintf(fp,"\n");
    }
}

float** alloc_m(int n)
{
    float ** matrix;
	matrix = (float **) calloc(n, sizeof(float *));
	for(int i = 0; i < n; i++)
		matrix[i] = (float *) calloc(n, sizeof(float));
	return matrix;
}

float det(float **m)
{
    float d=0;
    float **new_temp;

    new_temp= (float **) calloc(3, sizeof(float *));
	for(i = 0; i < 3; i++)
		new_temp[i] = (float *) calloc(5, sizeof(float));

    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            new_temp[i][j]=m[i][j];


    for(i=0;i<3;i++)
        for(j=3;j<=4;j++)
            new_temp[i][j]=m[i][j-3];


    for(i=0;i<3;i++)
        d+=new_temp[0][i]*new_temp[1][i+1]*new_temp[2][i+2];

    for(i=2;i<5;i++)
        d-=new_temp[0][i]*new_temp[1][i-1]*new_temp[2][i-2];

    return d;
}


void f(float **m,int k,int z,int carry)
{
  if(k>4)
  {
	for(x[z]=0;x[z]<k;x[z]++)
	{
		scan(m,0,x[z],k);
        if(x[z]%2==1)
            f(gen_mat,k-1,z+1,-m[0][x[z]]*carry);
	    else
            f(gen_mat,k-1,z+1,m[0][x[z]]*carry);
	}
  }
  else if(k==4)
  {
        count++;
        for(x4=0;x4<4;x4++)
        {
            scan(m,0,x4,4);
            ans=m[0][x4]*carry*det(gen_mat);
            if(x4%2==1)
                ans*=-1;
            f4+=ans;
        }
  }
}
