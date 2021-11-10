#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std ;
/*extern*/ int RomanToInteger(char *) ;
/*extern*/ int IntegerToRoman(int) ;
char number[30] ;
int data ;
char Roman[30] ;
int problem_89()
{
	FILE *fp ;
	fp = fopen("Roman.txt" , "r") ;
	
	int sum = 0 ;
	char *ptr ;
	while(!feof(fp))
	{
		fscanf(fp ,"%s" , number) ;		
		data = RomanToInteger(number) ;		
		sum += strlen(number) - IntegerToRoman(data) ;
	}
	// one probelm occured last line repeat twice
	return sum ;
}

int RomanToInteger(char *RomanNum)
{
	
	int len = strlen(RomanNum) ;
	int Numral[300] = {0} ;
	Numral[int('M')] = 1000 ;
	Numral[int('D')] = 500 ;
	Numral[int('C')] = 100 ;
	Numral[int('L')] = 50 ;
	Numral[int('X')] = 10 ;
	Numral[int('V')] = 5 ;
	Numral[int('I')] = 1 ;
	int max = -1 ;
	int Integer = 0;
	for(int i = len-1 ; i >-1 ; i--)
	{
		if(Numral[int(RomanNum[i])] >= max)
		{
			Integer += Numral[int(RomanNum[i])] ;
			max = Numral[int(RomanNum[i])];
		}
		 else
		{
			Integer -= Numral[int(RomanNum[i])] ;			
		}
	}

return Integer ;
}


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

