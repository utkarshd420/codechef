#include <cstdio>
#include <list>
#include <queue>
using namespace std;
class Graph{
public:
	list<int> *adj;
	int V;
	Graph(int v)
	{
		V = v;
		adj=new list<int>[v];
	}
	void add_edge(int v,int w)
	{
		adj[v].push_back(w);
	}
	void bfs(int s)
	{
		list<int> temp;
		bool *visited = new bool[V];
		for(int i=0;i<V;i++)
			visited[i]=false;
		temp.push_back(s);
		visited[s]=true;
		while(!temp.empty())
		{
			int u=temp.front();
			temp.pop_front();
			list<int>::iterator i;
			for(i=adj[u].begin();i!=adj[u].end();i++)
				if(visited[*i]==false)
				{
					temp.push_back(*i);
					visited[*i]=true;
				}
			printf("%d, ",u);
		}
	}
};

int main()
{
	Graph g(4);
	g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
    printf("Following is the bfs\n");
    g.bfs(0);
    return 0;
}