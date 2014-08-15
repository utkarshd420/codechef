#ifndef DIJKSTRA_H
#define DIJKSTRA_H


class dijkstra
{
    public:
        int n;
        dijkstra(int);
        void relax(int,int,int **);
        int *parent;
        int *dist;
        void print_path(int,int);
    protected:
    private:
};

#endif // DIJKSTRA_H
