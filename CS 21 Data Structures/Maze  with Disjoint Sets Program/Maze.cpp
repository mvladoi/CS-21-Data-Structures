#include "Maze.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

Maze::Maze(int sizeOfMaze)
{
    n = sizeOfMaze;
    mazeArray = new int[n*n];
    shuffledArary = new int[n*n];
    for(int i = 0; i <= (n*n); i++)
    {
        mazeArray[i] = 15;
        shuffledArary[i] = i;
    }
    randomShuffle();
    mazeArray[1] = 11;
    mazeArray[n*n] = 14;
    uf = new UnionFind(n);


}





Maze::~Maze()
{
    if(mazeArray != 0)
    {
        //delete []mazeArray;
    }
    if(shuffledArary != 0)
    {
        //delete []shuffledArary;
    }
    if(uf != 0)
    {
        //delete uf;
    }
}


void Maze::randomShuffle()
{

    for(int i = 1; i < (n*n - 1); i++)
    {
        int index = i + (rand() % (n*n-i));
        int temp = shuffledArary[i];
        shuffledArary[i] = shuffledArary[index];
        shuffledArary[index] = temp;

    }
}



bool Maze::topWall(int value)
{
    if(value-n <= 0 || uf->sameComponent(value, value-n)==true)
        return false;
    return true;

}

bool Maze::bottomWall(int value)
{
    if(value+n > (n*n) || uf->sameComponent(value, value+n)==true)
        return false;
    return true;
}

bool Maze::rightWall(int value)
{
    if(value%n == 0 || uf->sameComponent(value, value+1)==true)
        return false;
    return true;
}

bool Maze::leftWall(int value)
{
    if(value%n == 1 || uf->sameComponent(value, value-1)== true)
        return false;
    return true;

}



void Maze::print()
{


    int number = 9;
    char letter;
    for(int i = 1; i <=(n*n); i++)
    {
        if(mazeArray[i] > number)
        {
            letter = mazeArray[i] + 88;
            std::cout << letter;
        }

        else
        {
            letter = mazeArray[i] + 48;
            std::cout << letter;
        }
        if(i%n==0)
            std::cout << "\n";
    }

}

void Maze::breakWall(int wall, int value)
{
    if(wall == left)
    {
        mazeArray[value] -= 4;
        mazeArray[value-1] -= 1;
        uf->union_(value, value-1);
    }
    if(wall == right)
    {
        mazeArray[value] -= 1;
        mazeArray[value+1] -= 4;
        uf->union_(value, value+1);
    }

    if(wall == top)
    {
        mazeArray[value] -= 8;
        mazeArray[value-n] -= 2;
        uf->union_(value, value-n);
    }
    if(wall == bottom)
    {
        mazeArray[value] -= 2;
        mazeArray[value+n] -= 8;
        uf->union_(value, value+n);
    }



}

int Maze::checkAdjacentWalls(int value)
{
    std::vector <int> walls;
    bool l = leftWall(value);
    bool r = rightWall(value);
    bool t = topWall(value);
    bool b = bottomWall(value);
    if(l == true)
        walls.push_back(4);
    if(r == true)
        walls.push_back(1);
    if(t == true)
        walls.push_back(8);
    if(b == true)
        walls.push_back(2);

    int size = walls.size();
    if(size == 0)
        return -1;
    std::random_shuffle(walls.begin(), walls.end());
    return walls.at(0);


}


void Maze::mazeGenerator()
{

    while(uf->getNumberOfSets() > 1)
    {

        for(int i = 1; i <= n*n; i++)
        {
            int wall = checkAdjacentWalls(shuffledArary[i]);

            if(wall != -1)
            {
                breakWall(wall, shuffledArary[i]);

            }
        }
    }

}



