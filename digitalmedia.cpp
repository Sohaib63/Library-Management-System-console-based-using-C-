#include "digitalmedia.h"
#include<string>
#include<sstream>
#include<iomanip>
#include<iostream>
using namespace std;
digitalmedia::digitalmedia() :title(""), author(""), publisher(""), status(""), production_year(0), copies(0), item_id(0)
{}
digitalmedia::digitalmedia(string t, string a) : title(t), author(a), publisher(""), status(""), production_year(0), copies(0), item_id(0)
{}
digitalmedia::digitalmedia(string t, string a, string p, int prd, string s, int c, int id) : title(t), author(isValidAuthor(a)), publisher(isValidPublisher(p)), status(s), production_year(isValidProductionYear(prd)), copies(isValidCopies(c)), item_id(id)
{}
digitalmedia& digitalmedia::setdigitalmedia(string t, string a, string p, int prd, string s, int c, int id)
{
	title = t;  author = isValidAuthor(a);  publisher = isValidPublisher(p); status = s; production_year = isValidProductionYear(prd); copies = isValidCopies(c); item_id = id;
	return *this;
}
void digitalmedia::decreaseoneinitemid()
{
	this->item_id = this->item_id - 1;
}
bool operator<( digitalmedia& left,  digitalmedia& right)
{
	if (left.getdigitalmediaitemid() < right.getdigitalmediaitemid())
	{
		return true;
	}
	return false;
}
string digitalmedia::tostring()
{
	string data;
	stringstream sub;
	sub << setw(12) << left << std::to_string(this->item_id) << setw(18) << left << "digital media" << setw(31) << left << this->title << setw(15) << left << this->author << setw(18) << left << this->publisher << setw(19) << left << std::to_string(this->production_year) << setw(18) << left << this->status << std::to_string(this->copies);
	getline(sub, data);
	return data;
}
bool digitalmedia::copiesdecrement()
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
string digitalmedia::sptostring()const
{
	string data;
	data = std::to_string(this->item_id) + ',' + "digital media" + ',' + this->title + ',' + this->author + ',' + this->publisher + ',' + std::to_string(this->production_year) + ',' + this->status + ',' + std::to_string(this->copies);
	return data;
}
void digitalmedia::incresecopies(int itemid)
{
	if (this->item_id = itemid)
	{
		this->copies += 1;
	}
}
bool operator == (const digitalmedia& left,const digitalmedia& right)
{

	if (!(_stricmp(left.title.c_str(), right.title.c_str())) && !(_stricmp(left.author.c_str(), right.author.c_str())))
	{
		return true;
	}
	else
	{
		return false;
	}
}
string digitalmedia::getdigitalmediatitle() const
{
	return this->title;
}
string digitalmedia::getdigitalmediaauthor() const
{
	return this->author;
}
string digitalmedia::getdigitalmediastatus() const
{
	return this->status;
}
string digitalmedia::getdigitalmediapublisher() const
{
	return this->publisher;
}
int digitalmedia::getdigitalmediaprodyear() const
{
	return this->production_year;
}
int digitalmedia::getdigitalmediacopies() const
{
	return this->copies;
}
int digitalmedia::getdigitalmediaitemid() const
{
	return this->item_id;
}
string digitalmedia::isValidAuthor(string auth) {
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
string digitalmedia::isValidPublisher(string pub) {

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
int digitalmedia::isValidProductionYear(int pyear) {

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
int digitalmedia::isValidCopies(int copy) {

copies:
	if (copy < 0)
	{
		cout << "Error! No of copies must not be less than 0. Please try again....\n";
		cout << "Enter No of copies: ";
		cin >> copy;
		cin.ignore();
		goto copies;
	}

	return copy;
}
