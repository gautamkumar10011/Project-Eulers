#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std ;
 int checkPrime(int ) ;

 int problem_41(int start) 
{
	
	int val =  7000001 ;
	int flag = 1 ;
	int digit[10] = {0} ;
	char data[11] ;
	int len ;
	int max = 0 ;
	//cout<< val ;
 // my observation there can't be 8 digit of 9 digit prime 	reason sum of the digit div by 3 smilarly 5 n 6 digit pan not posible
	while(val < 7700000)	
	{
		val = val + 2 ;
		if(checkPrime(val))
		{
			len = sprintf( data , "%d" ,val) ;
			int i ;
			for(i = 0 ; i < len ; i++)
			{				
				if(digit[int(data[i] -'0')] == 0 && int(data[i] -'0') <= 7)
					digit[int(data[i] -'0')] = 1 ;
				else
					break ;
			}
	
			if(i == len)
			{
				if(max < val)
					max = val ;
					
			}


			for(int j = 1 ; j < 10 ; j++)
				digit[j] = 0 ;	

			
		}
	}

return max ;
}

 int checkPrime( int num)
{
	if(num == 2 )
		return 1 ;
	int val = 1 ;
	/*int p = num -1  ;
	
	int co = 5 ; */
	 int i = 0 ;
	int j =(int) sqrt(num) ;
	
	for(i = 2 ; i <= j ; i++)
		if((num % i) == 0)
			break ;

	return (num%i) == 0 ? 0 : 1 ;
			

	/*while(p != 0)
	{
		if(p %  2 == 1)
		{
		val = (val * co )% num ;
		}
		co = (co * co) % num ;
		p =p>>1 ;
	} */
	
 return val == 1 ? 1 : 0 ;
}
