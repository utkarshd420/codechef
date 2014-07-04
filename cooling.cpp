#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int num;scanf("%d",&num);
	for(int k=0;k<num;k++)
	{
		int dish_no; scanf("%d",&dish_no);
		vector<int> dish,pie;
		for(int i=0;i<dish_no;i++)
		{
			int temp;scanf("%d",&temp);
			pie.push_back(temp);
		}
		for(int i=0;i<dish_no;i++)
		{
			int temp;scanf("%d",&temp);
			dish.push_back(temp);
		}
		sort(pie.begin(),pie.end());
		sort(dish.begin(),dish.end());
		int flag =0;
		for(int i=0;i<dish_no;i++)
		{
			if(dish[i]>=pie[flag])
				flag++;
		}
		//printf("Flag is ----> %d\n",flag);
		if(flag == 0)
			printf("%d\n",0 );
		/*else if(flag == dish_no)
			printf("%d\n",flag);*/
		else
			printf("%d\n",flag);
	}
	

}
