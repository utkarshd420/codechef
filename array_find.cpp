#include <cstdio>
using namespace std;
int partition(int *arr,int p,int r)
{
	int key= arr[r];
	int j=p-1;
	for(int i=p;i<r;i++)
	{
		if(arr[i]<=key)
		{
			j++;
			int temp= arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	int temp = arr[j+1];
	arr[j+1]=key;
	arr[r]=temp;
	return j+1;
}
void quick(int *arr,int p,int r)
{
	if(p<=r)
	{
		int q =partition(arr,p,r);
		quick(arr,p,q-1);
		quick(arr,q+1,r);
	}
}
int main()
{
	int arr[5]={5,4,3,2,1};
	int sum;
	scanf("%d",&sum);
	quick(arr,0,4);
	printf("Sorted arr is \n");
	for(int i=0;i<5;i++) 
	{
		printf("%d, ",arr[i] );
	}
	printf("\n");
	int p=0,r=4;
	while(p<=r)
	{
		if(arr[p]+arr[r] == sum)
		{
			printf("%d,%d\n",arr[p],arr[r]);
			p++;
		}
		else if(arr[p]+arr[r] > sum)
			r--;
		else
			p++;
	}
}