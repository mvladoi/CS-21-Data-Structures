
/*Full Name: Vladoi Marian
  Pengo Account Name: mvladoi
  Email: vladoimarian@yahoo.com
  Directory Name: 21-1
  Assignement: Linked List
  Description: creting a Stack using a Linked List
  Code Status: working/tested
  The program compile with no errors and warnings
**/



#include "Stack.h"



int main()
{
    Stack myStack;
    double userInput = 0;
    while(std::cin >> userInput)
    {
        myStack.push(userInput);
    }
    while(!myStack.isEmpty()) {myStack.pop();}

    return 0;
}
