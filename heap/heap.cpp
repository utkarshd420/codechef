#include "heap.h"
#include <iostream>
using namespace std;
heap::heap(Node **arr,int len)
{
    heaps=arr;
    length=len;
    heap_size=length;
}
void heap::min_heapify(int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int smallest=i;
    if(l<heap_size && heaps[l]->key <= heaps[i]->key)
        smallest=l;
    else
        smallest=i;
    if(r<heap_size && heaps[r]->key < heaps[smallest]->key)
        smallest=r;
    if(smallest!=i)
    {
        Node* temp=heaps[i];
        heaps[i]=heaps[smallest];
        heaps[smallest]=temp;
        min_heapify(smallest);
    }
}
void heap::build_min_heap()
{
    for(int i=length/2;i>=0;i--)
    {
        min_heapify(i);
    }
}
void heap::disp()
{
    cout<<"heap is ";
    for(int i=0;i<heap_size;i++)
        cout<<heaps[i]->id<<":"<<heaps[i]->key<<" ";
    cout<<endl;
}

