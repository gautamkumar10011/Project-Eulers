#include<iostream>
#include<set>
#include<cstdio>
using namespace std ;

int problem_92(int limit)
{
	set<int> set89 , set1 ;
	int array[ ] = {85 , 89 ,145 , 42 , 20 , 4 , 16 , 37 ,58  } ;
	int array1[ ] = {44 ,32 ,13 ,10,1 } ;
	char number[12] ;
	int sum ;
	int temp[1000] ;
	int index = 0;
	int start = 1 ;
	int len ;
	int counter = 0 ;
	for(int i = 0 ; i < 9 ; i++)
		set89.insert(array[i]) ;

	for(int i = 0 ; i < 5 ; i++)
		set1.insert(array1[i]) ;

	while(start < limit)
	{
		sum = 0 ;
		index = 0 ;
		len = sprintf(number,"%d" ,start ) ;
		for(int i = 0 ; i< len ; i++)
			sum += int(number[i] -'0')*int(number[i] -'0') ;
		temp[index++] = sum ;
		while(set89.find(sum)  == set89.end() && set1.find(sum)  == set1.end())
		{
			
			len = sprintf(number,"%d" ,sum ) ;
			sum = 0 ;
			for(int i = 0 ; i< len ; i++)
				sum += int(number[i] -'0')*int(number[i] -'0') ;
			temp[index++] = sum ;
		}

		// upto here we are clear that 
		if(set89.find(sum) != set89.end())
		{
			// present in set of  89
			counter++ ;
			for(int i = 1 ; i< index ; i++) 
				set89.insert(temp[i]) ;
			
			if(set89.find(temp[0]) == set89.end())
				set89.insert(temp[0]) ;
		}
		else
		{
		// present in set 1 
			for(int i = 1 ; i< index ; i++) 
				set1.insert(temp[i]) ;
			
			if(set1.find(temp[0]) == set1.end())
				set1.insert(temp[0]) ;
		}
	
		start = start + 1 ;
	}

return counter ;
}
