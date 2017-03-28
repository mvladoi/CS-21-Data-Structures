#ifndef SSRECORD_H
#define SSRECORD_H
#include "Record.h"

class SSRecord:public Record
{
public:
    SSRecord();
    SSRecord(int newRecordNumber, std::string newRecordData);
    SSRecord(SSRecord& otherRecord);
    std::string printRecord();
    std::string getRecordData();
    void setRecordNumber(int newNumber){recordNumber = newNumber;}
    void setRecordData(std::string newData){recordData = newData;}
    int getRecordNumber();
    bool foundRecord(int number);


};


#endif
