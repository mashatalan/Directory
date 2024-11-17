#include "Record.h"

string Record::getCompanyName() const
{
	return this->companyName;
}

void Record::setCompanyName(string name)
{
	this->companyName = name;
}

string Record::getOwner() const
{
	return this->owner;
}

void Record::setOwner(string owner)
{
	this->owner = owner;
}

string Record::getPhone() const
{
	return this->phone;
}

void Record::setPhone(string phone)
{
	this->phone = phone;
}

string Record::getAddress() const
{
	return this->address;
}

void Record::setAdress(string address)
{
	this->address = address;
}

string Record::getActivity() const
{
	return this->activity;
}

void Record::setActivity(string activity)
{
	this->activity = activity;
}

void Record::display() const
{
	cout << "Name company : " << this->companyName << "\n";
	cout << "Owner : " << this->owner << "\n";
	cout << "Nuber phone : " << this->phone << "\n";
	cout << "Address : " << this->address << "\n";
	cout << "Activity : " << this->activity << "\n";
	cout << "\n\n\n";
}

void Record::saveToFile(ofstream& file) const
{
	file << this->companyName << "\n";
	file << this->owner << "\n";
	file << this->phone << "\n";
	file << this->address << "\n";
	file << this->activity << "\n";

}

bool Record::loadFromFile(ifstream& file)
{
	if (getline(file, companyName)&&
		getline(file, owner)&&
		getline(file, phone)&&
		getline(file, address)&&
		getline(file, activity))
	{
		return true;
	}
	return false;
}



