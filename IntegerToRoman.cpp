/***** This is the Simple Implementation of the Integer to Roman Convertion  ****/

#include<iostream>
#include<cstring>

using namespace std ;
// global data ;
char Roman[30] ;
int IntegerToRoman(int Num)
{
	int Index = 0 ;

		if(1000 <= Num)
		{
			while(1000 <= Num)
			{
				Roman[Index++] = 'M' ;
				Num -= 1000 ;
			}
		}

		if(Num >= 900 && Num < 1000)
		{
			Roman[Index++] = 'C' ;
			Roman[Index++] = 'M' ;
			Num -=  900 ;
		}
		
		if(500 <= Num)
		{
			while(500 <= Num)
			{
				Roman[Index++] = 'D' ;
				Num -= 500 ;
			}
		}

		if(Num >= 400 && Num < 500)
		{
			Roman[Index++] = 'C' ;
			Roman[Index++] = 'D' ;
			Num -=  400 ;
		}

		if(100 <= Num)
		{
			while(100 <= Num)
			{
				Roman[Index++] = 'C' ;
				Num -= 100 ;
			}
		}
	
		if(Num >= 90 && Num < 100)
		{
			Roman[Index++] = 'X' ;
			Roman[Index++] = 'C' ;
			Num -=  90 ;
		}

		if(50 <= Num)
		{
			while(50 <= Num)
			{
				Roman[Index++] = 'L' ;
				Num -= 50 ;
			}
		}
	
		if(Num >= 40 && Num < 50)
		{
			Roman[Index++] = 'X' ;
			Roman[Index++] = 'L' ;
			Num -=  40 ;
		}
	
		if(10 <= Num)
		{
			while(10 <= Num)
			{
				Roman[Index++] = 'X' ;
				Num -= 10 ;
			}
		}
	
		if(Num == 9)
		{
			Roman[Index++] = 'I' ;
			Roman[Index++] = 'X' ;
			Num -=  9 ;
		}
	
		if(5 <= Num)
		{
			while(5 <= Num)
			{
				Roman[Index++] = 'V' ;
				Num -= 5 ;
			}
		}
	
		if(Num == 4)
		{
			Roman[Index++] = 'I' ;
			Roman[Index++] = 'V' ;
			Num -=  4 ;
		}
		
		while(Num)
		{
			Roman[Index++] = 'I' ;
			Num -= 1 ;
		}

Roman[Index] = '\0' ;

return strlen(Roman) ;
}

