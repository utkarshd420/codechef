#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int num_int;scanf("%d",&num_int);
	for(int num=0;num<num_int;num++)
	{
		int n; scanf("%d",&n);
		int res[n][n];
		for(int i = 0;i<n;i++)	
			for(int j=0;j<n;j++)
				res[i][j]=0;
		for(int i =0;i<n;i++ )	
		{
			for(int j=0;j<=i;j++)
			{
				int temp_val;
				scanf("%d",&temp_val);
				if(i==0)
					res[i][j] = temp_val;
				else
				{
					if((j-1)>=0)
						res[i][j] = max(max(res[i][j],res[i-1][j]+temp_val),res[i-1][j-1]+temp_val);
					else
						res[i][j] = max(res[i][j],res[i-1][j]+temp_val);
				}
			}
		}
		int max=0;
			for(int j=0;j<n;j++)
				if(res[n-1][j]>max)
					max = res[n-1][j];
			printf("%d\n",max);
		}

}
