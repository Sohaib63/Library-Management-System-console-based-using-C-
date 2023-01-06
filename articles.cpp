#include "articles.h"
#include<string>
#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;
articles::articles() :title(""), author(""), publisher(""), status(""), production_year(0), copies(0), item_id(0)
{}
articles::articles(string t, string a) : title(t), author(a), publisher(""), status(""), production_year(0), copies(0), item_id(0)
{}
articles::articles(string t, string a, string p, string s, int prd, int c, int id) : title(t), author(isValidAuthor(a)), publisher(isValidPublisher(p)), status(s), production_year(isValidProductionYear(prd)), copies(isValidCopies(c)), item_id(id)
{}
bool operator<(articles& left,articles &right)
{
	if (left.getarticleitemid()<right.getarticleitemid() )
	{
		return true;
	}
	return false;
}
void articles::decreaseoneinitemid()
{
	this->item_id = this->item_id - 1;
}
void articles::increasecopies(int itemid)
{
	if (this->item_id = itemid)
	{
		this->copies += 1;
	}
}
articles& articles::setarticle(string t, string a, string p, string s, int prd, int c, int id)
{
	title = t;  author = isValidAuthor(a);  publisher = isValidPublisher(p); status = s; production_year = isValidProductionYear(prd); copies = isValidCopies(c); item_id = id;
	return *this;
}

bool articles::copiesdecrement()
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

string articles::tostring()
{
	stringstream sub;
	string data;
	sub << setw(12) << left << std::to_string(this->item_id) << setw(18) << left << "article" << setw(31) << left << this->title << setw(15) << left << this->author << setw(18) << left << this->publisher << setw(19) << left << std::to_string(this->production_year) << setw(18) << left << this->status << std::to_string(this->copies);
	getline(sub, data);
	return data;
}

string articles::sptostring()const
{
	string data;
	data = std::to_string(this->item_id) + ',' + "article" + ',' + this->title + ',' + this->author + ',' + this->publisher + ',' + std::to_string(this->production_year) + ',' + this->status + ',' + std::to_string(this->copies);
	return data;
}

bool operator == (const articles& left, const articles& right)
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
string articles::getarticletitle() const
{
	return this->title;
}
string articles::getarticleauthor() const
{
	return this->author;
}
string articles::getarticlestatus() const
{
	return this->status;
}
string articles::getarticlepublisher() const
{
	return this->publisher;
}
int articles::getarticleprodyear() const
{
	return this->production_year;
}
int articles::getarticlecopies() const
{
	return this->copies;
}
int articles::getarticleitemid() const
{
	return this->item_id;
}
string articles::isValidAuthor(string auth)
{
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
string articles::isValidPublisher(string pub)
{
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
int articles::isValidProductionYear(int pyear)
{

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
int articles::isValidCopies(int copy)
{

copies:
	if (copy < 0)
	{
		cout << "Error! No of copies must not  be less than 0. Please try again....\n";
		cout << "Enter No of copies: ";
		cin >> copy;
		cin.ignore();
		goto copies;
	}

	return copy;
}
