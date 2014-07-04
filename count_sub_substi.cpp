#include <cstdio>
using namespace std;

using namespace std;

int main()
{
	int num;scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		int len;scanf("%d",&len);
		char *arr = new char[len];
		scanf("%s",arr);
		int count = 0;long long int res=0;
		for(int j=0;j<len;j++)
		{
			if(arr[j]=='1')
				count++;
		}
		int flag =1;
		for(int j=0;j<len;j++)
		{
			if(arr[j]== '1')
			{
				res = res+(count-flag);
				flag++;
			}
		}
		printf("%lld\n",res+count);
	}
}