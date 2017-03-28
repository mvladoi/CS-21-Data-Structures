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




#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H


class SortedArray
{
public:
    SortedArray();
    ~SortedArray();
    void insert(int input);
    void quickSort(int count){quicksortFunction(0,count-1);}
    void quickInsertSort(int count){quickInsertSortFunction(0, count-1);}
    int getInteger(int position);
    int getSize(){return size;}



private:
    void insertionSort(int a);
    void quicksortFunction(int first, int last);
    void quickInsertSortFunction(int first, int last);
    int partition(int first, int last);
    int medianOfThree(int first, int last, int middle);
    void resize();
    void swap(int* a, int* b);
    int *A;
    int size;
    int capacity;
    static const int THRESHOLD = 9;


};

#endif // SORTEDARRAY_H
