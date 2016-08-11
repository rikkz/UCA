#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int find(int a[],int low,int high,int search)
{
    int x;
    if(low > high)
        return -1;
    int mid = (low + high) / 2;
    //cout<<a[low]<<" "<<a[mid]<<" "<<a[high]<<" "<<search<<endl;
    if (a[mid] == search)
        return 1;
    if( a[low] <= a[mid])
    {
        if(search >= a[low] && search <= a[mid])
          x =  find(a,low,mid-1,search);
        else
        x = find(a,mid + 1,high,search);
    }
    else
    {
        if(a[mid] <= search && a[high]>=search )
        x=find(a,mid+1,high,search);
        else
        x=find(a,low,mid-1,search);
    }
    return x;
}
int main()
{
  int a[]={7,7,1,7,7,7,7,7,7,7};
  cout<<find(a,0,9,1);
}

