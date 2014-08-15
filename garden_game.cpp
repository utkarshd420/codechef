#include <cstdio>
typedef unsigned long long int ll;
using namespace std;
ll modulo = 1000000007;
/*ll lcm_stack[10];
ll count =0;*/
ll abs(ll a, ll b)
{
	if(a>=b)
		return a-b;
	else
		return b-a;
}
ll get_gcd(ll a ,ll b)
{
	ll r =a%b;
	while(r !=0)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
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
		ll denom = get_gcd(g,l);
	//	printf("G is %lld and L is %lld\n",g,l );
		lcm = (g/(denom));
	// 	printf("%lld , ",lcm);
		lcm = (lcm*l)%modulo;
		/*if(lcm > modulo)
		{
			lcm_stack[count++]=lcm;
			//printf("Pushed into list %lld\n",lcm);
			lcm = 1;
		}
		//lcm=g;
		/*while(lcm%l!= 0 || lcm%g!=0) 
			lcm++;*/
	}
	return lcm;
}
int main()
{
	ll num;
	scanf("%lld",&num);
	//printf("%ld\n", sizeof(unsigned long long));
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
		for(int i=0;i<len;i++)
		{
			ll steps =1;
			int temp_index=i;
			while( arr[1][i]!=0 && (arr[1][temp_index] != arr[0][i]) )
			{
				ll k =arr[1][temp_index];
				if (temp_index!=i)
					arr[1][temp_index]= 0;
				temp_index = int(k)-1;
				steps++;
			}
			arr[1][temp_index]= 0;
			arr[1][i]= 0;
			/*for(int j=0;j<len;j++)
				printf("%lld , ",arr[1][j] );
			printf("   and steps are %lld  \n",steps);*/
			lcm = lcm_cal(steps,lcm);
			//printf("Lcm is %lld\n", lcm);	
		}
		/*if(count!=0)
		{
			int temp = 0;
			ll gcd = lcm_stack[temp++];
			ll prod=get_gcd(gcd,lcm);
			while(temp<count)
			{

				ll ele = lcm_stack[temp++];
				prod*=ele;
				gcd = get_gcd( ele , gcd );
				prod/=gcd;
				//printf("The prod is %lld\n", prod);
				//lcm_stack.pop_front();
			}
			printf("%lld\n", prod%modulo);
			//return 0;
		}
		else*/
			printf("%lld\n", lcm%modulo);
		//return 0;
	}
}