#ifndef BFS_H
#define BFS_H

#include <vector>

class BFS
{
    public:
        BFS();
        BFS(std::vector<int>& data);
        ~BFS();
        void shortestPath(int start);
        void printPath(int vertex);

    private:
        std::vector <int>* maze;
        std::vector<int> adjRooms(int pos);
        bool* flag;
        int* previous;
        int noNodes;
        int n;
};

#endif // BFS_H
