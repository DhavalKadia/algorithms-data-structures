#include<iostream>
#include<cstdlib>

using namespace std;

int *ary,zz,siz;

void qs(int,int,int,int,int);
void swipe(int&,int&);
void show();

int main()
{

    cout<<"Enter size of Array= ";
    cin>>siz;

    ary=new int [siz];

    for(zz=0;zz<siz;zz++)
        ary[zz]=rand()%1000;
    cout<<"input ="<<endl;

    show();

    qs(0,1,siz-1,1,siz-1);

    cout<<"\n\noutput ="<<endl;
    show();

    return 1;
}

void qs(int pivot,int up,int down,int vu,int vd)
{
 if(down>up)
 {
    if(up==(down-1))
    {
            if(ary[up]>ary[down])
            {
                swipe(ary[up],ary[down]);
                qs(pivot,up,down,vu,vd);
            }
            else
            {
                if(ary[pivot]>ary[up])
                    swipe(ary[pivot],ary[up]);
                else
                    swipe(ary[pivot],ary[up-1]);
                qs(pivot,pivot+1,up-1,pivot+1,up-1);
                qs(up,up+1,vd,up+1,vd);
            }
    }
    else
    {
        if(ary[pivot]<ary[up])
        {
            if(ary[up]>ary[down])
                {
                    if(ary[pivot]<ary[down])
                        qs(pivot,up,down-1,vu,vd);
                    else
                    {
                        swipe(ary[up],ary[down]);
                        qs(pivot,up,down,vu,vd);
                    }
                }
            else
                qs(pivot,up,down-1,vu,vd);
        }
        else
            qs(pivot,up+1,down,vu,vd);
    }
 }
 else if(up==down)
 {
    if(ary[pivot]>ary[up])
        swipe(ary[pivot],ary[up]);
    qs(pivot,pivot+1,up-1,pivot+1,up-1);
    qs(down,down+1,vd,down+1,vd);
 }
}

void swipe(int &a,int &b)
{
    int t;  t=a;  a=b;  b=t;
}


void show()
{
    for(zz=0;zz<siz;zz++)
        cout<<"\t"<<ary[zz];
}
