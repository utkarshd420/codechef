#include <iostream>
using namespace std;
int binary_search(int *arr,int p,int r,int ele,int size)
{
	int mid = (p+r) /2;
	while(p<=r)
	{

		if(arr[mid]==ele){
			if(mid+1>size)
				return mid;
			if(arr[mid+1]!=ele)
				return mid;
			else
				p=mid+1;
		}
		else if(arr[mid]<ele)
		{
			p=mid+1;
		}
		else
		{
			r=mid-1;
		}
		mid=(p+r)/2;
	}
	return -1;
}
int main()
{
	int a[]={1,1,2,2,2,3,3,4,9,10,11,23,45,56,78};
	int size = sizeof(a)/sizeof(a[0]);
	cout<<binary_search(a,0,size-1,12,size-1)<<endl;
}