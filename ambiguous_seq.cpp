#include <cstdio>
using namespace std;
int main()
{
	int num;scanf("%d",&num);
	while(num!=0)
	{
		int *seq = new int[num+1];
		seq[0]=-1;
		for(int j=1;j<=num;j++)
			scanf("%d",&seq[j]);
		int flag = 0;
		for(int j=1;j<=num;j++)
		{
			if(seq[seq[j]] != j)
			{
				flag=1;
				break;
			}
		}
		if(flag == 1 )
			printf("%s\n", "not ambiguous");
		else
			printf("%s\n","ambiguous" );
		scanf("%d",&num);
	}
}