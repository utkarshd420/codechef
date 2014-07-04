#include <cstdio>
using namespace std;
int main()
{
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	int arr[]={0,1,2,3,4,5,6,7,8,9};
	int res = a-b;
	float dig = res%10;
	dig--;
	if (dig<=0)
		dig = 9+dig;
	//printf("%d dig is \n",int(dig));
	if(res>9)
		printf("%d%d\n",res/10,arr[int(dig)]);
	else
		printf("%d\n",arr[int(dig)]);
}