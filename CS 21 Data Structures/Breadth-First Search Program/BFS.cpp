


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <queue>
#include "BFS.h"



BFS::BFS()
{
    maze = 0;
    flag = 0;
    previous = 0;
}



BFS::BFS(std::vector<int>& data)
{


    noNodes = data.size();
    n = (int)sqrt(noNodes);

    maze = new std::vector<int>;
    for(int i = 0; i < noNodes; i++)
    {
        maze->push_back(data.at(i));
    }
    flag = new bool [noNodes];
    for(int i = 0; i < noNodes; i++)
    {
        flag[i] = false;

    }

    previous = new int [noNodes];
    for(int i = 0; i < noNodes; i++)
    {
        previous[i] = -1;

    }

    adjRooms(32);

}



BFS::~BFS()
{
    delete maze;
    delete [] flag;
    delete [] previous;
}


std::vector<int> BFS::adjRooms(int pos)
{
    bool top = true;
    bool bottom = true;
    bool right = true;
    bool left = true;


//if(maze->at(pos) == 0)
    //top = bottom = right = left = false;

    if(1 == (maze->at(pos) >> 3 & 1))top = false;
    if(1 == (maze->at(pos) >> 1 & 1))bottom = false;
    if(1 == (maze->at(pos) >> 0 & 1))right = false;
    if(1 == (maze->at(pos) >> 2 & 1))left = false;


    //std::cout << top << " " << bottom << " " << left << " " << right << " ";
    std::vector<int> v;

    if(top)
        v.push_back(pos - n);
    if(bottom)
        v.push_back(pos + n);
    if(right && pos != noNodes -1)
        v.push_back(pos+1);
    if(left && pos != 0)
        v.push_back(pos-1);


    //for(int i = 0; i < v.size(); i++)
    //{
    //    std::cout << v.at(i) << std::endl;
   // }
   return v;
}




void BFS::shortestPath(int start)
{

    std::queue<int> Q;
    flag[start] = true;
    Q.push(start);

    while(!Q.empty())
    {

        int v = Q.front();
        //std::cout << v  <<  " v "<< std::endl;
        Q.pop();

        std::vector <int> validRooms = adjRooms(v);
        int size = validRooms.size();
        for(int i = 0; i < size; i++)
        {
            int w = validRooms.at(i);
            //std::cout << w << " W " << std::endl;
            if(flag[w] == false)
            {
                flag[w] = true;
                //std::cout << "flag[w] " << flag[w] << std::endl;
                previous[w] = v;
                //std::cout << "prev[w] " << previous[w] << std::endl;

                Q.push(w);
            }

        }

    }

    /**for(int i = 0; i < noNodes; i++){
        std::cout << flag[i] << " ";

    }
      std::cout << std::endl;

    for(int i = 0; i < noNodes ; i++){


        std::cout<< previous[i] << " ";

    }
      std::cout << std::endl;
*/
}



void BFS::printPath(int destination){

if (previous[destination] !=-1){
   printPath(previous[destination]);
    std::cout << "(" << destination / n << ", " << destination % n << ")\n";
}
else
    std::cout << "(0, 0)\n";
}

