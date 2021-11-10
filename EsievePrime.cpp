#include<iostream>
using namespace std ;
int *flag ;
void setNonPrime(int *,int , int) ;
int * EsievePrimeGenerator(int range)
{
	flag = new int[10000] ;
	if(range > 10000)
		return NULL ;
	for(int i = 1 ; i< range ; i++)
		flag[i] = true ;

	for(int j = 2 ; j < range ; j++)
	{
		if(flag[j] == true)
			setNonPrime(flag , range,j) ;
	}

return flag ;
}
QC
void setNonPrime(int flag[] , int ub ,int prime)
{
	for(int i = prime*prime ; i <  ub ; i = i+ prime)
		flag[i] = false ;
}
