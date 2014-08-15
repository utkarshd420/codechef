#include <cstdio>
#define MAX 256
#include <cstring>
bool compare(char arr1[],char arr2[])
{
	for(int i=0;i<MAX;i++)
	{
		if(arr1[i] != arr2[i])
			return false;
	}

	return true;
}

void find_pat(char *text,char *pat)
{
	int M = strlen(pat);int N = strlen(text);
	char cpat[MAX]={0};
	char ctxt[MAX]={0};
	for(int i=0;i<M;i++)
	{
		cpat[pat[i]]++;
		ctxt[text[i]]++;
	}
	for(int i=M;i<N;i++)
	{
		if(compare(cpat,ctxt))
			printf("String found at %d\n", i-M);
		ctxt[text[i-M]]--;
		ctxt[text[i]]++;
	}
	if(compare(cpat,ctxt))
		printf("String found at %d\n",N-M );
}
int main()
{
	char text[] = "BACDGABCDA";
	char pat[] = "ABCD";
	find_pat(text,pat);
	return 0;
}