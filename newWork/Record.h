#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class Record
{
	string companyName;
	string owner;
	string phone;
	string address;
	string activity;
public:
	Record() = default;
	Record(const string& name, const string& owner, const string& phone, const string& address, const string& activity) :
		companyName{ name }, owner{ owner }, phone{ phone }, address{ address }, activity{ activity } {}
	
	string getCompanyName() const;
	void setCompanyName(string);

	string getOwner() const;
	void setOwner(string);

	string getPhone() const;
	void setPhone(string);

	string getAddress() const;
	void setAdress(string);

	string getActivity() const;
	void setActivity(string);

	void display() const;

	void saveToFile(ofstream&) const;
	bool loadFromFile(ifstream&);
};


