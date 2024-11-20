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
		cout << "Warning: Could not open the file \"" << filename << "\". A new file will be created.\n";
		
	}
}

void Directory::saveToFile() const
{
	ofstream file(filename);
	if (file.is_open())
	{
		cout << records.size() << "\n";
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

void Directory::addRecord(const Record& record)
{
	records.push_back(record);
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

void Directory::searchByActivity(const string& activity) const
{
	bool f = false;
	for (const auto& record : records)
	{
		if (record.getActivity() == activity)
		{
			record.display();
			f = true;
		}
	}
	if (!f)
	{
		cout << "Record with " << activity << " not found \n";
	}
}


