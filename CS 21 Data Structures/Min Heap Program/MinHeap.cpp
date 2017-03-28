

#include <iostream>
#include <sstream>
#include "MinHeap.h"

MinHeap::MinHeap()
{
    capacity = 15;
    A = new int [capacity];
    size = 0;
}

MinHeap::MinHeap(int myArray[],  const int sizeArr)
{
    capacity = 15;
    A = new int [capacity];
    size = 0;

    if (sizeArr > capacity)
    {
        std::cout << "The MinHeap capacity is smaller than your array size" << std::endl;
        std::cout << "Only " << capacity << " elements were inserted in the MinHeap" << std::endl;
        for (int i = 0; i < capacity ; i++)
            heapInsert(myArray[i]);
    }


    else
        for(int i = 0; i < sizeArr; i++)

        {
            heapInsert(myArray[i]);
        }


}


bool MinHeap::isEmpty()
{
    return (size == 0);
}

bool MinHeap::isFull()
{
    return (size == capacity-1);
}



MinHeap::~MinHeap()
{
    if(!isEmpty())
    {
        delete [] A;
        A = NULL;
    }
}

int MinHeap::parent(int position)
{
    return position/2;
}


int MinHeap::left(int position)
{
    return 2*position;
}


int MinHeap::right(int position)
{
    return (2*position) + 1;
}



int MinHeap::minimum()
{
    if(isEmpty())
    {
        return 0;
    }
    return A[1];
}


void MinHeap::swap(int first, int last)
{
    int temp = A[last];
    A[last] = A[first];
    A[first] = temp;
}


int MinHeap::indexOfSmallest(int position, int l, int r)
{
    int minIndex = position;
    if(size >= l && A[l] < A[minIndex])
        minIndex = l;

    if(size >= r && A[r] < A[minIndex])
        minIndex = r;

    return minIndex;
}


void MinHeap::buildHeap()
{
    for(int i = size/2; i >= 1; i--)
        heapify(i);
}


void MinHeap::heapify(int i)
{
    int minIndex = indexOfSmallest(i, left(i), right(i));
    if(i!= minIndex)
    {
        swap(i, minIndex);
        heapify(minIndex);
    }
}

int MinHeap::extractMin()
{
    if(isEmpty())
    {
        std::cout << "The array is empty./n";
        return 0;
    }
    int data = minimum();
    A[1] = A[size];
    size--;
    heapify(1);
    return data;

}


void MinHeap::heapInsert(int newValue)
{
    buildHeap();
    size++;
    A[size] = newValue-1;
    decreaseKey(size, newValue);
}




void MinHeap::decreaseKey(int s, int key)
{
    if(A[s] >= key)
        return ;
    A[s] = key;
    while(s > 1 && A[parent(s)] > A[s])
    {
        swap(s, parent(s));
        s = parent(s);
    }

}



int* MinHeap::heapSort()
{
    int temp = size;
    int* newArray = new int[capacity];
    int* minHeap = new int[capacity];

    for(int i = 1; i <= temp; i++)
    {
        minHeap[i] = A[i];


    }


    for (int i = temp -1; i >= 0; i--)
    {
        newArray[i] = extractMin();

    }



    for (int i = 1; i <= temp ; i++)
    {
        A[i] = minHeap[i];

    }
    size = temp;
    return newArray;

}

std::string MinHeap::toString()
{
    std::stringstream ss;
    ss.clear();
    ss.str("");



    ss << "{";
    for (int i = 1; i <= size; i++)
    {
        ss << A[i];
        if(i< size)
        {
            ss << ", ";
        }
    }
    ss << "}\n";


    std::string s;
    s = ss.str();

    return s;
}
