#pragma once
#ifndef BOOKS_H
#define BOOKS_H
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;
class books
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
	books();
	books(string t, string a, string p, int prd, int c, string s, int i);
	books(string t, string a);
	books& setbook(string t, string a, string p, int prd, int c, string s, int id);
	string tostring() const;
	string sptostring()const;
	friend bool operator ==(const books& left,const books &right);
	bool copiesdecrement();
	string getbooktitle() const;
	string getbookauthor() const;
	string getbookstatus() const;
	string getbookpublisher() const;
	int getbookprodyear() const;
	int getbookcopies() const;
	int getbookitemid() const;
	string isValidAuthor(string);
	string isValidPublisher(string);
	int isValidProductionYear(int);
	int isValidCopies(int);
	void incresebookcopies(int itemid);
	void decreaseoneinitemid();
	friend bool operator<( books& left,  books& right);
};
#endif // !BOOKS_H

