#include "dijkstra.h"
#include <iostream>
#include <cstdio>
#include <list>
#include "../heap/min-priority.cpp"
dijkstra::dijkstra(int m)
{
    n=m;
    parent=new int[n];
    dist=new int[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=-1;
        dist[i]=9999;
    }
}
void dijkstra::relax(int u,int v, int **w)
{
    if(dist[v]>dist[u]+w[u][v])
    {
        dist[v]=dist[u]+w[u][v];
        parent[v]=u;
    }
    /*cout<<"distance is "<<endl;
    for(int i=0;i<n;i++)
        cout<<dist[i]<<" ";
    cout<<endl;
    cout<<"parent is "<<endl;
    for(int i=0;i<n;i++)
        cout<<parent[i]<<" ";
    cout<<endl;*/
}
void dijkstra::print_path(int s , int d)
{
    if(s==d)
    {
        cout<<s;
        return;
    }
    else if(parent[d]==-1)
    {
        cout<<"No path exists\n";
        return;
    }
    else
    {
        print_path(s,parent[d]);
        cout<<"->"<<d;
    }
}
int main()
{
    FILE *fin=fopen("input.txt","r");
    int n;
    fscanf(fin,"%d",&n);
    int **w=new int*[n];
    for(int i=0;i<n;i++)
        w[i]=new int[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            fscanf(fin,"%d",&w[i][j]);
    dijkstra *dj=new dijkstra(n);
    Node **vertex=new Node*[n];
    for(int i=0;i<n;i++)
    {
        vertex[i]=new Node();
        vertex[i]->id=i;
        vertex[i]->key=9999;
    }
    cout<<"Input source ";
    int s;
    cin>>s;
    vertex[s]->key=0;
    dj->dist[s]=0;
    min_priority *Q=new min_priority(vertex,n);
    list<int> SeT;
    while(Q->ob->heap_size!=0)
    {
       // Q->ob->disp();
        Node *u=Q->extract_min();
        SeT.push_back(u->id);
        for(int i=0;i<n;i++)
        {
            if(w[u->id][i]!=0)
            {
                dj->relax(u->id,i,w);
                for(int p=0;p < Q->ob->heap_size;p++)
                    if(Q->ob->heaps[p]->id == i)
                    {
                        Q->decrease_key(p,dj->dist[i]);
                        break;
                    }
            }
        }
    }
    int dest;
    cout<<"Input the destination source ";
    cin>>dest;
    dj->print_path(s,dest);

    cout<<endl<<"Total weight of path is "<<dj->dist[dest]<<endl;
}
