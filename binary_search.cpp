#include<iostream>
using namespace std;

int binary_search( int a[] , int low , int high , int find )
{
	if( low > high )
		return 0;
	
	int mid = (low + high) / 2;
	
	if( a[mid] == find )
		return 1;
	
	int x = 0;
	
	x += binary_search( a , low , mid - 1 , find );
	
	if(x == 0)
		x += binary_search(a , mid + 1 , high , find );
	
	return x;
}

int main()
{
	int a[] = { 4 , 5 , 1 , 2 , 3 };
	
	cout<<binary_search( a , 0 , 4 , 6 );
}
