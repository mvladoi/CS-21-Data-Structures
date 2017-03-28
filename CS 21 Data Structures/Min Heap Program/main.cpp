#include <iostream>
#include "MinHeap.h"
using std::endl;
using std::cout;


const int sizeArr = 10;
void printSizeHeap(MinHeap& Data);



int main()
{
     cout << "Vladoi Marian" << endl << endl;
    int arr[sizeArr] = {5,3,7,1,2,4,9,8,6,10};



    cout << "The input integer array is:" << endl;
    cout << "{";
    for(int i = 0; i < sizeArr; i++){
        cout << arr[i];
        if(i < sizeArr -1)
            cout <<",";
    }
    cout << "}" << endl << endl;




    MinHeap Data(arr , sizeArr);

    cout << "Creating a integer minimum priority queue" << endl;
    cout << Data.toString();
    printSizeHeap(Data);


    Data.extractMin();

    Data.extractMin();


    cout << "Calling extractMin function two times"<< endl;
    cout << Data.toString();
    printSizeHeap(Data);


    Data.heapInsert(1);


    cout << "Calling heapInsert(1) function" << endl;
    cout << Data.toString();
    printSizeHeap(Data);



    cout << "Calling heapSort() function" << endl;
    int* sortedArr = Data.heapSort();
    cout << "{";
    for(int i = 0; i < Data.getSize(); i++)
    {
        cout << *(sortedArr + i);
        if(i <= Data.getSize() - 2)
            cout << ",";
    }
    cout << "}" << endl << endl;




    cout << "Printing the heap" << endl;
    cout << Data.toString();
    printSizeHeap(Data);

}



void printSizeHeap(MinHeap& Data)
{
    cout << "Heap size is: " << Data.getSize() << endl << endl;
}
