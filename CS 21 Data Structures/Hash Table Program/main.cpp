#include <iostream>
#include "HashTable.h"




void readFromFile(HashTable& c);
void writeToFile(HashTable& c);
void deleteRecord(HashTable& c);
void insertManually(HashTable& c);
void searchRecord(HashTable& c);
void clearHashTable(HashTable& c);
void printRecordsNumber(HashTable& c);








int main()
{

    HashTable SocialSecurity(178000);
    bool play = true;

    while(play)
    {

        std::cout << "\n\nMENU:\n"
                  << "1.Insert Record from a file by entering the file Name\n"
                  << "2.Insert a new Record from the keyboard\n"
                  << "3.Delete a Record by entering the Record Number\n"
                  << "4.Search for a Record by entering Record Number\n"
                  << "5.Clear the entire Hash Table\n"
                  << "6.Save the Hash Table to Disk\n"
                  << "7.Exit\n\n"
                  << "Please enter your choice: ";


        int choice = 0;
        std::cin >> choice;

        if(choice == 1)
        {
            readFromFile(SocialSecurity);
        }
        else if(choice == 2)
        {
            insertManually(SocialSecurity);
        }
        else if(choice == 3)
        {
            deleteRecord(SocialSecurity);
        }
        else if(choice == 4)
        {
            searchRecord(SocialSecurity);
        }
        else if(choice == 5)
        {
            clearHashTable(SocialSecurity);
        }
        else if(choice == 6)
        {
            writeToFile(SocialSecurity);
        }
        else
            play = false;


    }
}


void readFromFile(HashTable& c)
{
    std::string fileName;
    std:: cout << "Enter File Name: ";
    std::cin >> fileName;
    c.readFromFile(fileName);
    printRecordsNumber(c);
}


void deleteRecord(HashTable& c)
{
    int input = 0;
    std::cout << "Enter Record Number to be deleted: ";
    std::cin >> input;
    if(c.getRecordsInHashTable() > 0)
        std::cout << "Deleting the record nr " << input << std::endl;

    c.deleteRecord(input);
    printRecordsNumber(c);
}


void insertManually(HashTable& c)
{
    std::string info;
    int recordNumber;
    std::cout << "Enter Record Number to be inserted: ";
    std::cin >> recordNumber;
    std::cin.ignore();
    std::cin.clear();
    std::cout << "Enter Record Information: ";
    getline(std::cin, info);
    SSRecord inputRecord(recordNumber, info);
    SSRecord* ptr = new SSRecord(inputRecord);
    c.insertRecord(ptr);
    printRecordsNumber(c);
}


void searchRecord(HashTable& c)
{
    SSRecord* ptr;
    int recordNumber;
    std::cout << "Enter Record Number that you search for: ";
    std::cin >> recordNumber;
    ptr = c.searchRecord(recordNumber);
    if(ptr != 0)
        std:: cout << ptr->printRecord();
    else
        std::cout << "This Record is not in the HashTable\n";

}

void clearHashTable(HashTable& c)
{
    c.clearArrayVectors();
    printRecordsNumber(c);
}


void writeToFile(HashTable &c)
{
    std::string fileName;
    std::cout << "Enter File Name: ";
    std::cin >> fileName;

    c.writeToFile(fileName);
}



void printRecordsNumber(HashTable& c)
{

    std::cout <<"There are: " << c.getRecordsInHashTable() << " Records in HashTable\n";
}


