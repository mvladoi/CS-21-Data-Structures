#include "SSRecord.h"


SSRecord::SSRecord()
    {
        recordNumber = 0;
        recordData = "";
    }




SSRecord::SSRecord(int newRecordNumber, std::string newRecordData)
    {
        recordNumber = newRecordNumber;
        recordData= newRecordData;
    }




SSRecord::SSRecord(SSRecord& otherRecord)
    {
        recordNumber = otherRecord.recordNumber;
        recordData = otherRecord.recordData;
    }





std::string SSRecord:: printRecord()
    {
        std::stringstream out;
        out.str("");
        out.clear();
        out << std::setfill('0') << std::setw(9) << recordNumber << " " << recordData << "\n";
        return out.str();

    }

std::string SSRecord::getRecordData(){
return recordData;
}


int SSRecord::getRecordNumber(){
return recordNumber;
}


bool SSRecord::foundRecord(int number){
return (number == recordNumber);
}

