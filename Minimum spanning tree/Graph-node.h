#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H


class Graph_node
{
    public:
        int key;
        Graph_node(int);

    protected:
    private:
};
class Graph_edge
{
    public:
        int start_node;
        int end_node;
        int weight;
        Graph_edge(int,int,int);

    protected:
    private:
};
#endif // GRAPH-NODE_H
