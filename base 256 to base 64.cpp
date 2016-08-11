#include<iostream>
using namespace std;
char base64digit( unsigned int n )
{
	if( n < 26 ) return 'A' + n ;
	if( n < 52 ) return 'a' + (n - 26) ;
	if( n < 62 ) return '0' + (n - 52) ;
	return ( n == 62 )?'+':'/';
}
void pass( int *array ,int size )
{
	int n = 0 , val[ 6 ] = { 32 , 16 , 8 , 4 , 2 , 1 };
	for( int i = 0 ; i < size ; i++ )
	{
		n += val[ i%6 ]*array[ i ];
		if( (i + 1) % 6 == 0 )
		{
			cout<<base64digit(n);
			n = 0;
		}
	}
}
int main()
{
	string arr = "asure." ;
	int mynum,temp = 0;
	int array[24] = {0};
	for( int i = 0 ; arr[ i ]!='\0'  ; i++ )
	{
		if( i % 3 ==0 && i!=0 )
		{
			pass(array,24);
			temp = 0;
		}
			mynum = (int)(arr[ i ]) ;
			int loop = 7 ;
			while(loop != -1)
			{
				array[temp++] = 1 & ( mynum >> (loop--) );
			}
 	}
 	if( temp == 24 )
 		pass( array , 24 );
 	else if( temp == 16 )
 	{
 		array[ 16 ] = array[ 17 ] = 0;
		pass( array , 18 );	
		cout<<"=";
	}
	else
 	{
 		for( int i = 8 ; i <= 11 ; i++ )
		 array[ i ] = 0;
		pass( array , 12 );
		cout<<"==";	
	}	
}
