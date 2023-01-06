#pragma once
#ifndef SUBSCRIBERS_H
#define SUBSCRIBERS_H
#include<string>
#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;
class subscribers
{
private:
	string subscriber_ID,
		Type,
		Name,
		Address,
		Phone,
		Email;
public:
	subscribers();
	subscribers(string id, string name);
	subscribers(string i, string t, string n, string a, string p, string e);
	subscribers& setsubscriber(string i, string t, string n, string a, string p, string e);
	string  tostring() const;
	string  sptostring() const;
	friend bool operator<(const subscribers& left, const subscribers& right);
	friend ostream& operator<<(ostream& strn, subscribers& right);
	void setid(string id);
	void setname(string n);
	friend bool operator==(const subscribers& left, const subscribers& right);
	string getsubsriberid() const;
	string getsubsriberTYPE() const;
	string getsubscriberNAME()const;
	string getsubscriberaddress()const;
	string getsubscriberPHONE()const;
	string getsubscriberEMAIL()const;
	string isValidSubscriberType(string);
	string isValidSubscriberName(string);
	string isValidSubscriberPhone(string);
	string isValidSubscriberEmail(string);
};
#endif // !SUBSCRIBERS_H

