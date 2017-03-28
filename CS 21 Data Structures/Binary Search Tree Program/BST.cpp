


#include <iostream>
#include <cassert>
#include <sstream>
#include <climits>
#include "BST.h"

BST::BST()
{
    root = 0;
}



BST::~BST()
{
    destroy(root);
}


void BST::destroy(BSTNode* &p)
{
    if(p != 0)
    {
        destroy(p->left);
        destroy(p->right);
        delete p;
        p = 0;

    }
}



bool BST::isEmpty()
{
    return (root == 0);
}





BSTNode* BST::insert(int key)
{
    BSTNode* current;
    BSTNode* trailCurrent;
    BSTNode* newNode = new BSTNode(key);


    assert(newNode != NULL);

    if (root == NULL)
        root = newNode;
    else
    {
        current = root;
        while (current != NULL)
        {
            trailCurrent = current;
            if (current->data == key)
            {
                std::cerr << "The insert item is already in the list-";


                return newNode;
            }
            else if (current->data > key)
                current = current->left;
            else
                current = current->right;
        }
        if (trailCurrent->data > key)
            trailCurrent->left = newNode;
        else
            trailCurrent->right = newNode;
    }

    return newNode;
}




BSTNode* BST::min()
{
    if(!isEmpty())
    {
        return findMin(root);

    }

    else
        return 0;
}


BSTNode*  BST::findMin(BSTNode* p)
{
    while(p->left)
        p = p->left;
    return p;

}


BSTNode* BST::max()
{

    if(!isEmpty())
    {
        return findMax(root);

    }

    else
        return 0;


}


BSTNode* BST::findMax(BSTNode* p)
{
    while (p->right)
        p = p->right;
    return p;
}



BSTNode* BST::successor(int key)
{

    if(!isEmpty())
    {

        return  findSuccessor(root, key);

    }


    return 0;
}




BSTNode* BST::findSuccessor(BSTNode* p, int key)
{
    BSTNode* successor = 0;
    BSTNode* current = root;
    while (current -> data != key)
    {
        if(current-> data > key)
        {
            successor = current;
            current= current->left;
        }
        else
            current = current->right;
    }
    if(current && current->right)
        successor = findMin(current->right);


    return successor;
}




BSTNode* BST::predecessor(int key)
{


    if(!isEmpty())
    {

        return  findPredecessor(root, key);

    }


    return 0;
}



BSTNode* BST::findPredecessor(BSTNode* p, int key)
{
    BSTNode* predecessor = NULL;
    BSTNode* current  = root;



    while(current && current->data != key)
    {
        if(current->data >key)
        {
            current= current->left;
        }
        else
        {
            predecessor = current;
            current = current->right;
        }
    }
    if(current && current->left)
        predecessor = findMax(current->left);


    return predecessor;

}





std::string BST::printInOrderTraversal()
{
    std::stringstream fout;
    fout.clear();
    fout.str("");
    if(!isEmpty())
    {
        fout << "inorder traversal:\n";
        inOrder(root, fout);
        fout << "\n";
    }
    else
        fout << "The Three is Empty.\n";

    return fout.str();
}


void BST::inOrder(BSTNode* p, std::stringstream& fout)
{
    if(p)
    {
        inOrder(p->left, fout);
        fout << p->data << " ";
        inOrder(p->right, fout);

    }

}




std::string BST::printPreOrderTraversal()
{
    std::stringstream fout;
    fout.clear();
    fout.str("");
    if(!isEmpty())
    {
        fout << "preorder traversal:\n";
        preOrder(root, fout);
        fout << "\n";
    }
    else
        fout << "The Three is empty.\n";

    return fout.str();

}


void BST::preOrder(BSTNode* p, std::stringstream& fout)
{
    if(p)
    {
        fout << p->data << " ";
        preOrder(p->left, fout);
        preOrder(p->right, fout);
    }
}






std::string BST::printPostOrderTraversal()
{
    std::stringstream fout;
    fout.clear();
    fout.str("");
    if(!isEmpty())
    {
        fout << "postorder traversal: \n";
        postOrder(root, fout);
        fout << "\n";
    }
    else
        fout << "The Three is empty.\n";

    return fout.str();

}


void BST::postOrder(BSTNode* p, std::stringstream& fout)
{
    if(p)
    {
        postOrder(p->left, fout);
        postOrder(p->right, fout);
        fout << p->data << " ";

    }
}


BSTNode* BST::search(int key)
{

    if(!isEmpty())
    {
        return searchNode(root, key);

    }
    else
        std::cerr << "Error, Empty Tree.\n";
    return 0;


}



BSTNode* BST::searchNode(BSTNode* p , int key)
{

    BSTNode *current;
    bool found = false;


    current = root;
    while (current != NULL && !found)
    {
        if (current->data == key)
        {
            found = true;
            return current;
        }
        else if (current->data > key)
            current = current->left;
        else
            current = current->right;
    }//end while

    return 0;


}





bool BST::delete_(int key)
{


    BSTNode* current; //pointer to traverse the tree
    BSTNode* trailCurrent; //pointer behind current
    bool found = false;
    if (root == NULL)
    {
        std::cerr << "Error, Empty Three.\n ";
        return false;
    }
    else
    {
        current = root;
        trailCurrent = root;
        while (current  && !found)
        {
            if (current->data == key)
                found = true;
            else
            {
                trailCurrent = current;
                if (current->data > key)
                    current = current->left;
                else
                    current = current->right;
            }
        }
        if (current == NULL)
        {

            return false;
        }
        else if (found)
        {
            if (current == root)
                deleteNode(root);
            else if (trailCurrent->data > key)
                deleteNode(trailCurrent->left);
            else
                deleteNode(trailCurrent->right);


        }

        return true;
    }


}





void BST::deleteNode(BSTNode* &p)
{

    BSTNode* current;
    BSTNode* trailCurrent;
    BSTNode* temp;
    if (p == NULL)
        std::cerr << "Error: The node to be deleted is NULL." << std::endl;
    else if(!p->left && !p->right)
    {
        temp = p;
        p = NULL;
        delete temp;
    }
    else if(!p->left)
    {
        temp = p;
        p = temp->right;
        delete temp;
    }
    else if(!p->right)
    {
        temp = p;
        p = temp->left;
        delete temp;
    }
    else
    {
        current = p->left;
        trailCurrent = NULL;
        while (current->right)
        {
            trailCurrent = current;
            current = current->right;
        }
        p->data = current->data;
        if (trailCurrent == NULL)

            p->left = current->left;
        else
            trailCurrent->right = current->left;
        delete current;
    }
}








