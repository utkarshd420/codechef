#include "topo_sort.h"
#include <iostream>
#include <list>
#include <cstdio>
using namespace std;
list<int> topo;
void DFS(int v,int **m,int *parent,int *start,int *finish,int n,char* color,int *time)
{
        for(int j=0;j<n;j++)
        {
            if(m[v][j]!=0)
            {
                if(color[j]=='w')
                {
                    start[j]=(*time)++;
                    color[j]='g';
                    parent[j]=v;
                    DFS(j,m,parent,start,finish,n,color,time);
                }
            }
        }
        color[v]='b';
        finish[v]=(*time)++;
        topo.push_front(v);
}
int main()
{
    int n;static int time=1;
    FILE *fin=fopen("input.txt","r");
    //cout<<"Input the number of elements ";
   // cin>>n;
    fscanf(fin,"%d",&n);
    int **m=new int*[n];
    for(int i=0;i<n;i++)
        m[i]=new int[n];
    //cout<<"Input the adjacency matrix\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            fscanf(fin,"%d",&m[i][j]);
    char *color=new char[n];
    int *parent=new int[n];
    int *start=new int[n];
    int *finish=new int[n];
    for(int i=0;i<n;i++)
    {
        color[i]='w';
        parent[i]=-1;
        start[i]=0;
        finish[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(color[i]=='w')
        {
            color[i]='g';
            start[i]=time;
            DFS(i,m,parent,start,finish,n,color,&time);
        }
    }
    cout<<"topo sort is " ;
    for(list<int>::iterator it=topo.begin();it!=topo.end();it++)
        cout<<(*it)<<"->";
    cout<<endl;
}
