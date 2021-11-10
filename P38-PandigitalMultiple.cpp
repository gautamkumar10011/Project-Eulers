#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std ;
// in order to solve this problem my stretagy is to peak one number 1 2 ...
// then product by 1 2 3  so on unless and until sum of the digit is less than 9
int problem_38()
{
	int beg =  1 ;
	int end = 10000 ;
	int count = 0 ;
	char str[25] ;
	char temp[15] ;
	int product = 0 ;
	int len = 0 ;	
	int digit[10] ={0};
	int max = -1 ;
	int save ;
	// choosing the number
	for( int i = 1 ; i < end ; i++)
	{
		count  = 0 ;
		str[0] = '\0' ;

		for(int j = 1 ; j < 10 ; j++)
		{
			product = i*j ;
			len = sprintf(temp ,"%d" , product) ;
			count += len ;
			strcat(str, temp) ;			
			if(count >= 9)
				break ;
		}

		if(count == 9)
		{	
			int l ;
			for(l= 0 ; l < 9 ; l++)
			{
				if(digit[int(str[l] -'0')] == 0 && int(str[l] -'0') != 0)
					digit[int(str[l] -'0')] = 1 ;
				else
					break ;
			}
			
			if(l == 9)
			{
				sscanf(str ,"%d",&product) ;			
				if(max  < product)
				{
					max = product ;
					save = i ;
				}
			}		

			for(int l = 0 ; l  < 10 ; l++)
				digit[l] =  0 ;
		}
	} // end of the outer loop 
cout << save <<'\n' ;
return max ;
}
