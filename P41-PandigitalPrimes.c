/***** using permutation to generate nmber ***/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool primechecker(char *prime)
{
	long long num = atoll(prime) ;
	long long p = num  - 1 ;
	long long val = 1 ;
	//printf("%lld",num) ;
	//getchar() ;
	if(num % 2 == 0)
		return false ;
	long long b = num-1 ;
	
	while(p)
	{
		if(p%2)
			val = val*b % num ;
	
		b = b*b % num ;
		p = p >> 1 ;
	}
	
	if(val== 1)
		printf("%lld",num) ;

	return val == 1 ? true : false ;
}

bool permutation_prime(char *digit , int n , int depth , int *visit , char *perm)
{
	if(depth == n - 3)
	{
		perm[n] = '\0' ;
		if( primechecker(perm))
			return true ;
		else
			return false ;
	}

	int i  ;
	for(i = 0 ; i < n ;i++)
	{
		if(!visit[i])
		{
			visit[i] = 1 ;
			perm[depth] =  digit[i] ;
			if(permutation_prime(digit , n , depth + 1, visit , perm ))
					return true ;
			visit[i] = 0 ;
		}
	}

	return false ;
}

int main()
{
	char digit[11] = {'9','8','7','6','5','4','3','2','0','1'} ;
	char perm[12] ;
	int visit[12] = {0} ;
	printf("%d",permutation_prime(digit , 10 , 0 , visit , perm)) ;
}
