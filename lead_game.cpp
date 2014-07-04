#include <cstdio>
#include <cstdlib>

using namespace std;
 
int main()
{
	int n; scanf("%d",&n);
	int winner = 1;int max_lead = 0;
	int score_p1 = 0;int score_p2 = 0;
	for(int i=0;i<n;i++)
	{
		int pl1;int pl2;
		scanf("%d",&pl1);
		scanf("%d",&pl2);
		pl1+= score_p1;
		pl2+= score_p2;
		if(pl1 > pl2)
		{
			if((pl1-pl2)>max_lead)
			{
				max_lead= (pl1-pl2);
				winner =1;
			}
		}
		else
		{
			if((pl2-pl1)>max_lead)
			{
				max_lead= (pl2-pl1);
				winner =2;
			}
		}
		score_p2 = pl2;
		score_p1 = pl1;

	}
	printf("%d %d\n",winner,max_lead);
}