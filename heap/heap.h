#ifndef HEAP_H
#define HEAP_H

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
    protected:
    private:
};

#endif // HEAP_H
