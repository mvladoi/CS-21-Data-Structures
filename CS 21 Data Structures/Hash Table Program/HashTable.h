#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "SSRecord.h"


class HashTable
{
    public:
        HashTable();
        HashTable(int newArraySize = 100);
        ~HashTable();
        void insertRecord(SSRecord* newRecord);
        void deleteRecord (int numberOfRecord);
        SSRecord* searchRecord(int numberOfRecord);
        void clearArrayVectors();
        void readFromFile(std::string fileName);
        void writeToFile(std::string fileName);
        int getRecordsInHashTable();

    private:
        SSRecord* find(int numberOfRecord);
        int hash(SSRecord*);
        int hashKey(int key){return (int) (arraySize*(key*c - floor(key*c)));}
        int arraySize;
        static const double c = .618034;
        std::vector<SSRecord*> ** array;
};

#endif // HASHTABLE_H
