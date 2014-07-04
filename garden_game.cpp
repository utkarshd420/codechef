#include <cstdio>
#include <iostream>
typedef long long int ll;
using namespace std;
ll lcm_cal(ll steps,ll lcm)
{
	if(lcm%steps == 0)
		return lcm;
	else
	{
		ll g=steps,l=lcm;
		if(lcm>steps)
		{
			g=lcm;l=steps;
		}
		lcm=g;
		while(lcm%l!= 0 || lcm%g!=0) 
			lcm++;
	}
	return lcm;
}
int main()
{
	ll num;
	scanf("%lld",&num);
	while(num--)
	{
		ll len;scanf("%lld",&len);
		ll ** arr= new ll*[2];
		arr[0] = new ll [len];
		arr[1] = new ll[len];
		for(ll i=0;i<len;i++)
		{
			int temp=0;
			arr[0][i] = i+1;
			scanf("%lld",&arr[1][i]);
		}
		ll lcm =1;
		for(ll i=0;i<len;i++)
		{
			ll steps =0;
			ll temp_index = i;
			while(arr[1][temp_index] != arr[0][i])
			{
				temp_index = int(arr[1][temp_index])-1;
				steps++;
				printf("The temp_index is %lld steps is %lld\n",temp_index,steps);
				if(steps>4)
					break;
			}
			lcm = lcm_cal(steps,lcm);
		}
		printf("%lld\n", lcm);
	}
}