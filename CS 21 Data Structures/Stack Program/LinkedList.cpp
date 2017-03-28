

/*Full Name: Vladoi Marian
  Pengo Account Name: mvladoi
  Email: vladoimarian@yahoo.com
  Directory Name: 21-1
  Assignement: Linked List
  Description: creting a Stack using a Linked List
  Code Status: working/tested
  The program compile with no errors and warnings
**/




#include "LinkedList.h"


using std::cout;
using std::endl;



void LinkedList::insertFront(double input)
{
    LinkedListNode* temp = new LinkedListNode(input);
    temp->next = first;
    first = temp;

}



LinkedList::~LinkedList()
{
    LinkedListNode* temp;
    while(!isEmpty())
    {
        temp = first;
        first = first->next;
        delete temp;

    }
}



void LinkedList::deleteFront()
{
    if (isEmpty())
    {
        cout << "Can not delete from an empty List" << endl;
    }
    LinkedListNode* temp = first;
    first = first->next;
    temp->print();
    delete temp;
}





