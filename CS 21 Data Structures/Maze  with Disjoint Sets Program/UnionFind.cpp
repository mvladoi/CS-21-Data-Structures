
#include <iostream>
#include "UnionFind.h"




UnionFind::UnionFind(int x)
{
    n = x;
    numOfSets = n*n;
    parent = new int[numOfSets];
    rank_ = new int[numOfSets];
    for(int i = 0; i <= numOfSets; i++)
    {
        makeSet(i);
    }
}






UnionFind::~UnionFind()
{
    if(parent != 0)
    {
        delete [] parent;
    }
    if(rank_ != 0)
    {
        delete [] rank_;
    }
}








void UnionFind::makeSet(int x)
{
    parent[x] = x;
    rank_[x] = 0;
}





void UnionFind::union_(int x, int y)
{
    int first = find_(x);
    int second = find_(y);
    if(first != -1 && second != -1)
    {
        link(first, second);
    }
    else
    {
        std::cerr << "Values are not in the range [1-" << n*n << "]" << std::endl;
    }
}




int UnionFind::find_(int x)
{

    if(x > 0 && x <= n*n)
    {
        if(x != parent[x])
        {
            parent[x] = find_(parent[x]);

        }
        return parent[x];
    }
    else return -1;
}



void UnionFind::link(int x, int y)
{

    if(x == y)
    {
        return;
    }
    numOfSets--;

    if(rank_[x] > rank_[y])
    {
        parent[y] = x;
    }
    else
    {
        parent[x] = y;
        if(rank_[x] == rank_[y])
        {
            rank_[y]++;
        }
    }


}



bool UnionFind::sameComponent(int x, int y){
if(find_(x) != -1 && find_(y) != -1 && find_(x) == find_(y)){
    return true;
}
return false;

}

