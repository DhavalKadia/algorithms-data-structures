#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;            //  hardware limit=4294967295
void first_block(int,int);        //  till that Roman numerals can be calctd.
void concate();

unsigned long long int input;
int i,j,t=0;
char block_n[6][3][4],block[100],block_tmp[10][10];

int main()
{
//    clrscr();
    cout<<"n=";
    cin>>input;
    cout<<"Roman of "<<input<<"=";
    while(input!=0)
    {
     first_block(input%1000,t);
     t++;
     input/=1000;
    }
    concate();
    cout<<"\n"<<block;
    getch();
    return 1;
}

void first_block(int n,int block_no)
{
    int rem;
    char step_first[1],step_middle[1],step_last[1];

 for(i=0;i<3;i++)
 {
   rem=n%10;
   n/=10;

 if(rem)
 {
   if(i==0)
   {
     if(block_no==0)
       strcpy(step_first,"I");
     else
       strcpy(step_first,"M");
       strcpy(step_middle,"V");
       strcpy(step_last,"X");
   }
   else if(i==1)
   {
       strcpy(step_first,"X");
       strcpy(step_middle,"L");
       strcpy(step_last,"C");
   }
   else if(i==2)
   {
       strcpy(step_first,"C");
       strcpy(step_middle,"D");
       strcpy(step_last,"M");
   }
 if(((rem==4||rem==9)&&!block_no)||((rem==4||rem==9)&&i&&block_no))
   {
      if(block_no&&i==0)
	strcpy(step_first,"I");
       strcat(block_n[block_no][i],step_first);

       if(rem==4)
	   strcat(block_n[block_no][i],step_middle);
       else
	   strcat(block_n[block_no][i],step_last);
   }

   else if(rem<=4||(rem>=6&&rem<=8))
   {
       if(rem<=4)
       {
	 if(block_no==0&&rem<=3)
	 {
	   for(j=0;j<rem;j++)
	       strcat(block_n[block_no][i],step_first);
	 }
	 else if(block_no)
	 {
	   for(j=0;j<rem;j++)
	       strcat(block_n[block_no][i],step_first);
	 }
       }
       else if(rem>=6&&rem<=8)
       {
	   strcat(block_n[block_no][i],step_middle);
	   for(j=0;j<rem-5;j++)
	   {
	       strcat(block_n[block_no][i],step_first);
	   }
       }
   }
   else if(rem==5)
       strcat(block_n[block_no][i],step_middle);
  }
 }
    for(j=2;j>=0;j--)
    {
	strcat(block_tmp[block_no],block_n[block_no][j]);
	strcat(block_tmp[block_no]," ");
    }
}

void concate()
{
 for(i=t-1;i>=0;i--)
    strcat(block,block_tmp[i]);
}
