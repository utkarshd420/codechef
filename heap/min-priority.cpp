#include "min-priority.h"
#include <iostream>
using namespace std;
min_priority::min_priority(Node **A,int length)
{
    ob=new heap(A,length);
    ob->build_min_heap();
}
Node* min_priority::extract_min()
{
    if(ob->heap_size<1)
        return NULL;
    Node * mini= ob->heaps[0];
    ob->heaps[0]=ob->heaps[ob->heap_size-1];
    ob->heap_size--;
    //cout<<"hs is "<<ob->heap_size<<endl;
    ob->min_heapify(0);
    return mini;
}
void min_priority::decrease_key(int i,int key)
{
    if( key <= ob->heaps[i]->key)
    {
        ob->heaps[i]->key=key;
        while(i>=0 && ob->heaps[i]->key < ob->heaps[i/2]->key)
        {
            Node *temp=ob->heaps[i/2];
            ob->heaps[i/2]=ob->heaps[i];
            ob->heaps[i]=temp;
            i=i/2;
        }
    }
}
