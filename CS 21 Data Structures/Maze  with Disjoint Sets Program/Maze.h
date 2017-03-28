#ifndef MAZE_H
#define MAZE_H
#include "UnionFind.h"

class Maze
{
    public:
        Maze(int sizeOfMaze);
        ~Maze();
        void print();
        void mazeGenerator();


    private:
        static const int left = 4;
        static const int right = 1;
        static const int top = 8;
        static const int bottom = 2;
        int n;
        int* mazeArray;
        int* shuffledArary;
        UnionFind* uf;
        int checkAdjacentWalls(int value);
        void breakWall(int value1, int value2);
        bool topWall(int value);
        bool bottomWall(int value);
        bool leftWall(int value);
        bool rightWall(int value);
        void randomShuffle();

};

#endif // MAZE_H
