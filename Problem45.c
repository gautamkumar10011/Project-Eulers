#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/**** checking from 144th term *****/ 
long long int problem_45()
{
	int i = 144 ;
	long long int data ;

	while(1)
	{
		data =(long long int) i*(2*i-1) ;
		if(isPandigital(data))		
			return data ;
		i++ ;
	}
}

int isPandigital(long long int data)
{
	long long int c = 2*data ;
	int n =(int) (1+sqrt(1+ 12*c)) / 6 ;
	long long int sq = (long long int)n*(3*n -1)/2;
	if(sq == data)
	 {
		if(IsTri(data))
			return 1 ;
		else
			return 0 ;
	 }
	
	return 0;
}

int IsTri(long long int data)
{
	long long int c = 2*data ;
	int n = (int)(-1 + sqrt(1 + 4*c))/2 ;
	long long int sq = (long long int)n*(n+1)/2 ;
	if(sq == data)
		return 1 ;
	return 0 ;
}


int main()
{

	printf("%lld" , problem_45()) ;
	return 0 ;
}
