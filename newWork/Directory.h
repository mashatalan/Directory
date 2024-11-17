#pragma once
#include <vector>
#include <fstream>
#include "Record.h"
class Directory
{
	vector <Record> records;
	const string filename;

	void loadFromFile();
	void saveToFile() const;
	
};

