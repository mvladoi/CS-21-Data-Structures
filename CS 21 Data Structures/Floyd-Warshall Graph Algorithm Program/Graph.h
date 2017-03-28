#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <limits>
#include <string>
using namespace std;

class Graph
{
public:
    Graph();
    ~Graph();
    void initializeGraph(int s);
    int findSizeMatrix();
    void readInput(string a);
    void printParentMatrix();
    void printDistanceMatrix();
    void warshallShortestPath();


private:
    int nrDigits();
    void printLine();
    int arrSize;
    int nrOfDigits;
    int** matrix;
    int**  shPath;
    vector <int> sourceNode;
    vector<int> destinationNode;
    vector<int> weight;
    int INF;

};

#endif // GRAPH_H
