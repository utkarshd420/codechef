#include "shortest_path.h"
#include <iostream>
#include <queue>
using namespace std;
void print_path(int *parent,int s ,int d)
{
    if(s==d)
       cout<<s;
    else if(parent[d]==-1)
        cout<<"No path exists"<<endl;
    else
    {
        print_path(parent,s ,parent[d]);
        cout<<"-->"<<d;
    }
}
void BFS(int **m, int n,int s,int d)
{
    char *color=new char[n];
    int *parent=new int[n];
    int *dist=new int[n];
    queue<int> edges;
    for(int i=0;i<n;i++)
    {
        if(i!=s)
        {
            color[i]='w';
            parent[i]=-1;
            dist[i]=0;
        }
    }
    color[s]='g';
    parent[s]=-1;
    dist[s]=0;
    edges.push(s);
    while(edges.size()!=0)
    {
        int u=edges.front();
        edges.pop();
        for(int i=0;i<n;i++)
        {
            if(m[u][i]!=0)
            {
                if(color[i]=='w')
                {
                    color[i]='g';
                    dist[i]=dist[u]+1;
                    parent[i]=u;
                    edges.push(i);
                }
            }
        }
        color[u]='b';
    }
    cout<<"Distance from "<<s<<" to "<<d<<" is "<<dist[d]<<" path is "<<endl;
    print_path(parent,s,d);
}
int main()
{
    cout<<"Input the number of nodes ";
    int n;
    cin>>n;
    int **m=new int*[n];
    for(int i=0;i<n;i++)
        m[i]=new int[n];
    cout<<"Input the adjacency matrix "<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>m[i][j];
    int source;int dest;
    cout<<"Input the source node ";
    cin>>source;
    cout<<"Input the destination node ";
    cin>>dest;
    BFS(m,n,source,dest);
}
