#pragma once
#ifndef ARTICLES_H
#define ARTICLES_H
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;
class articles
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
	articles();
	articles(string t, string a, string p, string s, int prd, int c, int id);
	articles(string t, string a);
	articles& setarticle(string t, string a, string p, string s, int prd, int c, int id);
	bool copiesdecrement();
	string tostring();
	string sptostring()const;
	friend bool operator == (const articles& left, const articles& right);
	string getarticletitle() const;
	string getarticleauthor() const;
	string getarticlestatus() const;
	string getarticlepublisher() const;
	int getarticleprodyear() const;
	int getarticlecopies() const;
	int getarticleitemid() const;
	string isValidAuthor(string);
	string isValidPublisher(string);
	int isValidProductionYear(int);
	int isValidCopies(int);
	void increasecopies(int);
	void decreaseoneinitemid();
	friend bool operator<(articles& left,articles&right);
};
#endif // !ARTICLES_H

