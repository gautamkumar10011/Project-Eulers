#include<stdio.h>
#include<stdlib.h>
extern long long int checkPrime(long long int );
int main()
{
	
	FILE *fp ;
	
        char   number[22] ;
	int dataList[12] = {0};	
	int prime ,temp  ;
	int  i , j , k , len  ;
        int counter = 0 ;
	long int sum = 0 ;
	
/***** this is the file that i Mannually created that contains primes ****/
	fp = fopen("primes.txt", "r") ;

	


	while(counter < 11)
	{
		// read the number form the file
		fscanf(fp , "%d",&prime) ;
  		k = 0 ;	
		temp = prime ;
		len = sprintf(number ,"%d" , prime) ;

		   if(prime > 10)
		   {
			for(i = len - 1 ; i > 0 ; i--)
			{
			    if(number[i] == '2' || number[i] == '0' ||number[i] == '4' || number[i] == '6'||number[i]=='8'||number[i]=='5')
				{
					k = 1 ;
					break ;
				}
			}
			
		// value of the k == 1 shows that the given number is can't be truncateable primes 
			if(number[0] == '4' || number[0] == '6'|| number[0] == '8' || number[0] == '9'|| number[0] == '1'||number[len-1] == '1')
			{k = 1 ;}
			else if(k == 0)  // it means possibly it is a truncatalble
			{
				 // there is two truncatable possibility 1) L -> R  2)  R --> L
	
				/*** 	    L -> R 	 ***/
				for( i = 1 ;	i < len ; i++)
				{
					sscanf(&number[i], "%d" , &prime) ;
					if(!checkPrime(prime))
					{
						k = 2 ;
						break ;
					}
				
				}
				/* * If the above loop will pass successfully then k == 0  * */
				if(k == 0)
				for(i = len  - 1 ; i > 0; i--)
				{
					number[i] = '\0' ;
					sscanf(number,"%d",&prime) ;
					if(!checkPrime(prime))
					{
						k = 2 ;
						break ;
					}
				}
			
				if(k == 0 )
				{
					dataList[counter++] = temp ;
					printf("  %d  " , temp) ;
					sum += temp ;
				}

			}
			
		     }
	
		} // end of the while loop
	
	
		printf("counter value : %d  sum : %ld  " , counter ,sum ) ;
	return 0 ;
}
	
