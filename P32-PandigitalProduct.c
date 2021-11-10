#include<stdio.h>
#include<stdlib.h>

int main()
{
	int TwoDigit[100] ;
	int ThreeDigit[1000] ;
	int DigitHash[10] = {0} ;
	int product ;
	long long int sum = 0 ;
	int i , j , l , k , m , n , b = 0; 	// for the loop
	int save[20] = {0};
	// stroing the two digit number
	n = 0 ;
	for( i = 1 ; i < 10 ; i++)
	{
		for(j = 1 ; j < 10 ; j++)
			if(i != j )
			   TwoDigit[n++] = i*10 + j ;
	}
        m = 0 ;

	for( i = 1 ; i < 10 ; i++)
	{
		for(j = 1 ; j < 10 ; j++)
		{
			for(l =1 ; l < 10 ; l++)
			if(i != j && i != l  && j != l)
			   ThreeDigit[m++] = i*100 + j*10 + l ;
		}
	}

	for( i = 0 ; i < n ; i++)
	{
		DigitHash[TwoDigit[i] % 10] = 1 ;
		DigitHash[(TwoDigit[i]/10) % 10] = 1 ;

		for(j = 0 ; j < m ; j++)
		{
                if(DigitHash[ThreeDigit[j] % 10] != 1 && DigitHash[(ThreeDigit[j]/10) % 10] != 1 && DigitHash[(ThreeDigit[j] /100)
				 % 10] != 1)
			{
				DigitHash[ThreeDigit[j]%10] = 1 ;
				DigitHash[(ThreeDigit[j]/10)%10] = 1 ;
			        DigitHash[(ThreeDigit[j] / 100) % 10] = 1 ;
				
				product = TwoDigit[i] * ThreeDigit[j] ;
				if(product / 10000  == 0 && product %10 != (product /10)%10 && product %10 != (product /100)%10 && product %10 != (product /1000)%10 &&  (product/10) %10 != (product /100)%10 && (product/10) %10 != (product /100)%10 && (product/10) %10 != (product /1000)%10 &&  (product/100) %10 != (product /1000)%10 && (product /10)%10!= 0 && (product /100)%10 != 0 && product%10 != 0)
				{
					if( DigitHash[product% 10] != 1 && DigitHash[(product/10) % 10] != 1 &&
						 DigitHash[(product/100) % 10] != 1 && DigitHash[(product /1000)%10] != 1)
					{
						
						save[b++] = product ;
						printf("%d  X  %d  =  %d \n",TwoDigit[i] , ThreeDigit[j] , product) ;
					}
				}
				DigitHash[ThreeDigit[j]%10] = 0 ;
				DigitHash[(ThreeDigit[j]/10)%10] = 0 ;
				DigitHash[(ThreeDigit[j] / 100) % 10] = 0 ;

			 }	
		}
	
		DigitHash[TwoDigit[i] % 10] = 0 ;
		DigitHash[(TwoDigit[i]/10) % 10] = 0 ;

	}

	
	for(i = 1 ; i < 10 ; i++)
	{
		DigitHash[i] = 1 ;
		for(j = 1 ; j < 10 ; j++)
		{
			if(i != j)
			{
				for(  k  = 1 ; k < 10 ; k++)
				  if(i != k && j != k)
				   {
					for(l =1 ; l < 10 ; l++)
					if(i != l && j!= l && k != l)
					{
						for(m = 1 ; m < 10 ; m++)
						 if( i != m && j!= m && k!= m &&l != m)
						 {
						    DigitHash[j] = 1 ;
						    DigitHash[k] = 1 ;
						    DigitHash[l] = 1 ;
						    DigitHash[m] = 1 ;
						    product = i *(j*1000 + k *100 + l *10 +m) ;
							if(product / 10000  == 0 && product %10 != (product /10)%10 && product %10 != (product /100)%10 && product %10 != (product /1000)%10 &&  (product/10) %10 != (product /100)%10 && (product/10) %10 != (product /100)%10 && (product/10) %10 != (product /1000)%10 &&  (product/100) %10 != (product /1000)%10 && (product /10)%10!= 0 && (product /100)%10 != 0 && product%10 != 0)
							{
								if( DigitHash[product% 10] != 1 && DigitHash[(product/10) % 10] != 1 && DigitHash[(product/100) % 10] != 1 && DigitHash[(product /1000)%10] != 1)	
								{
								
								save[b++] = product ;
								printf("%d  X  %d%d%d%d  =  %d \n",i,j,k,l,m,product) ;	
								}
						        }  // bigger logic
						    DigitHash[j] = 0 ;
						    DigitHash[k] = 0 ;
						    DigitHash[l] = 0 ;
						    DigitHash[m] = 0 ;
			
						 }
					}
				  }
			}
		}
	DigitHash[i] = 0 ;
	}
	
	for(i = 0 ; i < b ; i++)
	{
		for(j = i+1 ; j < b ; j++)
			if(save[i] == save[j])
				save[j] = 0 ;
	}
	sum = 0 ;
	
	for(i = 0 ; i < b ; i++)
		sum = sum + save[i] ;

	printf("%lld" , sum) ;

return 0 ;
}
