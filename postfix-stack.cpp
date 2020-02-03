#include<iostream>
#include<string.h>
using namespace std;

int top=0,cnt=0,i,m;
string *input,*final,stac[3];

void init();
void autorun(int);
int isnumber(string);
int isprime(string,string);
int get_priority(string);


int main()
{
    cout<<"With How many Operands you want to proceed ? ";
    cin>>m;
    init();

    autorun(0);

    cout<<endl<<"Postfix Form : ";
    for(i=0; i<(2*m-2); i++)
        cout<<final[i];
    for(i=top-1; i>=0; i--)
        cout<<stac[i];

    return 1;
}

void autorun(int n)
{
  if(n<(2*m-1))
    {
        if(isnumber(input[n]))
        {
            final[cnt]=input[n];
            cnt++;
            autorun(n+1);
        }
        else
        {
            if(top==0)
            {
                stac[0]=input[n];
                top=1;
                autorun(n+1);
            }
            else
            {
                if(isprime(input[n],stac[top-1]))
                {
                    stac[top]=input[n];
                    top++;
                    autorun(n+1);
                }
                else
                {
                    final[cnt]=stac[top-1];
                    cnt++;
                    top--;
                    autorun(n);
                }
            }
        }
    }
}

int isnumber(string check)
{
    if(check=="^")
        return 0;
    else if(check=="/")
        return 0;
    else if(check=="*")
        return 0;
    else if(check=="+")
        return 0;
    else if(check=="-")
        return 0;
    else
        return 1;
}

int get_priority(string in)
{
    if(in=="^")
        return 3;
    else if(in=="/")
        return 2;
    else if(in=="*")
        return 2;
    else if(in=="+")
        return 1;
    else if(in=="-")
        return 1;
}

int isprime(string current,string base)
{
    if(get_priority(current)>get_priority(base))
        return 1;
    else
        return 0;
}

void init()
{
    input=new string[2*m-1];
    final=new string[2*m-1];

    for(i=0; i<(2*m-1); i++)
    {
        cout<<"\nEnter Element["<<i<<"]= ";
        cin>>input[i];
    }
}

