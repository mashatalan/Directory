#include <iostream>
#include "Record.h"
#include "Directory.h"
using namespace std;


int main()
{
    Directory directory;
    int choice;
    

    do
    {
        cout << "\n\n MENU \n\n";
        cout << "1. Added record.\n";
        cout << "2. Search by name\n";
        cout << "6. Display all records\n";
        cout << "0. Exit.\n";
        cout << "Enter your choice : ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            string companeName, owner, phone, address, activity;
            cout << "Name company : ";
            getline(cin, companeName);
            cout << "Owner : ";
            getline(cin, owner);
            cout << "Phone : ";
            getline(cin, phone);
            cout << "Address : ";
            getline(cin, address);
            cout << "Activity : ";
            getline(cin, activity);
            directory.addRecord(Record(companeName, owner, phone, address, activity));
            cout << "Record added.\n";
            break;
        }
        case 2:
        {
            string searchCompanyName;
            cout << "Enter a company name to search : ";
            getline(cin, searchCompanyName);
            directory.searchByCompanyName(searchCompanyName);
            break;
        }
        case 6:
        {
            directory.displayAll();
            break;
        }
        default:
            break;
        }

    } while (choice != 0);
}
