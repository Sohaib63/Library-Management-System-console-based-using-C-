#pragma once
#ifndef BORROWINGRECORD_H
#define BORROWINGRECORD_H
#include"library.h"
#include"subscribers.h"
#include<vector>
#include<map>
#include<set>
#include<string>
using namespace std;
#include<iomanip>
#include<sstream>
#include<ctime>
class borrowingrecord
{
private:
	subscribers subscriber;
	vector<library>lib;
	map<string,string> borrow_dates;
	map<string,string> returndates;
	map<string,int>fine;
public:
	borrowingrecord();
	borrowingrecord(subscribers that, library them);
	borrowingrecord(library them, subscribers that,string,string,string,string);
	borrowingrecord& add(subscribers that, library them);
	void set(subscribers that, library them);
	string tostring();
	string sptostring();
	string getsubscriberid();
	string getsubscribername();
	borrowingrecord setsubscriber(string subscriber_ID, string Type, string Name, string Address, string Phone, string Email);
	void setreturndate(int,string);
	void setborrowdate(int, string);
	string getborrowdate(int);
	string getreturndate(int);
	string dayafteraddingdays(int, int, int, int);
	bool isleapyear(int);
	int finecalcculation(int);
	string getlibrarysptostring();
	void deleteitem(int);
	int findbook(string, string);
	int finddigitalmedia(string, string);
	int findarticle(string, string);
	int finecalcculationforadminview(int item_id);
	void editbook(books);
	void editarticle(articles);
	void editdigitalmedia(digitalmedia);
	void uniquekey(int);
	void editlibray(string, string, string, string);
	void deletelibrary(string, string);
	friend bool operator<(const borrowingrecord&, const borrowingrecord&);
	void sortinfo();
	void setlibrary(library);
	void setfine(int itemid,int fine);
};
#endif // !BORROWINGRECORD_H

