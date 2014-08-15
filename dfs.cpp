#include <cstdio>
#include <list>
#include <queue>
using namespace std;
class Graph{
public:
	list<int> *adj;
	int V;
	int *color;
	int *start_time;
	int *finish_time;
	int *parent;
	int Time;
	Graph(int v)
	{
		V = v;
		adj=new list<int>[v];
		color=new int[V];
		start_time = new int[V];
		finish_time = new int[V];
		parent = new int[V];
		Time=0;
	}
	void add_edge(int v,int w)
	{
		adj[v].push_back(w);
	}

		void dfs_visit(int u)
		{
			color[u]=1;
			printf("%d, ",u);
			Time++;
			start_time[u]=Time;
			list<int>::iterator i;
			for(i=adj[u].begin();i!=adj[u].end();i++)
			{
				if(color[*i]==0)
				{
					parent[*i]=u;
					dfs_visit(*i);
				}
			}
			color[u]=2;
			Time++;
			finish_time[u]= Time;
		}
		void dfs()
		{
			for(int i=0;i<V;i++)
			{
				color[i]=0;						//0->white,1->grey,2->black
				parent[i]=-1;
				start_time[i]=0;
				finish_time[i]=0;
			}
			for(int i=0;i<V;i++)
			{
				if(color[i]==0)
					dfs_visit(i);
			}
		}
};

int main()
{
	Graph g(4);
	g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
    printf("Following is the dfs\n");
    g.dfs();
    return 0;
}
