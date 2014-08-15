#include <iostream>
using namespace std;
int majority(int *arr,int size)
{
	int count =0;int maj_ele=0;
	for(int i=0;i<size;i++)
	{
		if(arr[i]==arr[maj_ele])
			count++;
		else
			count--;
		if(count==0)
		{
			count=1;
			maj_ele=i;
		}
	}
	return arr[maj_ele];
}
int main()
{
	int arr[9]={3,3,4,2,4,4,3,3,3};
	int size =9;
	int major = majority(arr,size);
	int count =0;
	for(int i=0;i<size;i++)
	{
		if(major==arr[i]) count++;
	}
	if(count>size/2) cout<<"Majority Element is "<<major<<endl;
	else cout<<"none"<<endl;
}