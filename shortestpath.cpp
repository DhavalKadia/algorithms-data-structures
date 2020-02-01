#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void show();
void init();
void init();
void junction();
void print();

struct panel* new_file(struct panel *);
void trace(short int x,short int y,struct panel *);
void split(short int x,short int y,struct panel *);
int check(short int a,short int b,struct panel *);
void free_gateway(struct gateway *);
void free_panel(struct panel *);
void copy_panel(struct panel *,struct panel *);
void s_show(struct panel *px);
void dist(struct panel *);
void navigate();
void dir(float,short int,short int);
void select();
int** alloc_m(int,int);

int alpha;
int i,j,fi=0,**navi,x_s,y_s,fx,fy,loc,x_d,y_d,v;
int o=0;
int chk;

float branch_end,minimum=2329;

struct gateway{

    short int pp;
    short int qq;
    struct gateway *down;

}*bottom,*copx,*temp,*bottom_up,*gamma,*gamma2,*beta,*del_gate,*cop_y,*temp_y,*g_y;

struct panel{

    struct gateway *gate;

}*rightest,*fina,*start,*alphaa,*p_y;

int main()
{

    cout<<"\t\t\t\tProgrammed By\n\n\t\t\t\tDhaval Kadia\n\n\t\t\t\t   BE-II\n\n\t\t\t   Computer Sci. & Engr.\n\n       Faculty Of Technology & Engineering - M.S. University  ( INDIA ) \n\n\t    This was Completed on Mid 2014 , Published on 2015\n";

    init();

    junction();

    print();

    cout<<"\nEnter Valid Co-Ordinate From 0 to "<<(alpha-1)<<" From Where Path is.";
    cout<<"\n\nEnter Your STARTING Co-Ordinates : \n\tX = ";
    cin>>x_s;

    if(x_s>=alpha)
    {
        cout<<"\nEnter below "<<alpha<<" X = ";
        cin>>x_s;
    }

    cout<<"\tY = ";
    cin>>y_s;

    if(y_s>=alpha)
    {
        cout<<"\nEnter below "<<alpha<<" Y = ";
        cin>>y_s;
    }


    if(navi[x_s][y_s]>0)
    {
        cout<<"\nEnter Your DESTINATION Co-Ordinates : \n\tX = ";
        cin>>x_d;

        if(x_d>=alpha)
        {
            cout<<"\nEnter below "<<alpha<<" X = ";
            cin>>x_d;
        }

        cout<<"\tY = ";
        cin>>y_d;

        if(y_d>=alpha)
        {
            cout<<"\nEnter below "<<alpha<<" Y = ";
            cin>>y_d;
        }

        if(navi[x_d][y_d]>0)
        {

            start->gate->pp=x_s;
            start->gate->qq=y_s;

            navi[x_s][y_s]=2;
            navi[x_d][y_d]=1;

            cout<<"\nPLEASE WAIT...";

            trace(x_s,y_s,start);

            free_panel(start);

            cout<<"\n\nDistance : "<<minimum<<" miles to Go On ,\n\nPATH ";
            s_show(fina);
            cout<<"\n\nFollow Below Directions :\n";
            navigate();
        }
        else
        {
            cout<<"\n\nSelect Proper Destination Co-Ordinate from Where PATH is.\n";
        }
    }
    else
    {
        cout<<"\n\nSelect Proper Current Co-Ordinate from Where PATH is.\n";
    }

    cout<<"\n\nAny type of Suggestions , You can contact me on dhavalkadiamsu@gmail.com\n";
    getch();

    return 1;
}

int** alloc_m(int m,int n)
{
    int ** matrix;
	matrix = (  int **) calloc(m, sizeof(  int *));
	for(  int i = 0;i < m; i++)
		matrix[i] = (  int *) calloc(n, sizeof(  int));
	return matrix;
}

