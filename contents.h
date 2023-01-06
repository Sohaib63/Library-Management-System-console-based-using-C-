#pragma once
#ifndef CONTENTS_H
#define CONTENTS_H
#include"articles.h"
#include"books.h"
#include<iostream>
#include"digitalmedia.h"
#include<vector>
class contents
{
private:
	vector<articles> article;//vector<articles>::iterator it;
	vector<books> book;
	vector<digitalmedia> digital;
public:
	contents();
	contents(articles a);
	contents(books b);
	contents(digitalmedia d);
	contents(articles a, books b, digitalmedia d);
	contents& setarticle(articles a);
	bool editcopies(articles a);
	bool editcopies(books b);
	bool editcopies(digitalmedia d);
	contents& setbook(books b);
	contents& setdigitalmedia(digitalmedia d);
	string tostring() const;
	string sptostring() const;
	void deleteitem(int);
	int findbook(string, string);
	int finddigitalmedia(string, string);
	int findarticle(string, string);
	void increasecopies(int);
	void editbook(books);
	void editarticles(articles);
	void editdigitalmedia(digitalmedia);
	void uniquekey(int);
	void sort();
	string getnameonid(int);
};
#endif // !CONTENTS_H

