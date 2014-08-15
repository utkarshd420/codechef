#include "prim.h"
#include "../heap/min-priority.cpp"
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    FILE *fin=fopen("input.txt","r");
    //cout<<"Please input the number of nodes ";
    fscanf(fin,"%d",&n);
    int **m=new int*[n];
    for(int i =0;i<n;i++)
        m[i]=new int[n];
   // cout<<"Please input the adjacency matrix \n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            fscanf(fin,"%d",&m[i][j]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<m[i][j]<<" ";
            cout<<endl;
    }
    Node **vertex = new Node*[n];
    for(int i=0;i<n;i++)
        vertex[i]=new Node();
    int *parent= new int[n];
    for(int i=0;i<n;i++)
    {
        vertex[i]->id=i;
        vertex[i]->key=9999;
        parent[i]=-1;
    }
   // cout<<vertex[0]->id<<" "<<vertex[0]->key<<endl;
    cout<<"input the root node ";
    int r;
    cin>>r;
    vertex[r]->key=0;
    min_priority *Q=new min_priority(vertex,n);
    Q->ob->disp();
    while(Q->ob->heap_size!=0)
    {
        Node* u=Q->extract_min();
        for(int i=0;i<n;i++)
        {
            if(m[u->id][i]!=0)
            {
                for(int j=0;j<Q->ob->heap_size;j++)
                {
                    if(Q->ob->heaps[j]->id==i)
                    {
                        if(m[u->id][i] <= Q->ob->heaps[j]->key)
                        {
                            parent[i] = u->id;
                            Q->decrease_key(j,m[u->id][i]);
                           // Q->ob->heaps[j]->key=m[u->id][i];
                            //Q->ob->disp();
                        }
                    }
                }
            }
        }
        if(u->id!=r)
            cout<<"From node "<<parent[u->id]<<" "<<u->id<<" with weight "<<m[parent[u->id]][u->id]<<endl;
    }
}
