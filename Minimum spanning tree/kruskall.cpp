#include <iostream>
#include <list>
#include "kruskall.h"
#include "Graph-node.cpp"
using namespace std;
list<Graph_edge *> edges;
list<Graph_edge *> mst;
void add_edge(Graph_edge *e)
{
    for(list <Graph_edge *>::iterator it=edges.begin();it!=edges.end();it++)
    {
        if((*it)->weight >= e->weight)
        {
            edges.insert(it,e);
            return;
        }
    }
    edges.push_back(e);
}
bool find_set(int **un_find,int u, int v,int n)
{
    cout<<"u & v are "<<u<<" "<<v<<endl;
    for(int i=0;i<n;i++)
        cout<<un_find[i][0]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<un_find[i][1]<<" ";
     cout<<endl;
    if(u==v)
        return false;
    int k=0;
    while(un_find[u][1]!=-1)
    {
        u=un_find[u][1];
    }
    while(un_find[v][1]!=-1)
    {
        v=un_find[v][1];
    }
    return u!=v;
}
void Union(int **un_find,int u, int v)
{
   while(un_find[u][1]!=-1)
    {
        u=un_find[u][1];
    }
     while(un_find[v][1]!=-1)
    {
        v=un_find[v][1];
    }
    un_find[u][1]=v;
}
int main()
{
        int n;
        cout<<"Input the number of nodes you want ";
        cin>>n;
        cout<<"Please input the adjacency matrix signifying the weights \n";
        int **m=new int*[n];
        for(int i=0;i<n;i++)
            m[i]=new int[n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>m[i][j];

        int **union_find=new int*[n];
        for(int i=0;i<n;i++)
            union_find[i]=new int[2];
        for(int i=0;i<n;i++)
        {
            union_find[i][0]=i;
            union_find[i][1]=-1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j<=i && m[i][j]!=0)
                {
                    Graph_edge* e=new Graph_edge(i,j,m[i][j]);
                    add_edge(e);
                }
            }
        }
          cout<<"edges is "<<edges.size()<<endl;
        for(list <Graph_edge *>::iterator it=edges.begin();it!=edges.end();it++)
        {
            if(find_set(union_find,(*it)->start_node,(*it)->end_node, n))
            {
                mst.push_back(*it);
                Union(union_find,(*it)->start_node,(*it)->end_node);
            }
        }
        cout<<"MST is \n";
        for(list <Graph_edge *>::iterator it=mst.begin();it!=mst.end();it++)
        {
            cout<<"Edge is "<<(*it)->start_node<<" "<<(*it)->end_node<<" with weight "<<(*it)->weight<<endl;
        }
}
