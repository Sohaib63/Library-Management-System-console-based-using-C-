#pragma once
#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;
class digitalmedia
{
private:
	string title,
		author,
		publisher,
		status;
	int production_year,
		copies,
		item_id;
public:
	digitalmedia();
	digitalmedia(string t, string a, string p, int prd, string s, int c, int id);
	digitalmedia(string t, string a);
	digitalmedia& setdigitalmedia(string t, string a, string p, int prd, string s, int c, int id);
	string tostring();
	bool copiesdecrement();
	string sptostring()const;
	friend bool operator == (const digitalmedia& left,const digitalmedia& right);
	string getdigitalmediatitle() const;
	string getdigitalmediaauthor() const;
	string getdigitalmediastatus() const;
	string getdigitalmediapublisher() const;
	int getdigitalmediaprodyear() const;
	int getdigitalmediacopies() const;
	int getdigitalmediaitemid() const;
	string isValidAuthor(string);
	string isValidPublisher(string);
	int isValidProductionYear(int);
	int isValidCopies(int);
	void decreaseoneinitemid();
	void incresecopies(int itemid);
	friend bool operator<( digitalmedia& left,  digitalmedia& right);
};
#endif // !DIGITALMEDIA_H
