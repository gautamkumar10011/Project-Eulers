#include<iostream>
#include<cmath>
using namespace std ;
extern int * EsievePrimeGenerator(int range) ;
int problem_46(int start)
{
	
	int *ptr = EsievePrimeGenerator(10000) ;
	int oddnum  = start + 2 ;
	int flag = 1 ;
	int flagc = 0 ;
	while(flag)
	{
		// checking that given number is composite odd ( logic if the number is odd and not prime then it must be odd composite)

		if(ptr[oddnum] != true )
		{
			flagc = 1 ;
			// right now we conclude that the given  number is composite n odd (right )
			for(int j = 3 ; j < oddnum; j++)
			{
			   if(ptr[j] == true )
			   {
				int temp = (int)sqrt((oddnum - j)/2) ;  // oddnum - j alway even reason both are odd
				if((oddnum - j)/2 == temp *temp)
				{ 
					flagc = 0 ;				
					 break ;}
			   }
			}

			if(flagc == 1)
				return oddnum ;
		}
		
		oddnum = oddnum + 2 ;
		if(oddnum > 10000)
		{	flag = 0 ;
			return 2 ;
		}

	}

return oddnum ;
}
