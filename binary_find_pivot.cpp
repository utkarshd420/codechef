#include <iostream>
using namespace std;
int find_pivot(int *arr,int p,int r)
{
	int mid = (p+r)/2;
	if(r<p) return 0;
	if(r==p) return p;
	if(mid<r && arr[mid]>arr[mid+1])
		return mid+1;
	else if(mid>p && arr[mid-1]>arr[mid])
		return mid;
	if(arr[r]>arr[mid])
		return find_pivot(arr,p,mid-1);
	return find_pivot(arr,mid+1,r);
}
int main()
{
	int a[] = {3,4,5,6,1,2};
	cout<<find_pivot(a,0,5)<<endl;
}