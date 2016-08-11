#include<iostream>
using namespace std;
int base64digit( char n )
{
	if( n >= 'A' &&  n<='Z' ) return n - 'A' ;
	if( n >= 'a' &&  n<='z' ) return 26 + n - 'a' ;
	if( n >= '0' &&  n<='9' ) return 52 + n - '0' ;
	return ( n == 62 )?'+':'/';
} 
void pass( int *array ,int size )
{
	int n = 0 , val[ 8 ] = { 128, 64 , 32 , 16 , 8 , 4 , 2 , 1 };
	for( int i = 0 ; i < size ; i++ )
	{
		n += val[ i%8 ]*array[ i ];
		if( (i + 1) % 8 == 0 )
		{
			cout<<char(n);
			n = 0;
		}
	}
}
int main()
{
	string arr = "YW55IGNhcm5hbCBwbGVhc3Vy" ;
	int mynum,temp = 0;
	int array[24] = {0};
	for( int i = 0 ; arr[ i ]!='\0'  ; i++ )
	{
			if(arr[i]!='=')
			{
				mynum = (int)(base64digit(arr[ i ]));
				int loop = 5 ;
				while(loop != -1)
				{
					array[temp++] = 1 & ( mynum >> (loop--) );
				}
			}
			else
				temp = temp - 2;
 			if( (i+1) % 4 ==0 || arr[i+1]=='\0')
			{
			pass(array,temp);
			temp = 0;
			}
	 }

}
