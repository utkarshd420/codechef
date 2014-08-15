#include <cstdio>
#include <vector>
#include <list>
using namespace std;

/**
MIN PRIORITY QUEUE
*/
typedef struct NodeA
{
    int id;
    int key;
}Node;

class heap
{
    public:
        Node **heaps;
        heap(Node **,int);
        void min_heapify(int);
        void build_min_heap();
        int heap_size;
        int length;
        void disp();
};

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
class min_priority
{
    public:
        heap *ob;
        min_priority(Node **,int);
        Node* extract_min();
        void decrease_key(int,int);
};
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
}



/** MIN PRIORITY ENDS HERE */


typedef struct NodeA{
	int weight;
	int ind;
}graphNode;
int main()
{
	int m,n;
	scanf("%d",&n);
	scanf("%d",&m);
	vector<vector<Node>> arr;
	for(int i=0;i<=n;i++)
		arr.push_back(vector<Node>());
	for(int i=0;i<m;i++)
	{
		int start,end;
		scanf("%d",&start);
		scanf("%d",&end);
		graphNode * temp=new graphNode();
		temp->weight=0;
		temp->ind=end;
		arr[start].push(temp);
		graphNode * temp1=new graphNode();
		temp1->weight=1;
		temp1->ind=start;
		arr[end].push(temp1);
	}
}