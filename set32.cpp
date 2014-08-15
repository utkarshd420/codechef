#include <iostream>
using namespace std;
int partition(int *arr,int p,int r)
{
	int key=arr[r];
	int j=p-1;
	for(int i=p;i<r;i++)
	{
		if(arr[i]<=key)
		{
			j++;
			int temp = arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	int temp=arr[j+1];
	arr[j+1]=key;
	arr[r]=temp;
	return j+1;
}
void quick(int *arr,int p,int r)
{
	if(p<r)
	{
		int q =partition(arr,p,r);
		quick(arr,p,q-1);
		quick(arr,q+1,r);
	}
}
int main()
{
	int arr[]={1,1,1,3,4,5,6,3,4,4,5,5,5,6,7,8,1};
	int size = sizeof(arr)/sizeof(arr[0]);
	quick(arr,0,size-1);
	cout<<"Sorted array is :";
	for(int i=0;i<size;i++)
		cout<<arr[i]<<", ";
	cout<<endl;
	for(int i=0;i<size;)
	{
		int count=1;
		int key=arr[i++];
		while(arr[i]==key && i<size)
		{
			count++;
			i++;
		}
		if(count%2==0)
			cout<<arr[i-1]<<", ";

	}
}