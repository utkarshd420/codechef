#include <cstdio>
#include <cmath>
#define gc getchar
using namespace std;
inline void inp(int &x )//fast input function
{
 
register long int c=gc();
x = 0;
for(;(c<48 || c>57);c = gc());
for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main()
{
	int num;inp(num);
	for(int k=0;k<num;k++)
	{
		register int game_num;
		inp(game_num);
		if(game_num % 2 == 0)
			printf("ALICE\n");
		else
			printf("BOB\n");
	}

}