#include <cstdio>
#include <cstring>
using namespace std;
void swap(char* a1,char *a2)
{
	char temp = *a1;
	*a1 = *a2;
	*a2 = temp;
}
void permute(char *str,int start,int end)
{
	int i;
	if(start==end)
		printf("%s\n",str);
	else
	{
	for(i=start;i<=end;i++)
	{
		swap(str+start,str+i);
		permute(str,start+1,end);
		swap(str+start,str+i);
	}
}
}
int main()
{
	char str[] = "abcdef";
	permute(str,0,5);
}	