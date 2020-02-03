// Factorial by Iteration - Dhaval Kadia

class Fact{

	static long[] final_str=new long[1000000];
	static int i,j;

static void gen_str( long  in_str[], long   mul_er)
{
    long temp,mul;
    long carry=0;

    i=0;
    while(final_str[i]!=-1)
    {
        temp=in_str[i]*mul_er+carry;
        final_str[i]=temp%10000000000L;
        carry=(temp-final_str[i])/10000000000L;
        i++;
    }

    if(carry>0)
    {
        final_str[i]=carry;
        final_str[i+1]=-1;
    }
}

public static void main(String[] st)
{
	
    long   n;
    final_str[0]=1;
    final_str[1]=0;
    final_str[2]=-1;

    gen_str(final_str,2);

    n=5;	// Enter number here

    i=0;
    for(j=3;j<=n;j++)        
    	gen_str(final_str,j);
        
    System.out.println(n+"!=");
    
    i=0;
    while(final_str[i]!=-1)
    {
    	String formatted = String.format("%010d", final_str[i]);
    	System.out.print(formatted+" ");
    	
    	if(i%10 == 9)
    		System.out.println();
    	
        i++;
    }
}
}