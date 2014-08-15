#include <cstdio>
using namespace std;
int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		int n,k;
		scanf("%d",&n);
		scanf("%d",&k);
		int *arr=new int[n];
		int flag=0;
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		
		for(int i=0;i<n;i++)
		{
			int num=arr[i];
			/*if(flag>=k)
			{
				printf("YES\n");
				flag=-1;
				break;
			}*/
			if(num%2==0)
				flag++;
		}
		if(k==0 && flag>=n)
		{
			printf("NO\n");
			continue;
		}
		if(flag >= k)
		{
			printf("YES\n");
		}
		/*else if(flag!=-1)
		{
			printf("NO\n");
		}*/
		else
			printf("NO\n");
		flag=0;
	}
}