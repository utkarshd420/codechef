#include <cstdio>
using namespace std;
int abs(int p)
{
	if(p<0)
		return -p;
	else
		return p;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int x,y;
		scanf("%d",&x);
		scanf("%d",&y);
		int counter=1;
		bool inc=true;
		int direction=1;
		//int oldcount=counter;
		int xcoord=0,ycoord=0;
		int flag=0;
		int count_stepx=0;
		int count_stepy=0;
		while(abs(xcoord)<abs(x))
		{
			if(direction==1)
			{
					int temp = xcoord;
					xcoord+=counter;
					if(temp<=x && xcoord>=x)
					{
						flag=1;
						break;
					}
			}
			else
			{
					int temp=xcoord;
					xcoord-=counter;
					if(temp>=x && xcoord<=x)
					{
						flag=1;
						break;
					}
			}
			counter+=2;
			count_stepx++;
			direction = ~direction;
		}
		if(flag==0){
			printf("NO\n");
			continue;
		}
		counter=2;direction=1;flag=0;
		while(abs(ycoord)<abs(y))
		{
			if(direction==1)
			{
					int temp = ycoord;
					ycoord+=counter;
					if(temp<=y && ycoord>=y)
					{
						flag=1;
						break;
					}
			}
			else
			{
					int temp=ycoord;
					ycoord-=counter;
					if(temp>=y && ycoord<=y)
					{
						flag=1;
						break;
					}
			}
			counter+=2;
			count_stepx++;
			direction = ~direction;
		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
		/*printf("steps are %d\n",count_step);
		direction=1;
		if(xcoord)
		while(count_step!=1)
		{
			if(direction==1)
				ycoord+=counter;
			else

		}*/
		/*
		while(abs(xcoord) <=abs(x) || abs(ycoord)<=abs(y))
		{
		//	printf("%d %d Counter is ,%d\n",xcoord,ycoord ,counter);
			if(inc)
			{
				if(direction==1){
					int temp = xcoord;
					xcoord+=counter;
					if(ycoord==y && temp<=x && xcoord>=x)
					{
						printf("YES\n");
						flag=1;
						break;
					}
				}
				else{
					int temp=xcoord;
					xcoord-=counter;
					if(ycoord==y && temp>=x && xcoord<=x)
					{
						printf("YES\n");
						flag=1;
						break;
					}
				}
				counter++;
				inc =false;
			}
			else
			{
				if(direction==1){
					int temp = ycoord;
					ycoord+=counter;
					if(xcoord==x && temp<=y && ycoord>=y)
					{
						printf("YES\n");
						flag=1;
						break;
					}
				}
				else{
					int temp=ycoord;
					ycoord-=counter;
					if(xcoord==x && temp>=y && ycoord<=y)
					{
						printf("YES\n");
						flag=1;
						break;
					}
				}
				counter++;
				inc =true;	
			}
			if(counter-oldcount == 2){
				
				direction = ~direction;
				oldcount=counter;
			}
		}
		if(flag==0)
			printf("NO\n");*/
	}
}