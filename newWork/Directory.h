#pragma once
#include <vector>
#include <fstream>
#include "Record.h"
using namespace std;
class Directory
{
	vector <Record> records;
	const string filename = "text.txt";
	int recordCount = 0;

	void loadFromFile();
	void saveToFile() const;
public:
	Directory();
	int getRecordCount() const;
	void addRecord(const Record&);
	void displayAll() const;

};

