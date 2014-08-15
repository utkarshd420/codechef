#include <cstdio>
using namespace std;
int partition(int *arr,int p,int r)
{
	int k = arr[r];
	int i=p-1;
	for(int j=p;j<r;j++)
	{
		if(arr[j]<=k)
		{
			i++;
			int temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
		}
	}
	int temp=arr[i+1];
	arr[i+1]=k;
	arr[r]= temp;
	return i+1;
}
void quick(int *arr,int p,int r)
{
	if(p<r)
	{
		int q = partition(arr,p,r);
		quick(arr,p,q-1);
		quick(arr,q+1,r);
	}
}
int main()
{
	int arr[]={5,4,3,2,1,-1,-2};
	quick(arr,0,6);
	for(int i=0;i<7;i++)
		printf("%d, ",arr[i] );
}
