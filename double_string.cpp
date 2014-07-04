#include <cstdio>
#define gc getchar
using namespace std;
inline void inp(long int &x )//fast input function
{
 
	register long int c=gc();
	x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
	long int num;inp(num);
	for(long int i=0;i<num;i++)
	{
		long int doub_num;inp(doub_num);
		if(doub_num%2 == 0)
			printf("%ld\n", doub_num);
		else
			printf("%ld\n",doub_num-1 );
	}
}