#include <cstdio>
#include <cmath>
using namespace std;
long long int set_face_left(int face,int curr_x,int curr_y,int x, int y)
{
	if(face == 1)
	{
		curr_y++;
		long long int dist = (curr_x -x )*(curr_x -x ) + (curr_y-y)*(curr_y-y);
		return dist;
	}
	else if(face ==0)
	{
		curr_x--;
		long long int dist = (curr_x -x )*(curr_x -x ) + (curr_y-y)*(curr_y-y);
		return dist;	
	}
	else if(face==2)
	{
		curr_x++;
		long long int dist = (curr_x -x )*(curr_x -x ) + (curr_y-y)*(curr_y-y);
		return dist;		
	}
	else if(face==3)
	{
		curr_y--;
		long long int dist = (curr_x -x )*(curr_x -x ) + (curr_y-y)*(curr_y-y);
		return dist;			
	}
}
long long int set_face_right(int face,int curr_x,int curr_y,int x, int y)
{
	if(face == 1)
	{
		curr_y--;
		long long int dist = (curr_x -x )*(curr_x -x ) + (curr_y-y)*(curr_y-y);
		return dist;
	}
	else if(face ==0)
	{
		curr_x++;
		long long int dist = (curr_x -x )*(curr_x -x ) + (curr_y-y)*(curr_y-y);
		return dist;	
	}
	else if(face==2)
	{
		curr_x--;
		long long int dist = (curr_x -x )*(curr_x -x ) + (curr_y-y)*(curr_y-y);
		return dist;		
	}
	else if(face==3)
	{
		curr_y++;
		long long int dist = (curr_x -x )*(curr_x -x ) + (curr_y-y)*(curr_y-y);
		return dist;			
	}
}
void take_left_step(int *face,int *curr_x,int *curr_y)
{
	if(*face ==1)
	{
		(*curr_y)++;
		(*face) = 0;
	}
	else if(*face ==2)
	{
		(*curr_x)++;
		(*face) = 0;	
	}
	else if(*face ==0)
	{
		(*curr_x)--;
		(*face) = 3;		
	}
	else if(*face ==3)
	{
		(*curr_y)--;
		(*face) = 2;		
	}
}
void take_right_step(int *face,int *curr_x,int *curr_y)
{
	if(*face ==1)
	{
		(*curr_y)--;
		(*face) = 2;
	}
	else if(*face ==2)
	{
		(*curr_x)--;
		(*face) = 3;	
	}
	else if(*face ==0)
	{
		(*curr_x)++;
		(*face) = 1;		
	}
	else if(*face ==3)
	{
		(*curr_y)++;
		(*face) = 0;		
	}
}
int main()
{
	int num;scanf("%d",&num);
	while(num--)
	{
		int x,y;
		scanf("%d",&x);
		scanf("%d",&y);
		int face =1;
		int curr_x = 0,curr_y = 0;
		long long int res_steps = 0;
		while(curr_x!=x && curr_y!=y)
		{
			long long int left_step = set_face_left(face,curr_x,curr_y,x,y);
			long long int right_step = set_face_right(face,curr_x,curr_y,x,y);
			printf("Left step distance is %lld\n",left_step);
			printf("Right step distance is %lld\n",right_step);
			if(left_step <= right_step)
				take_left_step(&face,&curr_x,&curr_y);
			else 
				take_right_step(&face,&curr_x,&curr_y);
			res_steps++;

			printf("%d %d %d\n", curr_x,curr_y,face);
		}
		printf("%lld\n",res_steps+1);
	}
}