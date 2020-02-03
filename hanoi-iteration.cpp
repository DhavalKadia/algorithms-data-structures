#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

int **flat,n;
void gen(int);

int main()
{
    int orig,dest,siz;

    cout<<"Enter Number of Disk = ";
    cin>>n;
    cout<<"\nEnter Number of Tower where Disks are There = ";
    cin>>orig;
    cout<<"\nEnter Number of Tower where Disks are going to be Put = ";
    cin>>dest;

    siz=pow(2,n);
    flat=new int*[siz];
    for(int i=0;i<siz;i++)
        flat[i]=new int[3];
    flat[siz/2][0]=n; flat[siz/2][1]=orig; flat[siz/2][2]=dest;

    for(int i=2;i<=n;i++)
        gen(i);

    for(int i=1;i<pow(2,n);i++)
        cout<<flat[i][0]<<":"<<flat[i][1]<<"->"<<flat[i][2]<<endl;
 return 1;
}

void gen(int level)
{
    int flag=1,t_up,up,t_down,down;
    t_up=up=pow(2,n-(level-1));
    t_down=down=pow(2,(n-level));

  for(;down<=pow(2,n)-t_down;down+=2*t_down)
    if(flag==1)
    {
        flat[down][0]=(n+1)-level;
        flat[down][1]=flat[up][1];
        flat[down][2]=3-(flat[up][1]+flat[up][2]);
        flag=0;
    }
    else if(flag==0)
    {
        flat[down][0]=(n+1)-level;
        flat[down][1]=3-(flat[up][1]+flat[up][2]);
        flat[down][2]=flat[up][2];
        flag=1;
        up+=2*t_up;
    }
}