void init()
{
    cout<<"\n[ 5<size<26 Recommended ]\n\nEnter Size of MAP you want = ";
    cin>>alpha;

    navi=alloc_m(alpha,alpha);

    for(i=0;i<alpha;i++)
    {
        for(j=0;j<alpha;j++)
        {
            navi[i][j]=0;
        }
    }

    select();

    bottom=(struct gateway*)malloc(sizeof(struct gateway*));
    bottom_up=(struct gateway*)malloc(sizeof(struct gateway*));
    copx=(struct gateway*)malloc(sizeof(struct gateway*));
    temp=(struct gateway*)malloc(sizeof(struct gateway*));

    fina=(struct panel*)malloc(sizeof(struct panel));

    start=(struct panel*)malloc(sizeof(struct panel));

    start->gate=(struct gateway*)malloc(sizeof(struct gateway*));
    bottom=start->gate;
    start->gate->down=NULL;

    gamma=(struct gateway*)malloc(sizeof(struct gateway*));
    gamma2=(struct gateway*)malloc(sizeof(struct gateway*));

    del_gate=(struct gateway*)malloc(sizeof(struct gateway*));

    cop_y=(struct gateway*)malloc(sizeof(struct gateway*));
    temp_y=(struct gateway*)malloc(sizeof(struct gateway*));

    p_y=(struct panel*)malloc(sizeof(struct panel));
    g_y=(struct gateway*)malloc(sizeof(struct gateway*));
}

void print()
{
    cout<<"\n\t\t\t\tMAP :\n\n";

    char l;
    printf("  Y  ");
    for(i=0;i<alpha;i++)
        printf("%d  ",i%10);
    printf("\n X\n");
    for(i=0;i<alpha;i++)
    {
        printf("%2d ",i);
        for(j=0;j<alpha;j++)
        {
            if(navi[i][j]>0)
                l='O';
            else
                l='+';
            printf("%3c",l);
        }

        printf("\n");
    }
}

void copy_panel(struct panel *from,struct panel *to)
{
    cop_y=from->gate;

    to->gate=(struct gateway*)malloc(sizeof(struct gateway*));

    temp_y=to->gate;

    struct gateway *temp_up_y=(struct gateway*)malloc(sizeof(struct gateway*));

    while(cop_y)
    {
        temp_y->pp=cop_y->pp;
        temp_y->qq=cop_y->qq;

        cop_y=cop_y->down;

        temp_y->down=(struct gateway*)malloc(sizeof(struct gateway*));
        temp_up_y=temp_y;
        temp_y=temp_y->down;
    }

    temp_up_y->down=NULL;
}

