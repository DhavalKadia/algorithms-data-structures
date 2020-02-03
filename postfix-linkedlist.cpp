#include<iostream>
#include<stdlib.h>
//#include<stdio.h>
using namespace std;

void alloc(struct binary *,int,struct binary *);
void auto_post(struct binary *);
FILE *f;
struct binary
{
    char sign;
    int left_v;
    int right_v;
    struct binary *left;
    struct binary *right;
};

int main()
{
  //  f=fopen("pre.txt","w");
    struct binary *root;
    root=(struct binary*)malloc(sizeof(struct binary));
    alloc(root,0,root);
    cout<<"\nPostfix Form : ";
    auto_post(root);
    return 1;
}

void alloc(struct binary *tmp,int state,struct binary * pre)
{
    char ans;

    cout<<"\nDo you want to proceed further? y/n? ";
    cin>>ans;

    if(ans=='y')
    {
        cout<<"\nEnter Sign=";
        cin>>tmp->sign;

        tmp->left=(struct binary*)malloc(sizeof(struct binary));
        alloc(tmp->left,0,tmp);
        tmp->right=(struct binary*)malloc(sizeof(struct binary));
        alloc(tmp->right,1,tmp);
    }
    else if(ans=='n')
    {
        if(state==0)
        {
            cout<<"\nEnter Lvalue=";
            cin>>pre->left_v;
            pre->left=NULL;
        }
        else if(state==1)
        {
            cout<<"\nEnter Rvalue=";
            cin>>pre->right_v;
            pre->right=NULL;
        }
    }
}

void auto_post(struct binary *tmp)
{
    if(tmp->left)
        auto_post(tmp->left);
    else
        cout<<tmp->left_v<<" ";

    if(tmp->right)
        auto_post(tmp->right);
    else
        cout<<tmp->right_v<<" ";

    cout<<tmp->sign<<" ";
}
