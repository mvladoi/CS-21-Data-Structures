#ifndef UNIONFIND_H
#define UNIONFIND_H


class UnionFind
{
    public:
        UnionFind(int n);
        ~UnionFind();
        int find_(int x);
        void union_(int x, int y);
        int getNumberOfSets(){return numOfSets;}
        bool sameComponent(int x, int y);

    private:
       int* parent;
       int* rank_;
       void makeSet(int x);
       void link(int x, int y);
       int numOfSets;
       int n;

};

#endif // UNIONFIND_H
