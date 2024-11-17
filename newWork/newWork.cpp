#include <iostream>
#include "Record.h"
using namespace std;


int main()
{
    Record firm1("VOG Industries", "John Doe", "123-456-7890", "46 Sunshine Street", "Energy Solutions");
    firm1.display();
    
    const string fileName = "text.txt";
    ofstream file(fileName);
    if (file.is_open())
    {
        firm1.saveToFile(file);
        cout << "Recoding in file : " << fileName << "\n";
        file.close();
    }
    else
    {
        cout << "Error. Failed to open file.";
    }
}
