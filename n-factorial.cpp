#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdio.h>

void gen_str( unsigned long long str[],unsigned long long  );

unsigned long long   i,j;
unsigned long long   final_str[100000000];

FILE *f;

int main()
{
    unsigned long long   n;
    f=fopen("fact.txt","w");

    final_str[0]=1;
    final_str[1]=0;
    final_str[2]=-1;

    printf("enter n=");
    scanf("%llu",&n);

    for(j=1;j<=n;j++)
        gen_str(final_str,j);

    fprintf(f,"%llu! =\n",n);

    i=0;
    while(final_str[i]!=-1)
       {
        printf("%010llu ",final_str[i]);
        fprintf(f,"%010llu ",final_str[i]);
        if(i%10==9)
            fprintf(f,"\n");
        i++;
       }

	return 1;
}

void gen_str( unsigned long long  in_str[],unsigned long long   mul_er)
{
    unsigned long long   temp,mul;
    unsigned long long   carry=0;

    i=0;
    while(final_str[i]!=-1)
    {
        temp=in_str[i]*mul_er+carry;
        final_str[i]=temp%10000000000;
        carry=(temp-final_str[i])/10000000000;
        i++;
    }

    if(carry>0)
    {
        final_str[i]=carry;
        final_str[i+1]=-1;
    }
}

