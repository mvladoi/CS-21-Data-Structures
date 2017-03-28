
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "BFS.h"

using namespace std;

vector<int> readInput(string fileNale);



int main()
{


    vector<int> data = readInput("test.txt");
  if(data.size() > 0){
        int start = 0;
        int destination = data.size()-1;
    BFS instance(data);
    instance.shortestPath(start);
    instance.printPath(destination);
  //}

}

}



vector<int> readInput(string file){


   std::ifstream fin;
    fin.open(file.c_str());
    if(fin.fail()){
        std::cerr << "Fail failed to open." << std::endl;
        exit(1);
    }



    std::string line;
    vector<int> maze;

    while (getline(fin, line)){
         int lSize = line.size();


            for(int i = 0; i < lSize; i++){
                int value = 0;
                char c = tolower(line.at(i));
                if(c >= 'a' && c <= 'f'){
                    value = c - 87;
                    maze.push_back(value);
                }

                else{
                        value = c - 48;
                    maze.push_back(value);

                }

            }

    }



fin.close();


return maze;

}
