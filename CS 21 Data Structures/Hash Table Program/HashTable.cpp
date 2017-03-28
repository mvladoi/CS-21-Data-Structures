#include "HashTable.h"






HashTable::HashTable():arraySize(100){
 array = new std::vector<SSRecord*>* [arraySize];
 for(int i = 0; i < arraySize; i++){
    array[i] = NULL;
 }

}


HashTable::HashTable(int newArraySize):arraySize(newArraySize)
{
    array = new std::vector<SSRecord*>* [arraySize];
    for(int i = 0; i < arraySize; i ++){
        array[i] = new std::vector<SSRecord*>;
    }
}



HashTable::~HashTable()
{
    delete []array;
}



int HashTable::hash(SSRecord* ptr){

return (int)(arraySize*(ptr->getRecordNumber()*c - floor(ptr->getRecordNumber()*c)));

}



void HashTable::insertRecord(SSRecord* newRecord){

array[hash(newRecord)]->push_back(newRecord);

}




void HashTable::deleteRecord(int numberOfRecord){
int pos = hashKey(numberOfRecord);
int size = array[pos]->size();
SSRecord* first = find(numberOfRecord);
if (first != NULL){
    SSRecord* second = array[pos]->at(size-1);
    first->setRecordNumber(second->getRecordNumber());
    first->setRecordData(second->getRecordData());
    array[pos]->pop_back();

}
else
    std::cerr << "This Record is not in the Hash Table\n";

}


SSRecord* HashTable::find(int numberOfRecord){
int size = array[hashKey(numberOfRecord)]->size();
int pos = hashKey(numberOfRecord);
for(int i = 0; i < size; i++){
    if(array[pos]->at(i)->foundRecord(numberOfRecord))
        return array[pos]->at(i);
}
return NULL;

}


SSRecord* HashTable::searchRecord(int numberOfRecord){
return find(numberOfRecord);
}



void HashTable::clearArrayVectors(){
for(int i = 0; i < arraySize; i++){
    array[i]->clear();
}

}



int HashTable::getRecordsInHashTable(){
int recordsInHashTable = 0;
for(int i = 0; i < arraySize; i++){
    recordsInHashTable += array[i]->size();
}
return recordsInHashTable;
}



void HashTable::readFromFile(std::string fileName){
std::ifstream fin;
fin.open(fileName.c_str());
int key;
std::string info;
if(fin.fail()){
    std::cerr << "Input file opening failed.\n";
    exit(0);
}
while(fin >> key){
    getline(fin,info);
    SSRecord myRecord(key, info);
    SSRecord* ptr= new SSRecord(myRecord);
    insertRecord(ptr);

}
fin.close();

}


void HashTable::writeToFile(std::string fileName){
std::ofstream fout;
fout.open(fileName.c_str());
if(fout.fail()){
    std::cerr << "File failed to create!\n";
    exit(0);
}

for(int i = 0; i < arraySize; i++){
    int vectorSize = array[i]->size();
    for(int j = 0; j < vectorSize; j++){
         fout << array[i]->at(j)->printRecord();

}

}
fout.close();
}