void trace(short int x,short int y,struct panel *p)
{

    if(x==x_d&&y==y_d)
    {
        dist(p);

        if(minimum>=branch_end)
        {
            minimum=branch_end;
            copy_panel(p,fina);
        }
    }
    else
    {
        if(navi[x][y]==2)
        {
            split(x,y,p);
        }
        else if(navi[x][y]==1)
        {
            int m,n;
            for(m=x-1;m<=x+1;m++)
            {
                if(m>=0&&m<alpha)
                {
                    for(n=y-1;n<=y+1;n++)
                    {
                        if(n>=0&&n<alpha)
                        {
                            if(m!=x||n!=y)
                            {
                                chk=check(m,n,p);

                                if(navi[m][n]==1&&!chk)
                                {
                                    bottom->down=(struct gateway*)malloc(sizeof(struct gateway*));
                                    bottom=bottom->down;

                                    bottom->pp=m;
                                    bottom->qq=n;
                                    bottom->down=NULL;

                                    trace(m,n,p);
                                }
                                else if(!chk)
                                {
                                    trace(m,n,p);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void split(short int x,short int y,struct panel *p)
{
    if(!check(x,y,p))
    {
        bottom->down=(struct gateway*)malloc(sizeof(struct gateway*));
        bottom=bottom->down;

        bottom->pp=x;
        bottom->qq=y;

        bottom->down=NULL;
    }

    int m,n;
    for(m=x-1;m<=x+1;m++)
    {
        if(m<alpha&&m>=0)
        {
            for(n=y-1;n<=y+1;n++)
            {
                if(n>=0&&n<alpha)
                {
                    if(navi[m][n]>0)
                    {
                            if(navi[m][n]>0&&!check(m,n,p)&&(m!=x||n!=y))
                            {
                                struct panel *temp_pan=(struct panel*)malloc(sizeof(struct panel));

                                temp_pan=new_file(p);

                                if(!check(m,n,temp_pan))
                                {
                                    bottom->down=(struct gateway*)malloc(sizeof(struct gateway*));
                                    bottom=bottom->down;

                                    bottom->pp=m;
                                    bottom->qq=n;

                                    bottom->down=NULL;
                                }

                                trace(m,n,temp_pan);

                                free_panel(temp_pan);
                            }
                    }
                }
            }
        }
    }
}


struct panel* new_file(struct panel *vect)
{
    copx=vect->gate;
    rightest=(struct panel*)malloc(sizeof(struct panel));
    rightest->gate=(struct gateway*)malloc(sizeof(struct gateway*));

    temp=rightest->gate;

    struct gateway *temp_up=(struct gateway*)malloc(sizeof(struct gateway*));

    while(copx)
    {
        temp->pp=copx->pp;
        temp->qq=copx->qq;

        copx=copx->down;

        temp->down=(struct gateway*)malloc(sizeof(struct gateway*));
        temp_up=temp;
        temp=temp->down;
    }

    temp_up->down=NULL;

    return rightest;
}



int check(short int a,short int b,struct panel *pan)
{
 bottom=pan->gate;

 while(bottom)
    {
        if((bottom->pp==a)&&(bottom->qq==b))
            {
                return 1;
            }
        bottom_up=bottom;
        bottom=bottom->down;
    }
    bottom=bottom_up;

    return 0;
}


void navigate()
{
    short int d_x,d_y,c_x,c_y;
    int step;
    float dis;

    bottom=fina->gate;

    d_x=bottom->down->pp-bottom->pp;
    d_y=bottom->down->qq-bottom->qq;

    if(d_x&&d_y)
        dis=1.41;
    else
        dis=1;

    step=1;

    bottom=bottom->down;

    while(bottom->down)
    {
        c_x=bottom->down->pp-bottom->pp;
        c_y=bottom->down->qq-bottom->qq;

        if(c_x==d_x&&c_y==d_y)
        {
            step++;

            if(c_x&&c_y)
                dis=dis+1.41;
            else
                dis=dis+1;
        }
        else
        {
            dir(step,d_x,d_y);

            step=1;

            d_x=bottom->down->pp-bottom->pp;
            d_y=bottom->down->qq-bottom->qq;

            if(d_x&&d_y)
                dis=1.41;
            else
                dis=1;
        }

        bottom=bottom->down;
    }

    dir(step,c_x,c_y);
}


void dir(float s,short int a,short int b)
{
    if(a==1&&b==0)
        printf("\n %.2f mile SOUTH      [ %d step x 1    mile ]",s,(int)s);
    else if(a==-1&&b==0)
        printf("\n %.2f mile NORTH      [ %d step x 1    mile ]",s,(int)s);
    else if(a==0&&b==1)
        printf("\n %.2f mile EAST       [ %d step x 1    mile ]",s,(int)s);
    else if(a==0&&b==-1)
        printf("\n %.2f mile WEST       [ %d step x 1    mile ]",s,(int)s);
    else if(a==1&&b==1)
        printf("\n %.2f mile SOUTH-EAST [ %d step x 1.41 mile ]",s*1.41,(int)s);
    else if(a==-1&&b==-1)
        printf("\n %.2f mile NORTH-WEST [ %d step x 1.41 mile ]",s*1.41,(int)s);
    else if(a==1&&b==-1)
        printf("\n %.2f mile SOUTH-WEST [ %d step x 1.41 mile ]",s*1.41,(int)s);
    else if(a==-1&&b==1)
        printf("\n %.2f mile NORTH-EAST [ %d step x 1.41 mile ]",s*1.41,(int)s);
}

void dist(struct panel *pan)
{
    branch_end=0;

    bottom=pan->gate;

    while(bottom->down)
    {
        branch_end++;

        if((bottom->pp-bottom->down->pp)&&(bottom->qq-bottom->down->qq))
        {
            branch_end=branch_end+0.41;
        }

        bottom=bottom->down;
    }
}

void junction()
{
    int m,n,branch;
    for(i=0;i<alpha;i++)
    {
        for(j=0;j<alpha;j++)
        {
            branch=0;
            for(m=i-1;m<=i+1;m++)
            {
                if(navi[i][j]>0)
                {
                    if(m>=0&&m<alpha)
                    {
                        for(n=j-1;n<=j+1;n++)
                        {

                            if(n>=0&&n<alpha)
                            {

                                if(navi[m][n]>0&&(m!=i||n!=j))
                                branch++;
                            }
                        }
                    }
                }
            }

        if(branch>2)
            navi[i][j]=2;
        }
    }

    if(navi[0][0]>0)
        navi[0][0]=1;

    if(navi[alpha-1][alpha-1]>0)
        navi[alpha-1][alpha-1]=1;

    if(navi[alpha-1][0]>0)
        navi[alpha-1][0]=1;

    if(navi[0][alpha-1]>0)
        navi[0][alpha-1]=1;
}

void s_show(struct panel *px)
{
    p_y=px;

    g_y=p_y->gate;

    while(g_y)
    {
        printf("-> [%d , %d] ",g_y->pp,g_y->qq);
        g_y=g_y->down;
    }
}

void free_panel(struct panel *vect)
{
    del_gate=vect->gate;

    free_gateway(del_gate);

    free(vect);
}

void free_gateway(struct gateway *gat)
{
    if(gat==NULL)
        return;
    else
    {
        free_gateway(gat->down);

        free(gat);
    }
}

void select()
{
    cout<<"\n\nSelect Pattern of MAP from below Choices :";
    cout<<"\n1. X inside Square.\n2. + inside Square.\n3. Mercedes Symbol inside Square.\n4. Diamond Shaped.\n5. Make Your Customized MAP.";
    cout<<"\n\nEnter Choice = ";
    cin>>v;

    if(v==1)
    {
        for(int z=0;z<alpha;z++)
            navi[0][z]=1;
        for(int z=0;z<alpha;z++)
            navi[z][0]=1;
        for(int z=1;z<alpha;z++)
            navi[z][z]=1;
        for(int z=0;z<alpha;z++)
            navi[(alpha-1)][z]=1;
        for(int z=0;z<alpha;z++)
            navi[z][(alpha-1)]=1;
        for(int z=0;z<alpha;z++)
            navi[z][(alpha-1)-z]=1;

    }
    else if(v==2)
    {
        for(int z=0;z<alpha;z++)
            navi[0][z]=1;
        for(int z=0;z<alpha;z++)
            navi[z][0]=1;
        for(int z=0;z<alpha;z++)
            navi[(alpha-1)][z]=1;
        for(int z=0;z<alpha;z++)
            navi[z][(alpha-1)]=1;
        for(int z=0;z<alpha;z++)
            navi[z][alpha/2]=1;
        for(int z=0;z<alpha;z++)
            navi[alpha/2][z]=1;
    }
    else if(v==3)
    {
        for(int z=0;z<alpha;z++)
            navi[0][z]=1;
        for(int z=0;z<alpha;z++)
            navi[z][0]=1;
        for(int z=0;z<alpha;z++)
            navi[(alpha-1)][z]=1;
        for(int z=0;z<alpha;z++)
            navi[z][(alpha-1)]=1;
        for(int z=0;z<(alpha/2);z++)
            navi[z][alpha/2]=1;
        for(int z=(alpha/2);z<alpha;z++)
            navi[z][z]=1;
        for(int z=(alpha/2);z<alpha;z++)
            navi[z][(alpha-1)-z]=1;
    }
    else if(v==4)
    {
        for(int z=(alpha/2);z<alpha;z++)
            navi[0][z]=1;
        for(int z=(alpha/2);z<alpha;z++)
            navi[z][0]=1;
        for(int z=0;z<(alpha/2);z++)
            navi[(alpha-1)][z]=1;
        for(int z=0;z<(alpha/2);z++)
            navi[z][(alpha-1)]=1;
        for(int z=0;z<alpha;z++)
            navi[z][alpha/2]=1;
        for(int z=0;z<alpha;z++)
            navi[alpha/2][z]=1;
    }
    else if(v==5)
    {
    cout<<"\n\nEnter 1 Where you want to add PATH and Enter 0 Where remain it BLANK.\n\n";
    for(i=0;i<alpha;i++)
	 {
	     for(j=0;j<alpha;j++)
         {
            cout<<"MAP ["<<i<<"]["<<j<<"] = ";
            cin>>navi[i][j];
         }
         cout<<"\n";
	 }
    }
    else
        cout<<"\n\nEnter Choice From 1 to 5.";
}
