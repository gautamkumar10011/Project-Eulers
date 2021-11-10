#include<iostream>


using namespace std ;
int binarySearch(int * ,int ,int ,int) ;	
int problem_39()
{
	int sq[1001] , perimeter[1001] = {0} ;
	int sum ;
	int temp ;
	for(int i = 0 ; i< 1001 ; i++)
		sq[i] = i*i ;

	for(int i = 1 ; i < 1001 ; i++)
	{
		for(int j = i + 1 ; j < 1001 ; j++)
		{
			sum = sq[i] + sq[j] ;
			temp = binarySearch(sq , 1 , 1000 , sum) ;
			if(temp != -1 && (i+j+temp) <= 1000)
				perimeter[i+j+temp/* perimeater*/] += 1 ;
		}
	}				
	// searching the max
	int max = -1 ;
	int index = -2 ;
	for(int i  = 1 ; i < 1001 ; i++)
	{
		if(max < perimeter[i])
			{
			max = perimeter[i] ;
			index =  i ;
			}
	}

return index ;
}

int binarySearch(int *ptr , int lb , int ub ,int key)
{
	
	int mid = (lb + ub) / 2;

	while(lb <= ub)
	{
		mid = (lb + ub) / 2 ;
		if(ptr[mid] == key)
			return mid ;
		else if(ptr[mid] > key)
			ub  = mid - 1 ;
		else
			lb = mid + 1 ;
	}
	
   return -1 ;
}


int main()
{
	cout<< problem_39() <<"\n" ;
	return 0 ;
}		
