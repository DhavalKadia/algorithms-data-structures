#include<stdio.h>
//#include<iostream>
#include<stdlib.h>
using namespace std;

void autonomous(int,int,int);
void put_base(int,int,int);
void init();
void show();
int pop(int);
void push(int,int);

int i,j,m,tower_orig,tower_dest;
unsigned long long int count=0;

FILE *f;

struct honai
{
    int e;
    struct honai *up;
    struct honai *down;
}*tower[3],*ptr,*top[3],*carry;


int main()
{

    f=fopen("honai.txt","w");
    printf("Enter Number of Disk = ");
    scanf("%d",&m);
    printf("\nEnter Number of Tower where %d Disks are There = ",m);
    scanf("%d",&tower_orig);
    init();
    printf("\nEnter Number of Tower where %d Disks are going to be Put = ",m);
    scanf("%d",&tower_dest);
    autonomous(m,tower_orig,tower_dest);
 //   fprintf(f,"\nTotal Number of Moves = %d",count);
    return 1;
}

void autonomous(int n,int orig,int dest)
{
    if(n==1)
        {
        count++;
   //     fprintf(f,"%d:%d>%d#",n,orig,dest);
        push(pop(orig),dest);
        }
    else
        {
        autonomous(n-1,orig ,2-(orig+dest-1));
            count++;
       //     fprintf(f,"%d:%d>%d#",n,orig,dest);
        push(pop(orig),dest);
        autonomous(n-1,2-(orig+dest-1),dest);
        }
}

void init()
{
    tower[tower_orig]=(struct honai*)malloc(sizeof(struct honai));
    tower[tower_orig]->down=NULL;
    tower[tower_orig]->up=NULL;

    for(i=0;i<3;i++)
    {
    top[i]=(struct honai*)malloc(sizeof(struct honai));
    top[i]->up=NULL;(struct honai*)malloc(sizeof(struct honai));
    top[i]->down=NULL;
    }
    ptr=tower[tower_orig];
    ptr->e=m;
    ptr->up=(struct honai*)malloc(sizeof(struct honai));
    carry=ptr;
    ptr=ptr->up;

    for(j=m-1;j>0;j--)
            {
                ptr->e=j;
                ptr->down=carry;
                carry=ptr;
                ptr->up=(struct honai*)malloc(sizeof(struct honai));
                ptr=ptr->up;
            }

    top[tower_orig]=carry;
    ptr=NULL;

    top[tower_orig]=carry;

    if(tower_orig==0)
    { top[1]=NULL;     top[2]=NULL; }
    else if(tower_orig==1)
    { top[0]=NULL;     top[2]=NULL; }
    else if(tower_orig==2)
    { top[1]=NULL;     top[0]=NULL; }
}

void show()
{
   // cout<<"\n--------------------------";
  fprintf(f,"\n----------------------------STEP %d",count);
    for(i=0;i<3;i++)
    {
        //cout<<"\nTower:"<<i<<": ";
        fprintf(f,"\nTower: %d: ",i);
        ptr=tower[i];
        while(ptr!=NULL)
        {
           // cout<<ptr->e<<" ";
            fprintf(f," %d",ptr->e);
            ptr=ptr->up;
        }
    }
}

int pop(int state)
{
    int ret;
    ret=top[state]->e;
    if(top[state]->down==NULL)
         { top[state]=NULL; tower[state]=NULL;} // both ???
    else
        {
            top[state]=top[state]->down;
            top[state]->up=NULL;
        }
    return ret;
}

void push(int in,int state)
{
    if(!top[state])
        {
            tower[state]=top[state]=(struct honai*)malloc(sizeof(struct honai));
            top[state]->down=NULL;
            carry=top[state];
            top[state]->e=in;
            top[state]->up=NULL;
        }
    else
        {
            carry=top[state];
            top[state]->up=(struct honai*)malloc(sizeof(struct honai));
            top[state]=top[state]->up;
            top[state]->e=in;
            top[state]->down=carry;
            top[state]->up=NULL;
        }
    show();
}
