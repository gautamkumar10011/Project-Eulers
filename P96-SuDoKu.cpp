#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int sudoku[10][10] = {  {0,0,0,0,0,0,0,0,0,0},
			{0,0,8,0,0,0,9,0,7,2},
			{0,6,0,0,0,0,0,0,0,4},
			{0,0,5,0,0,6,0,9,0,1},
			{0,2,0,0,0,0,5,0,0,0},
			{0,3,7,6,1,8,4,2,9,5}, 
			{0,0,0,0,3,0,0,0,0,6},
			{0,9,0,1,0,2,0,0,4,0},
			{0,5,0,0,0,0,0,0,0,9},
			{0,8,4,0,9,0,0,0,2,0}};  // very hard

int row[10][10]  = {0} ;
int col[10][10] = {0} ;
int TCT[4][4][10] ={0} ;   // three cross three (for the three cross three matrix
int counter[10] = {0};
int l  =   0 ;
struct advice
{
  int i , j ;
  int count ;
  int adv[10] ;
};
long int total ;
typedef struct advice advice ;
advice adv1[81] ;
void advicearray(advice *adv) ;
void initial()
{
	int i , j , m,n;
	for(i = 1 ; i < 10 ;i++ )
	{
		for(j = 1 ; j < 10 ; j++)
		{
			if(sudoku[i][j])
			{
				row[i][sudoku[i][j]] = 1 ;
				col[j][sudoku[i][j]]  = 1 ;
				TCT[(int)ceil((double)i/3)][(int)ceil((double)j/3)][sudoku[i][j]] = 1 ;
			}   
		 }  
	}
}


void advicearray(advice *adv1)  
{
	int i , j , k , counter[10] = {0} , m ;
	l = 0 ;
	for(i = 1 ; i < 10 ;i++ )
	{
		for(j = 1 ; j < 10 ; j++)
		{
			if(!sudoku[i][j])
			{
			for(k = 1 ; k < 10 ; k++)					 
			       counter[k] = row[i][k] || col[j][k] || TCT[(int)ceil((double)i/3)][(int)ceil((double) j/3)][k] ;
			
				m = 1 ;
				for(k = 1 ; k < 10 ; k++)	
				{
					if(!counter[k])
					 adv1[l].adv[m++] = k ;
					counter[k] = 0 ;
				}
					adv1[l].count = m  ;
					adv1[l].i = i ;
					adv1[l].j = j ;
					l++ ;
			}
		}
	 } 
		
}
void print()
{
	int i,j;
	for( i = 1 ;  i < 10 ;i++)
	{
		for(j = 1; j < 10 ; j++)
			printf("%d \t",sudoku[i][j]) ;
		putchar('\n');
		putchar('\n');
	}
}

void print1()
{
	int j , k;
		for(j = 0 ; j < l ; j++)
			printf(" (%d  %d  %d) \n",adv1[j].i,adv1[j].j,adv1[j].count) ;}

int sudoku_solver(int i , int j , int lb,int ub)
{
	int k,p,m,num ; // next num

	if(lb == ub)
		return 1 ;
	
	for(k = 1 ; k < adv1[lb].count ; k++)
	{       total++ ;
		num = adv1[lb].adv[k] ;
		p = row[i][num] || col[j][num] || TCT[(int)ceil((double)i/3)][(int)ceil((double) j/3)][num] ;
		if(p == 0)  // recursive call
		{
			sudoku[i][j] = num ;
			row[i][num] = 1 ;
			col[j][num] = 1 ;
			TCT[(int)ceil((double)i/3)][(int)ceil((double) j/3)][num]  = 1;
			if(!sudoku_solver(adv1[lb+1].i , adv1[lb+1].j,lb+1,ub))
			{
				row[i][num] = 0 ;
				col[j][num] = 0 ;
				TCT[(int)ceil((double)i/3)][(int)ceil((double) j/3)][num] = 0 ;
				sudoku[i][j] = 0;
			}
			else
			return 1 ;
		}
		
	}
	return 0 ;

}


void flushall()
{
	int i , j  , k  ;
	for(i = 0 ; i < 10 ; i++)
		{
			for(j = 0 ; j < 10 ; j++)
				{  row[i][j] = 0 ;
				    col[i][j] = 0 ;
				}
			counter[i] = 0 ; 
		}
	for(i = 0 ;  i < 4 ; i++)
		{
			for( j =  0 ; j < 4 ; j++)
				{
					for( k = 0 ; k < 10 ; k++)
						TCT[i][j][k] = 0 ;
				}
		}
}
	
int main()
{
	
	char *filename = "sudokuinput" ;
	FILE *fp = fopen(filename , "r") ;
	char line[15] = {0} ;	
	int i = 0 ,k = 0;
	int unit = 0 , tens = 0 , hundred = 0 ;
	int u , t, h ;
	int sum = 0 ;
	while(i < 50)
	{
	
//		fscanf(fp ,"%s",line) ;
		int j = 0 ; 
		for(j = 0 ; j <9 ; j++)
			{
				fscanf(fp, "%s" , line) ;
				for( k = 1 ; k< 10 ; k++)
					{sudoku[j+1][k] = line[k-1] - '0' ;}
			}
		i++ ;

		initial();
		advicearray(adv1) ;
	  	if(sudoku_solver(adv1[0].i , adv1[0].j , 0 , l)) ;
	//			print();
		unit += sudoku[1][3] ;
		tens += sudoku[1][2] ;
		hundred += sudoku[1][1] ;
		flushall() ;
		
	}
	printf("%d   %d   %d",hundred,tens,unit) ;
	
	printf("\n%d", i) ;
        return 0;
}
