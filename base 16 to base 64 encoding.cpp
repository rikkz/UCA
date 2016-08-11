#include<iostream>
using namespace std;
char base64digit( unsigned int n )
{
	if( n < 26 ) return 'A' + n ;
	if( n < 52 ) return 'a' + (n - 26) ;
	if( n < 62 ) return '0' + (n - 52) ;
	return ( n == 62 )?'+':'=';
}
void pass( int *array ,int size)
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
	string arr = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d" ;
	int mynum,temp = 0;
	int array[12] = {0};
	for( int i = 0 ; arr[ i ]!='\0'  ; i++ )
	{
		if( i % 3 ==0 && i!=0 )
		{
			pass(array,12);
			temp = 0;
		}
			if( arr[i] >= '0' && arr[i] <= '9' )
				mynum = arr[ i ] - '0';
			else
				mynum = (arr[ i ] - 'a') + 10;
			int loop = 3 ;
			while(loop != -1)
			{
				array[temp++] = 1 & ( mynum >> (loop--) );
			}
 	}
 	if( temp == 12 )
 		pass( array ,12);
 	else if( temp == 4 )
 	{
 		for( int i = 5 ; i >= 2 ; i-- )
		 array[ i ] = array[ i - 2 ];
		array[ 0 ] = 0;
		array[ 1 ] = 0;
		pass( array , 6 );	
	}
	else if( temp == 8 )
 	{
 		for( int i = 11 ; i >= 10 ; i-- )
		 array[ i ] = array[ i - 4 ];
		array[ 6 ]  = array[ 7 ] = array[ 8 ] = array[ 9 ] = 0;
		pass( array , 12 );	
	}
	
 		
}
