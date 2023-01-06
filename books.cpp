#include"books.h"
#include<string>
#include<sstream>
#include<iomanip>
#include<iostream>
using namespace std;
books::books() :title(""), author(""), publisher(""), status(""), production_year(0), copies(0), item_id(0)
{}
books::books(string t, string a) : title(t), author(a), publisher(""), status(""), production_year(0), copies(0), item_id(0)
{}
books::books(string t, string a, string p, int prd, int c, string s, int i) : title(t), author(isValidAuthor(a)), publisher(isValidPublisher(p)), status(s), production_year(isValidProductionYear(prd)), copies(isValidCopies(c)), item_id(i)
{}
books& books::setbook(string t, string a, string p, int prd, int c, string s, int id)
{
	title = t;  author = isValidAuthor(a);  publisher = isValidPublisher(p); status = s; production_year = isValidProductionYear(prd); copies = isValidCopies(c); item_id = id;
	return *this;
}
bool operator<( books& left,  books& right)
{
	 if (left.getbookitemid() < right.getbookitemid())
	 {
		 return true;
	 }
	 return false;
}
string books::tostring() const
{
	stringstream sub;
	string data;
	sub << setw(12) << left << std::to_string(this->item_id) << setw(18) << left << "book" << setw(31) << left << this->title << setw(15) << left << this->author << setw(18) << left << this->publisher << setw(19) << left << std::to_string(this->production_year) << setw(18) << left << this->status << std::to_string(this->copies);
	getline(sub, data);
	return data;
}
void books::incresebookcopies(int itemid)
{
	if (this->item_id=itemid)
	{
		this->copies += 1;
	}
}
void books::decreaseoneinitemid()
{
	this->item_id = this->item_id - 1;
}
string books::sptostring()const
{
	string data;
	data = std::to_string(this->item_id) + ',' + "book" + ',' + this->title + ',' + this->author + ',' + this->publisher + ',' + std::to_string(this->production_year) + ',' + this->status + ',' + std::to_string(this->copies);
	return data;
}
bool operator == (const books& left, const books& right)
{
	
	if (!(_stricmp(left.author.c_str(), right.author.c_str())) && !(_stricmp(left.title.c_str(), right.title.c_str())))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool books::copiesdecrement()
{
	if (this->copies == 0)
	{
		return false;
	}
	else
	{
		this->copies = this->copies - 1;
		return true;
	}

}
string books::getbooktitle() const
{
	return this->title;
}
string books::getbookauthor() const
{
	return this->author;
}
string books::getbookstatus() const
{
	return this->status;
}
string books::getbookpublisher() const
{
	return this->publisher;
}
int books::getbookprodyear() const
{
	return this->production_year;
}
int books::getbookcopies() const
{
	return this->copies;
}
int books::getbookitemid() const
{
	
	return this->item_id;
}
string books::isValidAuthor(string auth) {
Author:
	for (int i = 0; i < auth.length(); i++)
	{
		if (!(isalpha(auth[i]) || auth[i] == 32))
		{
			cout << "Error! Author name should consisit alphabet or space. Please try again....\n";
			cout << "Enter Author name: ";
			getline(cin, auth, '\n');
			goto Author;
		}
	}
	return auth;
}
string books::isValidPublisher(string pub) {

Publisher:
	for (int i = 0; i < pub.length(); i++)
	{
		if (!(isalpha(pub[i]) || pub[i] == 32))
		{
			cout << "Error! Publisher name should consisit alphabet or space. Please try again....\n";
			cout << "Enter Publisher name: ";
			getline(cin, pub, '\n');
			goto Publisher;
		}
	}
	return pub;
}
int books::isValidProductionYear(int pyear) {


proyear:
	if (pyear > 2020 || pyear < 1800)
	{
		cout << "Error! Production year must be greater than 1800 and less or equal to 2020. Please try again....\n";
		cout << "Enter Production year: ";
		cin >> pyear;
		cin.ignore();
		goto proyear;
	}

	return pyear;
}
int books::isValidCopies(int copy) {

copies:
	if (copy < 0)
	{
		cout << "Error! No of copies must not be less than 0 or  Please try again....\n";
		cout << "Enter No of copies: ";
		cin >> copy;
		cin.ignore();
		goto copies;
	}

	return copy;
}
