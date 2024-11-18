#include "Directory.h"

void Directory::loadFromFile()
{
	ifstream file(filename);
	if (file.is_open())
	{
		records.clear();
		Record record;
		int count = 0;
		while (record.loadFromFile(file))
		{
			records.push_back(record);
			count++;
		}
		recordCount = count;
		file.close();
		cout << "Records loaded: " << count << "\n";
	}
	else
	{
		cout << "Warning: Could not open the file \"" << filename << "\". A new file will be created.\n";
		
	}
}

void Directory::saveToFile() const
{
	ofstream file(filename);
	if (file.is_open())
	{
		file << "Quantity firm :" << records.size() << "\n";
		for (const auto& record:records)
		{
			record.saveToFile(file);
		}
		file.close();
		
	}
	else
	{
		cout << "Could not open the file";
		exit(EXIT_FAILURE);
	}
	
}

Directory::Directory()
{
	loadFromFile();
}

int Directory::getRecordCount() const
{
	return this->recordCount;
}



void Directory::addRecord(const Record& record)
{
	records.push_back(record);
	recordCount++;
	saveToFile();
}

void Directory::displayAll() const
{
	if (!records.empty())
	{
		for (const auto& record:records)
		{
			record.display();
		}
	}
	else
	{
		cout << "Directory is empty.\n";
	}
}

void Directory::searchByCompanyName(const string& companyName) const
{
	bool f = false;
	for (const auto& record:records)
	{
		if (record.getCompanyName() == companyName)
		{
			record.display();
			f = true;
		}
	}
	if (!f)
	{
		cout << "Record with name  " << companyName << " not found \n";
	}
}

void Directory::searchByOwner(const string& owner) const
{
	bool f = false;
	for (const auto& record:records)
	{
		if (record.getOwner() == owner)
		{
			record.display();
			f = true;
		}
	}
	if (!f)
	{
		cout << "Record with " << owner << " not found \n";
	}

}

void Directory::searchByNumberPhone(const string& numberPhone) const
{
	bool f = false;
	for (const auto& record : records)
	{
		if (record.getPhone() == numberPhone)
		{
			record.display();
			f = true;
		}
	}
	if (!f)
	{
		cout << "Record with " << numberPhone << " not found \n";
	}

}


