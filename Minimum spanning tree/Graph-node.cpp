#include "Graph-node.h"

Graph_node::Graph_node(int k)
{
    key=k;
}
Graph_edge::Graph_edge(int st,int fi,int w)
{
    start_node=st;
    end_node=fi;
    weight=w;
}
