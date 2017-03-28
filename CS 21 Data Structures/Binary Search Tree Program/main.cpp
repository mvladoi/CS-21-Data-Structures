




#include <iostream>
#include <sstream>
#include <climits>
#include "BST.h"

using namespace std;





void readFile(std:: string operation, int value, BST& Three);





int main()
{
    BST Three;
    std::string operation;
    int value = 0;
    string line;


    while(getline(std::cin, line))
    {
        std::stringstream fin(line);

        fin >> operation;
        if(operation != "#")
        {
            if (operation == "insert" || operation == "delete" || operation == "search" ||
                    operation == "successor" || operation == "predecessor")
            {
                fin >> value;


            }
            readFile(operation, value, Three);

        }
    }
}




void readFile(std::string operation, int key, BST& Three)
{

    if(operation == "postorder")
    {
        std::cout << Three.printPostOrderTraversal();
    }
    else if(operation == "inorder")
    {
        std::cout << Three.printInOrderTraversal();

    }
    else if(operation == "preorder")
    {
        std::cout << Three.printPreOrderTraversal();
    }
    else if(operation == "insert")
    {
        BSTNode* insertPtr = Three.insert(key);
        if(!insertPtr)
            std::cout <<"not inserted " << key << ".\n";
        else
            std::cout << "inserted " << Three.getInfo(insertPtr) << ".\n";
    }
    else if(operation == "search" )
    {
        if (Three.isEmpty())
            std::cout << "Three is empty.\n";
        else
        {
            BSTNode* foundPtr = Three.search(key);
            if(foundPtr)
                std::cout << Three.getInfo(foundPtr) << " found.\n";
            else
                std::cout << key << " not found.\n";
        }
    }
    else if(operation == "delete")
    {

        bool deletedKey = Three.delete_(key);


        if(!deletedKey)
            std::cout << "deleted " << key << " - not found.\n";

        else
        {
            std::cout << "deleted " << key << ".\n";

        }

    }
    else if(operation == "min")
    {

        BSTNode* min = Three.min();
        if(min)
            std::cout << "min is " << Three.getInfo(min) << ".\n";
        else
            std::cout << "The Three is empty.\n";
    }

    else if (operation == "max")
    {

        BSTNode* max = Three.max();
        if(max)
            std::cout << "max is " <<Three.getInfo(max) << ".\n";
        else
            std::cout << "The Three is empty.\n";


    }
    else if(operation == "predecessor")
    {
        if(Three.isEmpty())
            std::cout<< "The Three is empty.\n";
        else
        {
            BSTNode* foundPtr = Three.search(key);
            if(!foundPtr)
                std::cout << key << " not in tree.\n";
            else
            {
                BSTNode* predecessorPtr = Three.predecessor(key);
                if(!predecessorPtr)
                    std::cout << "no predecessor for " << key << ".\n";
                else
                    std::cout << key << " predecessor is " << Three.getInfo(predecessorPtr) << ".\n";
            }
        }

    }
    else if(operation == "successor")
    {
        if(Three.isEmpty())
            std::cout<< "The Three is empty.\n";
        else
        {
            BSTNode* foundPtr = Three.search(key);
            if(!foundPtr)
                std::cout << key << " not in tree.\n";
            else
            {
                BSTNode* successorPtr = Three.successor(key);
                if(!successorPtr)
                    std::cout << "no successor for " << key << ".\n";
                else
                    std::cout << key << " successor is " << Three.getInfo(successorPtr) << ".\n";
            }
        }
    }

    else
        std:: cout << "Invalid operation\n";


}







