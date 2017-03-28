#include "Graph.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <iomanip>



Graph::Graph()
{
    matrix = 0;
    shPath = 0;
    INF = numeric_limits<int>::max();
}


void Graph::initializeGraph (int s)
{

    arrSize = s;
    matrix = new int *[arrSize];
    for(int i = 0; i < arrSize; i++)
    {
        matrix[i] = new int[arrSize];
    }


    for(int i = 0; i < arrSize; i++)
    {
        for(int j = 0; j < arrSize; j++)
        {
            matrix[i][j] = INF;
        }
    }

    int size = sourceNode.size();
    for(int i = 0; i < size; i++)
    {
        matrix[sourceNode.at(i)-1][destinationNode.at(i)-1] = weight.at(i);
    }



    shPath = new int*[arrSize];
    for(int i = 0; i < arrSize; i++)
    {
        shPath[i] = new int [arrSize];
    }



    for(int i = 0; i < arrSize; i++)
    {
        for(int j = 0; j < arrSize; j++)
        {
            shPath[i][j] = INF;
        }
    }
}



Graph::~Graph()
{
    if(matrix != 0)
    {
        for(int i = 0; i < arrSize; i++)
        {
            delete matrix[i];
        }
        delete []matrix;
    }


    if(shPath != 0)
    {
        for(int i = 0; i < arrSize; i++)
        {
            delete shPath[i];
        }
        delete []shPath;
    }
}



void Graph::readInput(string a)
{
    vector<string> integerValues;
    stringstream input(a);
    string newLine;
    while(getline(input, a))
    {
        unsigned int prev = 0;
        unsigned int pos ;
        while((pos = a.find_first_of(", ", prev))!= string::npos)
        {
            if(pos > prev)
                integerValues.push_back(a.substr(prev,pos-prev));
            prev = pos+1;
        }
        if(prev < a.length())
            integerValues.push_back(a.substr(prev, string::npos));
    }

    integerValues.erase(remove(integerValues.begin(), integerValues.end(), " "), integerValues.end());
    for(unsigned int i = 0; i < integerValues.size(); i++)

    int nodeS = atoi(integerValues.at(0).c_str());
    int nodeD = atoi(integerValues.at(1).c_str());
    int nodeW = atoi(integerValues.at(2).c_str());

    sourceNode.push_back(nodeS);
    destinationNode.push_back(nodeD);
    weight.push_back(nodeW);


}


int Graph::findSizeMatrix()
{

    int maxS = *max_element(sourceNode.begin(), sourceNode.end());
    int maxD = *max_element(destinationNode.begin(), destinationNode.end());
    if(maxD > maxS)
        return maxD;
    else
        return maxS;

}



int Graph::nrDigits()
{
    int temp = findSizeMatrix();
    int temp2 = *max_element(weight.begin(), weight.end());
    int max = 0;
    if(temp > temp2)
        max = temp;
    else
        max = temp2;

    int count = 0;
    int divisor = 1;
    while(max / divisor > 0)
    {
        count++;
        divisor *= 10;
    }

    return count;
}




void Graph::printLine()
{
    nrOfDigits = nrDigits();
    if(nrOfDigits < 4)
        nrOfDigits = 4;


    for (int i = 0; i < arrSize+1; i++)
    {
        for(int j = 0; j < nrOfDigits; j++)
        {
            cout << "_";
        }
        cout << "|" ;

    }
    cout << endl;
    for(int i = 0 ; i < arrSize+1; i ++)
    {
        for(int j = 0 ; j < nrOfDigits; j++)
        {
            cout << " ";
        }
        cout << "|";

    }
    cout << endl;
}









void Graph::printParentMatrix()
{
    cout << "Parent Matrix:\n Vertically are the Source Nodes\n Horizontally are the destination Nodes "
         << endl;
    printLine();
    bool alpha = true;
    for (int i = 0; i < arrSize; i ++)
    {

        if (alpha)
        {
            cout << std::setw(nrOfDigits) << " " << "|" ;
            alpha = false;
            i--;
        }
        else
            cout << std::setw(nrOfDigits) << i+1 << "|" ;

    }
    cout << endl;

    printLine();


    for(int i = 0; i < arrSize; i++)
    {
        cout << std::setw(nrOfDigits) << i+1 << "|";
        for(int j = 0; j < arrSize; j ++)
        {
            if(matrix[i][j] == INF)
                cout << std::setw(nrOfDigits) << "INF" << "|";
            else
                cout << std::setw(nrOfDigits) << matrix[i][j] << "|";

        }
        cout << endl;
        printLine();
    }
    cout << endl << endl;
}


void Graph::printDistanceMatrix()
{

    cout << "Distance Matrix:\n Vertically are the Source Nodes\n Horizontally are the destination Nodes "
         << endl;
    printLine();
    bool alpha = true;
    for (int i = 0; i < arrSize; i ++)
    {

        if (alpha)
        {
            cout << std::setw(nrOfDigits) << " " << "|" ;
            alpha = false;
            i--;
        }
        else
            cout << std::setw(nrOfDigits) << i+1 << "|" ;

    }
    cout << endl;

    printLine();


    for(int i = 0; i < arrSize; i++)
    {
        cout << std::setw(nrOfDigits) << i+1 << "|";
        for(int j = 0; j < arrSize; j ++)
        {
            if(shPath[i][j] == INF)
                cout << std::setw(nrOfDigits) << "INF" << "|";
            else
                cout << std::setw(nrOfDigits) << shPath[i][j] << "|";

        }
        cout << endl;
        printLine();
    }

    cout << endl << endl;
}



void Graph::warshallShortestPath()
{
    for(int i = 0; i < arrSize; i++)
    {
        for(int j = 0 ; j < arrSize; j++)
        {
            shPath[i][j] = matrix[i][j];
        }
    }

    for(int k = 0; k < arrSize; k ++)
    {
        for(int i = 0; i < arrSize; i++)
        {
            for(int j = 0; j < arrSize; j ++)
            {
                if( shPath[i][k] != INF && shPath[k][j] != INF &&
                    shPath[i][k] + shPath[k][j] < shPath[i][j])

                    shPath[i][j] = shPath[i][k] + shPath[k][j];

            }
        }
    }


}

