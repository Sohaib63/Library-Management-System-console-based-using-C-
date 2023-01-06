#pragma once
#ifndef LIBRARY_H
#define LIBRARY_H
#include"contents.h"
#include<vector>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;
class library
{
private:
	string Library_ID,
		Name;
	contents content;
public:
	library();
	library(string i, string n, books b);
	library(string i, string n, articles a);
	library(string i, string n, digitalmedia d);
	library(string i, string n);
	library(books b);
	library(articles a);
	library(digitalmedia d);
	bool equal(string input);
	string tostring_library();
	library& setlibrary(string i, string n);
	library& setarticle(articles a);
	library& setbook(books b);
	library& setdigitalmedia(digitalmedia d);
	string tostring() const;
	string sptostring() const;
	friend bool operator==(const library& left,const library&right);
	string getlibraryid() const;
	string getlibrartname() const;
	string isValidLibraryName(string);
	void deletecontentitem(int);
	int findbook(string, string);
	int finddigitalmedia(string, string);
	int findarticle(string, string);
	void increscopies(int);
	void editbook(books);
	void editarticle(articles);
	void editdigital(digitalmedia );
	void uniquekey(int);
	void sortinfo();
	friend bool operator<(const library& left, const library& right);
	string sptostring_library();
	string getnameonid(int);
};
#endif // !LIBRARY_H

