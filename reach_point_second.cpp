#include <cstdio>

typedef long long int ll;
using namespace std;
ll abs(ll diff)
{
	if(diff>=0)
		return diff;
	else
		return -diff;
}
int main()
{
	int num;scanf("%d",&num);
	while(num--)
	{
		ll x,y;
		scanf("%lld",&x);scanf("%lld",&y);
		x = ll(abs(x));y = ll(abs(y));
		int flag=0;
		ll res_steps = 0;
		if(x>=y)
		{
			res_steps += 2*y;
			x =x-y;
			y=0;
			flag=0;
		}
		else
		{
			res_steps+=2*x;
			y = y-x;
			x=0;
			flag=1;
		}
		//printf(" x is %lld\n", x);
		//printf(" y is %lld\n", y);
		//printf(" res_steps is %lld\n", res_steps);
		ll diff= ll(abs(y-x));
		if(flag==0)
		{
			if(diff%2 == 0)
			{
				res_steps += 2*diff;
			}
			else
			{
				res_steps += 2*(diff-1) +3;
			}
			printf("%lld\n", res_steps);
		}
		else
		{
			if(diff%2 == 1)
			{
				res_steps += 2*(diff-1) +1;
			}
			else
			{
				res_steps += 2*diff;
			}
			printf("%lld\n", res_steps);
		}

	}
}