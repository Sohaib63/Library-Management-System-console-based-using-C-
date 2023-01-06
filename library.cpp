#include "library.h"
#include"contents.h"
#include"books.h"
#include"articles.h"
#include"digitalmedia.h"
#include<vector>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;
library::library() :Library_ID(""), Name("")
{}
library::library(string i, string n, books b) : Library_ID(i), Name(isValidLibraryName(n))
{
	content.setbook(b);
}
library::library(string i, string n, articles a) : Library_ID(i), Name(isValidLibraryName(n))
{
	content.setarticle(a);
}
library::library(string i, string n, digitalmedia d) : Library_ID(i), Name(isValidLibraryName(n))
{
	content.setdigitalmedia(d);
}
library::library(string i, string n) : Library_ID(i), Name(isValidLibraryName(n))
{}
library::library(books b)
{
	content.setbook(b);
}
library::library(articles a)
{
	content.setarticle(a);
}
library::library(digitalmedia d)
{
	content.setdigitalmedia(d);
}
bool library::equal(string input)
{
	stringstream sub3;
	sub3 << input;
	string title, catagory,
		author,
		publisher,
		status,
		production_year,
		copies,
		item_id;
	getline(sub3, item_id, ','); getline(sub3, catagory, ',');	getline(sub3, title, ',');	getline(sub3, author, ',');	getline(sub3, publisher, ','), getline(sub3, production_year, ',');	getline(sub3, status, ',');	getline(sub3, copies, '\n');
	if (!(_stricmp(catagory.c_str(), "book")))
	{
		return content.editcopies({ title, author, publisher, stoi(production_year, nullptr, 10), stoi(copies, nullptr, 10), status, stoi(item_id, nullptr, 10) });
	}
	if (!(_stricmp(catagory.c_str(), "article")))
	{
		return content.editcopies({ title, author, publisher, status, stoi(production_year, nullptr, 10), stoi(copies, nullptr, 10), stoi(item_id, nullptr, 10) });
	}
	if (!(_stricmp(catagory.c_str(), "digital media")))
	{
		return content.editcopies({ title, author, publisher, stoi(production_year, nullptr, 10), status, stoi(copies, nullptr, 10), stoi(item_id, nullptr, 10) });
	}
}
string library::tostring_library()
{
	stringstream sub;
	string data;
	sub << setw(20) << left << this->Library_ID << this->Name;
	getline(sub, data);
	return data;
}
string library::sptostring_library()
{
	string data;
	data= this->Library_ID+","+ this->Name;
	return data;
}
library& library::setlibrary(string i, string n)
{
	this->Library_ID = i; this->Name = isValidLibraryName(n);
	return *this;
}
library& library::setarticle(articles a)
{
	this->content.setarticle(a);
	return *this;
}
library& library::setbook(books b)
{
	this->content.setbook(b);
	return *this;
}
library& library::setdigitalmedia(digitalmedia d)
{
	this->content.setdigitalmedia(d);
	return *this;
}
void library::increscopies(int itemid)
{
	content.increasecopies(itemid);
}
string library::tostring() const
{
	string data;
	data = content.tostring();
	return data;
}
string library::sptostring() const
{
	string data;
	data = content.sptostring();
	return data;
}
bool operator==(const library& left,const library& right)
{
	
	if (!(_stricmp(left.Library_ID.c_str(), right.Library_ID.c_str())) && !(_stricmp(left.Name.c_str(), right.Name.c_str())))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator<(const library& left, const library& right)
{
	if (left.Library_ID<right.Library_ID)
	{
		return true;
	}
	else
	{
		return false;
	}
}
string library::getnameonid(int itemid)
{
	return content.getnameonid(itemid);
}
void library::sortinfo()
{
	content.sort();
}
void library::uniquekey(int itemid)
{
	content.uniquekey(itemid);
}
void library::deletecontentitem(int item_id)
{
	content.deleteitem(item_id);
}
string library::getlibraryid() const
{
	return this->Library_ID;
}
string library::getlibrartname() const
{
	return this->Name;
}
string library::isValidLibraryName(string lname)
{
Libraryname:
	for (int i = 0; i < lname.length(); i++)
	{
		if (!(isalpha(lname[i]) || lname[i] == 32))
		{
			cout << "Error! Library name should consisit alphabet or space. Please try again....\n";
			cout << "Enter Library name: ";
			getline(cin, lname, '\n');
			goto Libraryname;
		}
	}
	return lname;
}
void library::editdigital(digitalmedia that)
{
	content.editdigitalmedia(that);
}
void library::editarticle(articles that)
{
	content.editarticles(that);
}
void library::editbook(books that)
{
	content.editbook(that);
}
int library::findbook(string name, string author)//title name
{
	
	return content.findbook(name, author);
}
int library::finddigitalmedia(string name, string author)
{
	return content.finddigitalmedia(name, author);
}
int library::findarticle(string name, string author)
{
	return content.findarticle(name, author);
}