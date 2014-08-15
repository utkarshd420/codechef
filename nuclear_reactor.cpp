#include <cstdio>
using namespace std;
int main()
{
	int A,N,K;
	scanf("%d",&A);
	scanf("%d",&N);
	scanf("%d",&K);
	N++;
	while(A!=0 && K>0)
	{
		int sub = A%N;
		printf("%d ",sub);
		A= A-sub;
		A=A/N;
		K--;
	}
	while(K-->0)
		printf("0 ");
	printf("\n");
}