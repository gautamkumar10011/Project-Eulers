/**** list of the prime is hard coded just for the solution specific *****/
/**** Sieve of Eratosthenes can also be used to get the primese      *****/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int prime[1000] = {2 ,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163, 167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257 ,    263,    269,    271,    277,    281,     283,    293,    307,    311,    313,   317,    331,    337 ,    347,    349,     353,    359,    367,    373,    379,    383,    389,    397,    401,    409,     419,   421,    431,    433,    439,    443,    449,    457,    461,    463,     467,    479,    487,    491,    499,    503,    509,   521,    523,    541,     547,    557,    563,    569,    571  ,  577,    587,    593,    599,    601,     607,    613,    617,   619,    631,    641  ,  643,    647,    653,    659,     661,    673,    677,    683,    691,    701,    709,    719,    727,   733,     739,    743,    751,    757,    761 ,   769,    773,    787,    797,    809,     811,   821    , 823,    827,    829,   839,    853,    857   , 859,    863,     877,    881,    883,    887,    907,    911,    919 ,   929,    937,    941,     947,   953,    967,    971,    977,    983,    991,997} ;

	int i , odd[1000] ,j = 0 , l ,flag = 1 ;
	int value ;
	int savea ,saveb , max = -1 ,n;
	for( i = 0 ; i < 1000 ; i = i+2)
	{
		odd[i] = 2*j + 1 ;
		odd[i+1] = -odd[i] ;
		j++ ;
	}

// primes ---> a  odd --.> b

	for(i = 0 ;  i < 168; i++)
	{
		l = i ;
		for(j = 0 ; j < 1000 ; j++)
		{
			n = 0 ;
			flag =1 ;
			while(flag)
			{
				value = n*n + odd[j] * n + prime[i] ;
				printf(" %d  " ,value) ; 
				if(l > -1 && prime[l] == value )
				{
					n++ ;
				}
				else 
					flag = 0 ;
		
				if(odd[j] > 0)
					l++ ;
				else
					l-- ;
			}
			
			if( max < n )
			{
				savea = prime[i] ;
				saveb = odd[j] ;
				max = n ;
				
			}
			l = i ;
		}
	}
		
	printf("%d   %d  %d "  , savea ,saveb ,max) ;

return 0 ;
}
