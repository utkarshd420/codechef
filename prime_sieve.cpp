#include <cstdio>
#include <string>

using namespace std;
int *arr = new int[1003002];
void prime_sieve()
{
	for(int i=2;i<1003002;i++)
	{
		arr[i] = i;
	}
	for(int i=2;i<1003002;i++)
	{
		int currnum = arr[i];
		if(currnum!=0)
		{
	//	printf("%d\n",currnum);
		for(int j=i+currnum;j<1003002;j+=currnum)
		{
			if(arr[j]% currnum== 0)
				arr[j]=0;
		}
		}
	}
	
}
int check_prime(int number)
{
	if(arr[number] != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int num;scanf("%d",&num);
	prime_sieve();
	int count =0;
	for(int i=0;i<5*100000;i++)
	{
			if(check_prime(i)==1)
				count++;
	}
	printf("%d\n",count );
}
