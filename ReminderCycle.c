#include<stdio.h>
#include<stdlib.h>

// this program is to slove the remainder cycle problem
// My Strategy
	// If remainder repeats then cycle occured  else no cycle 
	// we will use linear value index hash to check the occurance of the remainder 
	// we will also cont the no of times of the cycle

int main()
{
	int remainder_hash[1001] = {0} ; // this will store the counter of the cycle
	int storing_remainder[1000] ;
	int R_count = 0 ;
	int value = 1 ;
	int i = 1  , j = 0; 
	int counter = 0 ;
	int max = -1 , data ;
	for(i = 2 ; i < 1001 ; i++)
	{
		value = 1 ;
		counter   = 0 ;
		j = 0 ;
		while( value % i != 0 && remainder_hash[value % i] != 1)
		{
			remainder_hash[value % i] = 1 ;
			storing_remainder[j++] = value % i ;
			value = (10 * value) %i ;
			counter++ ;
		}
			
		if(counter > max)
		{
			max = counter ;
			data = i ;;
		}

	
	 	for(value = 0 ; value < j ; value++)
			remainder_hash[storing_remainder[value]] = 0 ;

	}

	printf("%d %d" , max , data) ;
return 0 ;
}
			
