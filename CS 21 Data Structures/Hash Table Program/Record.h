#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cmath>
class Record
{
    public:
        virtual std::string printRecord() = 0;
        virtual std::string getRecordData()= 0;
        virtual int getRecordNumber() = 0;
        virtual bool foundRecord(int number)= 0;
        virtual void setRecordNumber(int number) = 0;
        virtual void setRecordData(std::string newData) = 0;

    protected:
        int recordNumber;
        std::string recordData;
};

#endif // RECORD_H
