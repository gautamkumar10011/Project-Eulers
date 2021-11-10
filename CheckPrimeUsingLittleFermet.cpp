/***** Checking the prime number using Little Ferrmt theorem , Log(n) time complexity *****/
long long int checkPrime(long long int num)
{
	if(num == 2 )
		return 1 ;
	
	long long int p = num -1  ;
	long long int val = 1 ;
	long long int co = 2 ;
	
	while(p)
	{
		if(p %2 == 1)
		{
		val = (val * co )% num ;
		}
		co = (co * co) % num ;
		p =p>>1 ;
	}
	
 return val == 1 ? 1 : 0 ;
}
