/**
FULL NAME: VLADOI MARIAN
PENGO ACCOUNT NAME: mvladoi
EMAIL: vladoimarian@yahoo.com
FILENAME: 21-2
ASSIGNMENT 2: Radix Bucket Sort
CODE STATUS: I think is working/tested
THE PROGRAM COMPILE WITH NO ERRORS AND WARNINGS
*/



#include <iostream>
#include <iomanip>
#include <cstdlib>


const int NROFBUCKETS = 10;




void radixBucketSort(int*& array, int size);
void resize(int*& array, int size, int& capacity);
int maxValue(int* array, int size);






int main()
{


    int capacity = 100000;
    int size = 0;

    int* array = new int[capacity];

    int temp;
   // while(std::cin >> temp)
   for(int i = 0; i < 50000000; i++)
    {
        array[size++] = i;
        if(size == capacity)
        {
            resize(array, size, capacity);
        }
    }

        radixBucketSort(array, size);

        for(int i = 0; i < 100; i++)
        {
            std::cout << std::setfill('0') << std::setw(9) << array[i] << std::endl;
        }



   delete []array;

    return 0;
}





void resize(int*& array, int size, int& capacity)
{

    int *tempArray;
    tempArray = new int[2*capacity + 1];
    for(int i = 0; i <= capacity; i++)
    {
        tempArray[i] = array[i];
    }
    delete [] array;
    array = NULL;
    capacity = capacity*2 + 1;
    array = tempArray;

}






int maxValue(int* array, int size)
{
    int temp;
    for(int i = 0; i < size; i++)
    {
        if(array[i] > temp)
            temp = array[i];
    }
    return temp;
}



void radixBucketSort(int*& array, int size)
{

    int index;

    int maxNumber = maxValue(array, size);

    // run the loop for each of the decimal places
    int exp = 1;

    int *tmpBuffer = new int[size];

    while (maxNumber / exp > 0)
    {
        int decimalBucket[10] = { 0 };

        // count the occurences in this decimal digit.
        for (index = 0; index < size; index++)
            decimalBucket[array[index] / exp % 10]++;


        // Prepare the position counters to be used for re-ordering the numbers
        // for this decimal place.
        for (index = 1; index < NROFBUCKETS; index++)
            decimalBucket[index] += decimalBucket[index - 1];


        // Re order the numbers in the tmpbuffer and later copy back to original buffer.
        for (index = size - 1; index >= 0; index--)
            tmpBuffer[--decimalBucket[array[index] / exp % 10]] = array[index];


          int* tempPtr = tmpBuffer;
          tmpBuffer = array;
          array = tempPtr;
        //for (index = 0; index < size; index++)
           //array[index] = tmpBuffer[index];

        // Move to next decimal place.
        exp *= 10;

std::cout << "Passed\n";
    }

delete []tmpBuffer;
}













