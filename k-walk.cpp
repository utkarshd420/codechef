#include <iostream>
using namespace std;
int recursive_walk(int graph[][4],int u ,int v, int k,int V)
{
	if(k==0 && u==v) return 1;
	if(k==1 && graph[u][v]) return 1;
	int count =0;
	for(int i=0;i<V;i++)
	{
		if(graph[u][i] == 1)
			count+= recursive_walk(graph,i,v,k-1,V);
	}
	return count;
}
int main()
{
	int u=0,v=3,V=4,k=4;
	int graph[4][4]={{0, 1, 1, 1},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 0}};
	cout<<recursive_walk(graph,u,v,k,V)<<endl;
}