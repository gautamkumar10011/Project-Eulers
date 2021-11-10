#include<stdio.h>
#include<stdlib.h>

int checkPalindromic(int) ;
int Ifpalindome(char *,int ,int) ;
int convertInBinary(char * , int) ;

int main()
{
	// declaration section 
	FILE  *fp ;
	long long int sum = 0 ;
        int	i = 1 ;
	// Main Implementation of the code

	 // open the file 

	while(i < 1000000)
	{
		if(checkPalindromic(i))
			sum += i;
		i++ ;
	}

	printf("Our sum is  : %lld" , sum) ;

	return 0 ;
}

int checkPalindromic(int value)
{
	char primeBin[33] ;// storing the binary form of the number
	char Number[20] ;  	   // storing the number in string form 
	int len ;

        len = sprintf(Number , "%d" , value) ;
	if(Ifpalindrome(Number ,0, len-1))
	{
		len = convertInBinary(primeBin,value) ;
 		if(Ifpalindrome(primeBin , 0 , len - 1) )
			return 1 ;
		else
			return 0 ;
	}

        return 0 ;
}

int Ifpalindrome(char *string ,int lb ,int  ub) 
{
	while(lb < ub)
	{
		if(string[lb] != string[ub])
			break ;
		lb++ ; ub-- ;
	}
	
	return lb >= ub ? 1 : 0 ;
}

int convertInBinary(char *string , int number)
{
	int index = 0;
	while(number)
	{
		string[index++]  = number%2 ;
		number = number/2 ;
	}
	
	string[index] = '\0' ;
	return index ;
}
