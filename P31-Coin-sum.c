#include<stdio.h>
#include<stdlib.h>

int coin_sum(int n ,int *coins ,int W)
{
	if(W == 0)
		return 1 ;
	if(W < 0 )
		return 0 ;
	if(n < 0 && W>=1)
		return 0 ;
	int left = coin_sum(n-1 , coins , W) ;
	int right = coin_sum(n,coins , W-coins[n]) ;
	return left + right;
}
int main()
{
	int coins[8]={1,2,5,10,20,50,100,200} ;
	int W = 200;

	printf(" total number of ways : %d " , coin_sum(7 , coins , W) ) ;
}
