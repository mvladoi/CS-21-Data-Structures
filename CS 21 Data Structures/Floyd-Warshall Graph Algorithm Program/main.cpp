
#include "Graph.h"
#include <iostream>
using namespace std;

int main()
{



    Graph Marian;
    string a;
    int nrLines = 0;
    while(getline(cin , a)){
    Marian.readInput(a);
    nrLines ++;
    }
if(nrLines > 0){
    int size = Marian.findSizeMatrix();
    Marian.initializeGraph(size);
    Marian.warshallShortestPath();
    Marian.printParentMatrix();
    Marian.printDistanceMatrix();

}












}
