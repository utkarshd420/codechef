#include <cstdio>
#include <string>
using namespace std;
void substring(char s1[],char s2[],int m,int n)
{
	for(int i=0;i<=(n-m);i++)
	{
		int flag=0;
		for(int j=i;j<m+i;j++)
			if(s1[j]!=s2[j-i])
			{
				flag=1;
				break;
			}
		if(flag==0)
		{
			printf("String %s is at %d\n",s2,i);
		}
	}
}
int main()
{
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	char s1[n];char s2[m];
	printf("Please Input string 1 \n");
	scanf("%s",s1);
	printf("Please Input string 2 \n");
	scanf("%s",s2);
	substring(s1,s2,m,n);
}