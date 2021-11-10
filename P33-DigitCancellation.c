#include<stdio.h>


int main()
{
	
	int TwoDigit1[100] , TwoDigit2[100] ;
	int i , j , gcd_v ,num[4] ={0},den[4] = {0};
	int savenum[4] , saveden[4] ,l = 0;
	int counter = 0 ;
	// formation of the two digit numbers
	for(i = 1  ; i < 10 ; i++)
	{
		for(j = 1 ; j < 10 ; j++)
		{
			if(i != j)
			{
				TwoDigit1[counter] = i * 10  + j ;
				TwoDigit2[counter++ ] = i* 10 + j ;
			}
		}
	}

// this is for the trivial solution

	for(i = 0 ; i < counter ; i++)
	{
		for(j = 0 ; j < counter ; j++)
		{
			if(TwoDigit1[i]%10 != TwoDigit2[j]%10 && TwoDigit1[i]%10 != (TwoDigit2[j]/10)%10 && TwoDigit2[i]%10 != (TwoDigit1[j]/10)%10 && (TwoDigit2[i]/10)%10 != (TwoDigit1[j]/10)%10 )
			{/*do nothing*/}
			else if(i != j && TwoDigit1[i] < TwoDigit2[j])
			{	
				gcd_v = gcd(TwoDigit1[i] , TwoDigit2[j]) ;
				if(gcd_v == 1)
				{/* doNothonh*/}
				else
				{
					num[0]  = TwoDigit1[i] / gcd_v ;
					den[0]  = TwoDigit2[j] / gcd_v ;
					if(num[0] *2 < 10 && den[0]*2 < 10)
					{	num[1] = 2*num[0] ;
						den[1] = 2*den[0] ;}
					
					if(num[0] *3 < 10 && den[0]*3 < 10)
					{	num[2] = 3*num[0] ;
						den[2] = 3*den[0] ;}
					
					if(num[0] *4 < 10 && den[0]*4 < 10)
					{	num[3] = 4*num[0] ;
						den[3] = 4*den[0] ;}

					// if first first digit are equal
					if(TwoDigit1[i]%10 == TwoDigit2[j]%10)
					{
					    if(num[0] == TwoDigit1[i]/10)%10 && den[0] == TwoDigit2[i]/10)%10 ||num[1] == TwoDigit1[i]/10)%10 && den[1] == TwoDigit2[i]/10)%10||num[2] == TwoDigit1[i]/10)%10 && den[2] == TwoDigit2[i]/10)%10||num[3] == TwoDigit1[i]/10)%10 && den[3] == TwoDigit2[i]/10)%10)
					    {
						savenum[l] = num[0] ;
						saveden[l++] = den[0] ;
					     }
						
					}
				}

				

			}
		}
	}



int gcd(int a , int b)
{
	if( b == 0)
		return a ;
	if( b > a)
		return gcd(b,a) ;
	return gcd(b , a%b) ;
}
