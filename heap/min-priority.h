#ifndef MIN_PRIORITY_H
#define MIN_PRIORITY_H
#include "heap.cpp"

class min_priority
{
    public:
        heap *ob;
        min_priority(Node **,int);
        Node* extract_min();
        void decrease_key(int,int);
    protected:
    private:
};

#endif // MIN-PRIORITY_H
