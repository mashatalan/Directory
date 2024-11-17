#include "Directory.h"

void Directory::loadFromFile()
{
	ifstream file(filename);
	if (file.is_open())
	{
		records.clear();
		Record record;
		while (record.loadFromFile(file))
		{
			records.push_back(record);
		}
		file.close();
	}
	else
	{
		cout << "Could not open the file";
		exit(EXIT_FAILURE);
	}
}

void Directory::saveToFile() const
{
	ofstream file(filename);
	if (file.is_open())
	{
		for (int i = 0; i < records.size(); i++)
		{
			records[i].saveToFile(file);
		}
		file.close();
	}
	cout << "Could not open the file";
	exit(EXIT_FAILURE);
}
