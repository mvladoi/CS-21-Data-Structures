
/**
FULL NAME: VLADOI MARIAN
PENGO ACCOUNT NAME: mvladoi
EMAIL: vladoimarian@yahoo.com
FILENAME: 21-3
ASSIGNMENT 3: Quicksort
DESCRIPTION: Implementing quicksort using the median of three partition and
             insert sort for smaller arrays
CODE STATUS: I think is working/tested
THE PROGRAM COMPILE WITH NO ERRORS AND WARNINGS
*/






#include <iostream>
#include "SortedArray.h"

SortedArray::SortedArray()
{
    capacity = 15;
    A = new int[capacity];
    size = 0;


}



SortedArray::~SortedArray()
{
    if(A != 0)
    {
        delete [] A;
        A = 0;
    }
}




void SortedArray::insert(int input)
{
    A[size] = input;
    size++;
    if(size == capacity)resize();

}




void SortedArray::resize()
{
    int *temp = new int[2*capacity];
    for(int i = 0; i < size; i++)
    {
        temp[i] = A[i];
    }
    capacity = capacity*2;
    delete [] A;
    A = NULL;
    A = temp;

}





int SortedArray::getInteger(int position)
{
    if(position < size)
    {
        return A[position];
    }
    std::cerr << "Warning , position bigger than size of array, returning 0" << std::endl;
    return 0;
}





void SortedArray::swap(int* a, int* b)
{

    int temp = *a;
    *a = *b;
    *b = temp;

}





void SortedArray::quicksortFunction(int first, int last)
{
    if(first < last)
    {
        int q = partition(first, last);
        quicksortFunction(first, q-1);
        quicksortFunction(q+1, last);
    }
}




int SortedArray::partition(int first, int last)
{

    int x = 0;
    if((last - first) > THRESHOLD)
    {
        x = medianOfThree(first, last, ((first+last)/2));
        swap(&A[x],&A[last]);
    }



    int i = first - 1;

    for(int j = first; j < last; j++)
    {
        if(A[j] <= A[last])
        {
            i++;
            swap(&A[i],&A[j]);

        }
    }
    swap(&A[i+1], &A[last]);
    return (i+1);//pivot point
}






int SortedArray::medianOfThree(int first, int last, int middle)
{

    if(A[first] > A[last])
    {
        if(A[last] > A[middle])return last;
        if(A[first] > A[middle])return middle;
        return first;
    }
    else
    {
        if(A[last] < A[middle])return last;
        if(A[first] < A[middle]) return middle;
        return first;
    }


}



void SortedArray::quickInsertSortFunction(int first, int last)
{
    if((last - first) > THRESHOLD)
    {
        int q = partition(first, last);
        quickInsertSortFunction(first, q-1);
        quickInsertSortFunction(q+1, last);
    }
    else
        insertionSort(THRESHOLD);
}





void SortedArray::insertionSort(int count)
{
    for(int j = 1; j < count; j++)
    {
        int key = A[j];
        int i = j - 1;
        while(i >= 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }

}
