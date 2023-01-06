#include "subscribers.h"
#include<string>
#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;
subscribers::subscribers() :subscriber_ID(""), Type(""), Name(""), Address(""), Phone(""), Email("")
{}
subscribers::subscribers(string id, string name) : subscriber_ID(id), Name(isValidSubscriberName(name)), Type(""), Address(""), Phone(""), Email("")
{}
subscribers::subscribers(string i, string t, string n, string a, string p, string e) : subscriber_ID(i), Type(isValidSubscriberType(t)), Name(isValidSubscriberName(n)), Address(a), Phone(isValidSubscriberPhone(p)), Email(isValidSubscriberEmail(e))
{}
subscribers& subscribers::setsubscriber(string i, string t, string n, string a, string p, string e)
{
	subscriber_ID = i, Type = isValidSubscriberType(t), Name = isValidSubscriberName(n), Address = a, Phone = isValidSubscriberPhone(p); Email = isValidSubscriberEmail(e);
	return *this;
}
string  subscribers::sptostring() const
{
	string data;
	data=this->subscriber_ID + ","+ this->Type + "," + this->Name + "," +  this->Address + "," +  this->Phone+ "," + this->Email+"\n";
	return data;
}
string  subscribers::tostring() const
{
	string data;
	stringstream sub;
	sub << setw(23) << left << this->subscriber_ID << setw(14) << left << this->Type << setw(30) << left << this->Name << setw(30) << left << this->Address << setw(20) << left << this->Phone << this->Email;
	getline(sub, data);
	return data;
}
bool operator<(const subscribers& left, const subscribers& right)
{
	if (stoi(left.subscriber_ID,nullptr,10) < stoi(right.subscriber_ID,nullptr,10))
	{
		return true;
	}
	else
	{
		return false;
	}
}
ostream& operator<<(ostream& strn, subscribers& right)
{

	strn << right.tostring();
	return strn;
}
void subscribers::setid(string id)
{
	this->subscriber_ID = id;
}
void subscribers::setname(string n)
{
	this->Name = isValidSubscriberName(n);
}
bool operator==(const subscribers& left, const subscribers& right)
{

	if (!(_stricmp(left.Name.c_str(), right.Name.c_str())) && !(_stricmp(left.subscriber_ID.c_str(), right.subscriber_ID.c_str())))
	{
		return true;
	}
	else
	{
		return false;
	}

}
string subscribers::getsubsriberid() const
{
	return this->subscriber_ID;
}
string subscribers::getsubsriberTYPE() const
{
	return this->Type;
}
string subscribers::getsubscriberNAME()const
{
	return this->Name;
}
string subscribers::getsubscriberaddress()const
{
	return this->Address;
}
string subscribers::getsubscriberPHONE()const
{
	return this->Phone;
}
string subscribers::getsubscriberEMAIL()const
{
	return this->Email;
}
string subscribers::isValidSubscriberType(string stype)
{
sstype:
	if (stype == "regular" || stype == "Regular" || stype == "REGULAR" || stype == "golden" || stype == "Golden" || stype == "GOLDEN") {
		return stype;
	}
	else {
		cout << "Error! Subscriber type should be 'Golden' or 'Regular'. Please try again....\n";
		cout << "Enter Subscriber type: ";
		getline(cin, stype, '\n');
		goto sstype;
	}

}
string subscribers::isValidSubscriberName(string sname) {
Subscribername:
	if (sname.length() > 30)
	{
		cout << "Error! Subscriber name length should be of 30 or less. Please try again....\n";
		cout << "Enter Subscriber name: ";
		getline(cin, sname, '\n');
		goto Subscribername;
	}
	for (int i = 0; i < sname.length(); i++)
	{
		if (!(isalpha(sname[i]) || sname[i] == 32))
		{
			cout << "Error! Subscriber name should consisit alphabet or space. Please try again....\n";
			cout << "Enter Subcsriber name: ";
			getline(cin, sname, '\n');
			goto Subscribername;
		}
	}
	return sname;

}

string subscribers::isValidSubscriberPhone(string pNo) {
SubscriberPhone:
	if (pNo.length() == 11)
	{
		for (int i = 0; i < pNo.length(); i++)
		{
			if (!(isdigit(pNo[i])))
			{
				cout << "Error! Phone no must contain only digits. Please try again...\n";
				cout << "Enter Subscriber Phone no: ";
				getline(cin, pNo, '\n');
				goto SubscriberPhone;
			}
		}

	}
	else
	{
		cout << "Error! Subscriber Phone no length should be of 11. Please try again....\n";
		cout << "Enter Subscriber Phone no: ";
		getline(cin, pNo, '\n');
		goto SubscriberPhone;
	}

	return pNo;
}
string subscribers::isValidSubscriberEmail(string semail)
{
email:
	size_t x = semail.find('@');
	if (x != string::npos)
	{
		string key;
		key = semail.substr(x + 1);
		if (!(key == "gmail.com" || key == "hotmail.com" || key == "yahoo.com"))
		{
			cout << "Error! email must contain 'gmail.com' or 'hotmail.com' or 'yahoo.com' as domain Please try again...\n";
			cout << "Enter email: ";
			getline(cin, semail, '\n');
			goto email;
		}
	}
	else {
		cout << "Error! email must contain domain Please try again...\n";
		cout << "Enter email: ";
		getline(cin, semail, '\n');
		goto email;
	}
	return semail;
}
