#ifndef MINHEAP_H
#define MINHEAP_H


class MinHeap
{
    public:
        MinHeap();
        MinHeap(int myArr[], const int sizeArr);
        ~MinHeap();
        int* heapSort();
        std::string  toString();
        void heapInsert(int i);
        int minimum();
        int extractMin();
        void decreaseKey(int i, int k);
        bool isEmpty();
        bool isFull();
        int getSize(){return size;}



    private:
        void buildHeap();
        void heapify(int i);
        void swap(int first, int second);
        int *A;
        int capacity;
        int size;
        int parent(int i);
        int left(int i);
        int right(int i);
        int indexOfSmallest(int i, int j, int k);

};

#endif // MINHEAP_H
