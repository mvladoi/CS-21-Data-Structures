
/*Full Name: Vladoi Marian
  Pengo Account Name: mvladoi
  Email: vladoimarian@yahoo.com
  Directory Name: 21-1
  Assignement: Linked List
  Description: creting a Stack using a Linked List
  Code Status: working/tested
  The program compile with no errors and warnings
**/


#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H
#include <iostream>
#include <iomanip>




class LinkedListNode
{

    friend class LinkedList;
public:
    LinkedListNode()
    {
        next = 0;
    }



    LinkedListNode(double input)
    {
        next = 0;
        object = input;
    }





    void print()
    {
        std::cout << std::fixed << std::setprecision(3) << object << std::endl;
    }




private:
    double object;
    LinkedListNode* next;
};

#endif // LINKEDLISTNODE_H
