


#include "Maze.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

int main(int argc, char* argv[])
{
    srand(time(0));


   // if(argc != 2){
      //  std::cout << "Please enter the size of maze\nMinimum size is 3." << argv[1] << "\n\n";
       // exit(-1);
   // }

    int n = 40;//atoi(argv[1]);
    if(n < 3){
        std::cout << "Size should be minimum 3.\n";
        exit(1);
    }
    Maze UFMaze (n);
    UFMaze.mazeGenerator();
    UFMaze.print();

    return 0;
}
