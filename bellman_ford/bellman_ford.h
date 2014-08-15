#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H


class bellman_ford
{
    public:
        int n;
        bellman_ford(int);
        void relax(int,int,int **);
        int *parent;
        int *dist;
        void print_path(int,int);
    protected:
    private:
};

#endif // BELLMAN_FORD_H
