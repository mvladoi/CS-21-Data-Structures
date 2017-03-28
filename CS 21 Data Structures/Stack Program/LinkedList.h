
/*Full Name: Vladoi Marian
  Pengo Account Name: mvladoi
  Email: vladoimarian@yahoo.com
  Directory Name: 21-1
  Assignement: Linked List
  Description: creting a Stack using a Linked List
  Code Status: working/tested
  The program compile with no errors and warnings
**/




#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "LinkedListNode.h"



class LinkedList
{
public:

    LinkedList()
    {
        first = 0;
    }
    ~LinkedList();
    void insertFront(double input);
    void deleteFront();
    bool isEmpty()
    {
        return (!first);
    }



private:
    LinkedListNode*  first;
};

#endif // LINKEDLIST_H
