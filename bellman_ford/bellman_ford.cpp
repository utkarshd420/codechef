#include "bellman_ford.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
bellman_ford::bellman_ford(int m)
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
void bellman_ford::relax(int u,int v, int **w)
{
    if(dist[v]>dist[u]+w[u][v])
    {
        dist[v]=dist[u]+w[u][v];
        parent[v]=u;
    }
}
void bellman_ford::print_path(int s , int d)
{
    if(s==d)
    {
        cout<<s<<"->";
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
    int n;
    FILE *fin=fopen("input.txt","r");
    fscanf(fin,"%d",&n);
    bellman_ford *bf=new bellman_ford(n);
    int **w=new int*[n];
    for(int i=0;i<n;i++)
        w[i]=new int[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            //cin>>w[i][j];
            fscanf(fin,"%d",&w[i][j]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            //cin>>w[i][j];
            cout<<w[i][j]<<" ";
        cout<<endl;
    }
    int s;
    cout<<"Input the source ";
    cin>>s;
    bf->parent[s]=-1;
    bf->dist[s]=0;
    for(int k=0;k<n-1;k++)
    {
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(w[i][j]!=0)
                bf->relax(i,j,w);
        }
    }
    }
   for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(w[i][j]!=0)
            {
            if(bf->dist[j]>bf->dist[i]+w[i][j])
            {
                cout<<"negative cycle exists exiting";
                exit(-1);
            }
            }
        }
    }
    int d;
    cout<<"input the ele to which u need short path ";
    cin>>d;
    cout<<"shortest path is \n";
    bf->print_path(s,d);
    cout<<endl<<"Total weight is "<<bf->dist[d]<<endl;
}
