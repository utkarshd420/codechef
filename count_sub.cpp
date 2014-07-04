#include <cstdio>
#include <string>
using namespace std;

int main()
{
	int num;scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		int len;scanf("%d",&len);
		char *arr = new char[len];
		scanf("%s",arr);
		long long int count = 0;
		for(int j=0;j<len;j++)
		{
			if(arr[j]=='1')
				count++;
		}
		long long int first_term = ((count)*(count-1))/2;
		long long int res = first_term + count;
		printf("%lld\n",res );
	}
}