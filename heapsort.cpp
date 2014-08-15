#include <cstdio>
using namespace std;
int heap_size;
void maxHeapify(int *arr,int i)
{
	int left=2*i+1;
	int right =2*i+2;
	int largest;
	if(left<=heap_size && arr[left]>arr[i])
		largest=left;
	else
		largest=i;
	if(right<=heap_size && arr[right]>arr[largest])
		largest=right;
	if(i!=largest){
		int temp = arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		maxHeapify(arr,largest);
	}
}
void buildMaxHeap(int *arr,int length)
{
	heap_size = length-1;
	for(int i=length/2;i>=0;i--)
		maxHeapify(arr,i);
	printf("Heap size is %d\n", heap_size);
	for(int i=0;i<length;i++)
		printf("%d, ",arr[i]);
	printf("\n");
}
void heapSort(int *arr,int length)
{
		while(heap_size>=1){
			printf("Step %d\n", heap_size);
			printf("Start with\n");
			for(int i=0;i<length;i++)
				printf("%d, ",arr[i]);
			printf("\n");
			int temp=arr[heap_size];
			arr[heap_size] = arr[0];
			arr[0]=temp;
			heap_size--;
			printf("Stop with\n");
			for(int i=0;i<length;i++)
				printf("%d, ",arr[i]);
			printf("\n");
			maxHeapify(arr,0);
		}
}
int main()
{
	int arr[]={5,4,3,2,1,-1,-2};
	int length = 7;
	buildMaxHeap(arr,length);
	heapSort(arr,length);
	for(int i=0;i<length;i++)
		printf("%d, ",arr[i]);
}