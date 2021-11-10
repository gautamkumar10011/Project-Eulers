#include <stdio.h>
#include<stdlib.h>

int main()
{
	int data_array[29000] ,Abundent[20000];
	int i;
	int j , k , l  ;
	long long int sum = 0 ;

	for(i = 1 ; i <29000 ; i++)
		data_array[i] = 0 ;

	for(i= 12 ; i< 29000 ; i++)
	{
		if(data_array[i] == 0)
		{
			if(check_abundent(i))
		   	{
				// hence i is the abundent number
				k = i ;
				data_array[k] = 1 ;
				while(k < 29000)
				{
					k = k +  i ;
					if(k < 29000)
						data_array[k] = 1 ;
				}
		   	}
		}
	}
//listing the abundent numbers in sorted order
	j = 0 ;
	for(i = 1 ; i < 29000 ; i++)
	{
		if(data_array[i] == 1)
			Abundent[j++] = i ;
	}

	// we have filter abundent numbers and the non abundent numbers
	// j tells that how many numbers that are abundent  and  data_array[i] tells us that the given i is abundent or not
	// our strategy is that we will that we will pick two numbers and check weather that sum of the two abundent is give that 
	// number os not if yes then mark data_array[i] = 1 
	// lastly we will filter the data_array[i] = 0 ; and that sum will be our solution
	l = 0 ;
	for(i = 1 ; i < 28124 ; i++)
	{
			while( l < j && i > Abundent[l] )
				l++ ;		// that tells the upperbound

			if(two_sum_check( i , Abundent , 0 , l))
				data_array[i] =  2 ;
		
	}

// after the filtering the data 
	for( i = 1 ; i < 28124 ; i++)
		if(data_array[i] != 2)
			sum += i ;

	printf("%lld" , sum) ;
return 0 ;
}

int two_sum_check(int value , int *data_array , int lb ,int ub)
{

	while(lb <= ub)
	{
		if( (data_array[lb] + data_array[ub]) == value)
			break ;
		else if( (data_array[lb] + data_array[ub]) > value)
			ub-- ;
		else
			lb++ ;
	}

	return lb <= ub ? 1 : 0 ;
}


int check_abundent(int value)
{
 	// here we are checking the that a given number is abundent or not by brute force
	
	int i = 1 ;
	int sum = 0 ;
	
	for(;i <value ;i++)
	{
		if(value%i == 0)
			sum += i ;
	}
	
	return sum > value ? 1 : 0;
}

