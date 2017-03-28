
/*Full Name: Vladoi Marian
  Pengo Account Name: mvladoi
  Email: vladoimarian@yahoo.com
  Directory Name: 21-1
  Assignement: Linked List
  Description: creting a Stack using a Linked List
  Code Status: working/tested
  The program compile with no errors and warnings
**/


#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"



class Stack : public LinkedList
{
public:
    Stack() {};

    void push(double input)
    {
        insertFront(input);
    }


    void pop()

        {
            deleteFront();
        }
};

#endif // STACK_H
