#include "borrowingrecord.h"
#include"library.h"
#include"subscribers.h"
#include<vector>
#include<iomanip>
#include<sstream>
#include<ctime>
#include<string>
#include<algorithm>
using namespace std;
const int MaxDayInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
borrowingrecord::borrowingrecord()
{}
borrowingrecord::borrowingrecord(subscribers that, library them)
{
	subscriber.setsubscriber(that.getsubsriberid(), that.getsubsriberTYPE(), that.getsubscriberNAME(), that.getsubscriberaddress(), that.getsubscriberPHONE(), that.getsubscriberEMAIL());
	lib.push_back(them);
	string item_id;
	stringstream sub; sub << them.sptostring();
	getline(sub, item_id, ',');
	time_t t = time(NULL);//to use system date 
	struct tm toget;
	localtime_s(&toget, &t);
	int day, month, year;
	day = toget.tm_mday;
	month = toget.tm_mon + 1;
	year = toget.tm_year + 1900;
	string date = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
	setborrowdate(stoi(item_id,nullptr,10),date);
}
borrowingrecord::borrowingrecord( library them, subscribers that,string itemid,string date,string returndate,string fee)
{
	subscriber.setsubscriber(that.getsubsriberid(), that.getsubsriberTYPE(), that.getsubscriberNAME(), that.getsubscriberaddress(), that.getsubscriberPHONE(), that.getsubscriberEMAIL());
	lib.push_back(them);
	setborrowdate(stoi(itemid, nullptr, 10),date);
	setreturndate(stoi(itemid, nullptr, 10),returndate);
	setfine(stoi(itemid,nullptr,10),stoi(fee,nullptr,10));
}

borrowingrecord& borrowingrecord::add(subscribers that, library them)
{
	subscriber.setsubscriber(that.getsubsriberid(), that.getsubsriberTYPE(), that.getsubscriberNAME(), that.getsubscriberaddress(), that.getsubscriberPHONE(), that.getsubscriberEMAIL());
	lib.push_back(them);
	string item_id;
	stringstream sub; sub << them.sptostring();
	getline(sub, item_id, ',');
	time_t t = time(NULL);//to use system date 
	struct tm toget;
	localtime_s(&toget, &t);
	int day, month, year;
	day = toget.tm_mday;
	month = toget.tm_mon + 1;
	year = toget.tm_year + 1900;
	string date = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
	setborrowdate(stoi(item_id, nullptr, 10), date);
	return *this;
}
void borrowingrecord::set(subscribers that, library them)
{
	subscriber.setsubscriber(that.getsubsriberid(), that.getsubsriberTYPE(), that.getsubscriberNAME(), that.getsubscriberaddress(), that.getsubscriberPHONE(), that.getsubscriberEMAIL());
	lib.push_back(them);
	string item_id;
	stringstream sub; sub << them.sptostring();
	getline(sub, item_id, ',');
	time_t t = time(NULL);//to use system date 
	struct tm toget;
	localtime_s(&toget, &t);
	int day, month, year;
	day = toget.tm_mday;
	month = toget.tm_mon + 1;
	year = toget.tm_year + 1900;
	string date = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
	setborrowdate(stoi(item_id, nullptr, 10), date);
}
void borrowingrecord::deleteitem(int itemid)
{
	for (auto it = lib.begin(); it != lib.end(); it++)
	{
		it->deletecontentitem(itemid);
	}
}
void borrowingrecord::editlibray(string findid, string findname, string replaceid, string replacename)
{
	auto it = find(lib.begin(), lib.end(), library(findid,findname));
	if (it!=lib.end())
	{
		it->setlibrary(replaceid, replacename);
	}
}
void borrowingrecord::sortinfo()
{
	sort(lib.begin(), lib.end());
	for (auto it=lib.begin();it!=lib.end();it++)
	{
		it->sortinfo();
	}
}
bool operator<(const borrowingrecord& left, const borrowingrecord& right)
{
	if (left.subscriber.getsubsriberid()<right.subscriber.getsubsriberid())
	{
		return true;
	}
}
void borrowingrecord::deletelibrary(string id,string name)
{
	auto it = find(lib.begin(), lib.end(), library(id, name));
	if (it != lib.end())
	{
		lib.erase(it);
	}
}
void borrowingrecord::uniquekey(int itemid)
{
	string record;
	for (auto it = borrow_dates.begin(); it != borrow_dates.end(); it++)
	{
		record += it->first + "," + it->second + "\n";
	}
	borrow_dates.clear();
	stringstream sub;
	sub << record;
	while (getline(sub, record, '\n'))
	{
		stringstream sub2;
		sub2 << record;
		string subscriberid, item, date;
		getline(sub2, subscriberid, ','); getline(sub2, item, ','); getline(sub2, date);
		int id;
		id = stoi(item, nullptr, 10);
		if (id > itemid) { id = id - 1; }
		string data = subscriberid + "," + std::to_string(id);
		borrow_dates[data] = date;
	}
	//
	string record2;
	for (auto it = returndates.begin(); it != returndates.end(); it++)
	{
		record2 += it->first + "," + it->second + "\n";
	}
	returndates.clear();
	stringstream sub2;
	sub2 << record2;
	while (getline(sub2, record2, '\n'))
	{
		stringstream sub2;
		sub2 << record2;
		string subscriberid, item, date;
		getline(sub2, subscriberid, ','); getline(sub2, item, ','); getline(sub2, date);
		int id;
		id = stoi(item, nullptr, 10);
		if (id > itemid) { id = id - 1; }
		string data = subscriberid + "," + std::to_string(id);
		returndates[data] = date;
	}
	//
	//
	string record3;
	for (auto it = fine.begin(); it != fine.end(); it++)
	{
		record3 += it->first + "," + std::to_string(it->second) + "\n";
	}
	fine.clear();
	stringstream sub3;
	sub3 << record3;
	while (getline(sub3, record3, '\n'))
	{
		stringstream sub2;
		sub2 << record3;
		string subscriberid, item, fine;
		getline(sub2, subscriberid, ','); getline(sub2, item, ','); getline(sub2, fine);
		int id;
		id = stoi(item, nullptr, 10);
		if (id > itemid) { id = id - 1; }
		string data = subscriberid + "," + std::to_string(id);
		this->fine[data] = stoi(fine, nullptr, 10);
	}
	//
	for (auto it=lib.begin();it!=lib.end();it++)
	{
		it->uniquekey(itemid);
	}
}
string borrowingrecord::getlibrarysptostring()
{
	string data;
	string record;
	for (auto it : lib)
	{
		stringstream sub;
		sub << it.sptostring();
		while (getline(sub, data, '\n'))
		{
			record += it.getlibraryid() + "," + it.getlibrartname() + "," + data + "\n";
		}
	}
	return record;
}
string borrowingrecord::sptostring()
{
	string data;
	string record;
	for (auto it : lib)
	{
		stringstream sub;
		sub << it.sptostring();
		while (getline(sub, data, '\n'))
		{
			stringstream content_id;
			content_id << data;
			string item_id;
			getline(content_id, item_id, ',');
			string index = getreturndate(stoi(item_id,nullptr,10));
			int fine;
			if (index == "----")
			{
				fine = 0;
			}
			else
			{
				string data = getsubscriberid() + "," + (item_id);
				fine = this->fine[data];
			}
		record += subscriber.getsubsriberid() + "," + getborrowdate(stoi(item_id,nullptr,10)) + "," + item_id + "," + index +","+std::to_string(fine)+ "\n";
		}

	}
	return record;
}
void borrowingrecord::setlibrary(library them)
{
	lib.push_back(them);
	string item_id;
	stringstream sub; sub << them.sptostring();
	getline(sub, item_id, ',');
}
string borrowingrecord::tostring()
{
	string data;
	string record;
	for (auto it : lib)
	{
		stringstream sub;
		sub << it.sptostring();
		while (getline(sub, data, '\n'))
		{
			stringstream content_id;
			content_id << data;
			string item_id;
			getline(content_id,item_id, ',');
			string index = getreturndate(stoi(item_id,nullptr,10));
			int fine;
			if (index== "----")
			{
				fine = 0;
			}
			else
			{
				string data = getsubscriberid() + "," + item_id;
				fine=this->fine[data];
			}
			record += subscriber.getsubsriberid() + "\t\t\t" + getborrowdate(stoi(item_id,nullptr,10)) + "\t\t\t" + item_id + "\t\t\t" + index +std::to_string(fine) +"\n" ;
		}

	}
	return record;
}
string borrowingrecord::getsubscriberid()
{
	return(subscriber.getsubsriberid());
}
string borrowingrecord::getsubscribername()
{
	return(subscriber.getsubscriberNAME());
}
bool borrowingrecord::isleapyear(int year)//part of validation of function
{

	if (year % 400 == 0)
	{
		return 1;
	}
	else if (year % 100 == 0)
	{
		return 0;
	}
	else if (year % 4 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
void borrowingrecord::editdigitalmedia(digitalmedia that)
{
	for (auto it = lib.begin(); it != lib.end(); it++)
	{
		it->editdigital(that);
	}
}
void borrowingrecord::editarticle(articles that)
{
	for (auto it = lib.begin(); it != lib.end(); it++)
	{
		it->editarticle(that);
	}
}
void borrowingrecord::editbook(books that)
{
	for (auto it=lib.begin();it!=lib.end();it++)
	{
		it->editbook(that);
	}
}
void borrowingrecord::setfine(int itemid, int fine)
{
	string data = getsubscriberid() + "," + std::to_string(itemid);
	this->fine[data] = fine;
}
int borrowingrecord::finecalcculationforadminview(int item_id)
{
	string day1, month1, year1;
	int dyear, dmonth, dDay, Ryear, Rmonth, Rday;
	time_t t = time(NULL);//to use system date 
	struct tm toget;
	localtime_s(&toget, &t);
	Rday = toget.tm_mday;
	Rmonth = toget.tm_mon + 1;
	Ryear = toget.tm_year + 1900;
	stringstream sub2;
	string duedate;
	string data = getsubscriberid() + "," + std::to_string(item_id);
	sub2 << this->borrow_dates[data];
	getline(sub2, day1, '/');	getline(sub2, month1, '/');	getline(sub2, year1);
	dDay = stoi(day1, nullptr, 10);
	dmonth = stoi(month1, nullptr, 10);
	dyear = stoi(year1, nullptr, 10);
	if (!(_stricmp(subscriber.getsubsriberTYPE().c_str(), "regular")))
	{
		duedate = dayafteraddingdays(dDay, dmonth, dyear, 7);//seven days for regular 1 week
	}
	if (!(_stricmp(subscriber.getsubsriberTYPE().c_str(), "golden")))
	{
		duedate = dayafteraddingdays(dDay, dmonth, dyear, 21);//21 days for golden 3 week
	}
	stringstream sub3;
	sub3 << duedate;
	getline(sub3, day1, '/'); getline(sub3, month1, '/'); getline(sub3, year1);
	dDay = stoi(day1, nullptr, 10);
	dmonth = stoi(month1, nullptr, 10);
	dyear = stoi(year1, nullptr, 10);
	static int increment[12] = { 1, -2, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 };
	int daysInc = 0;
	if (Rday - dDay < 0)
	{
		int month = Rmonth - 2; // -1 from zero, -1 previous month.
		if (month < 0)
			month = 11; // Previous month is December.
		daysInc = increment[month];
		if ((month == 1) && (Ryear % 4 == 0))
			daysInc++; // Increment days for leap year.
	}
	int total1 = dyear * 360 + dmonth * 30 + dDay;
	int total2 = Ryear * 360 + Rmonth * 30 + Rday;
	int diff = total2 - total1;
	int years = diff / 360;
	int months = (diff - years * 360) / 30;
	int days = diff - years * 360 - months * 30 + daysInc;
	if (days < 0)
	{
		return 0;
	}
	return (days * 5);
}
int borrowingrecord::finecalcculation(int item_id)
{
	string day1, month1, year1;
	int dyear, dmonth, dDay, Ryear,Rmonth,Rday;
	stringstream sub;
	string data = getsubscriberid() + "," + std::to_string(item_id);
	sub<< this->returndates[data];
	getline(sub, day1, '/'); getline(sub, month1, '/'); getline(sub, year1);
	Rday = stoi(day1,nullptr,10);
	Rmonth = stoi(month1, nullptr, 10);
	Ryear = stoi(year1, nullptr, 10);
	stringstream sub2;
	string duedate;
	string data3 = getsubscriberid() + "," + std::to_string(item_id);
	sub2 << this->borrow_dates[data3];
	getline(sub2, day1, '/');	getline(sub2, month1, '/');	getline(sub2, year1);
	dDay = stoi(day1, nullptr, 10);
	dmonth= stoi(month1, nullptr, 10);
	dyear= stoi(year1, nullptr, 10);
	if (!(_stricmp(subscriber.getsubsriberTYPE().c_str(), "regular")))
	{
		duedate = dayafteraddingdays(dDay, dmonth,dyear, 7);//seven days for regular 1 week
	}
	if (!(_stricmp(subscriber.getsubsriberTYPE().c_str(), "golden")))
	{
		duedate = dayafteraddingdays(dDay, dmonth,dyear, 21);//21 days for golden 3 week
	}
	stringstream sub3;
	sub3 << duedate;
	getline(sub3, day1, '/'); getline(sub3, month1, '/'); getline(sub3, year1);
	dDay= stoi(day1, nullptr, 10);
	dmonth= stoi(month1, nullptr, 10);
	dyear= stoi(year1, nullptr, 10);
	static int increment[12] = { 1, -2, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 };
	int daysInc = 0;
	if (Rday - dDay < 0)
	{
		int month = Rmonth - 2; // -1 from zero, -1 previous month.
		if (month < 0)
			month = 11; // Previous month is December.
		daysInc = increment[month];
		if ((month == 1) && (Ryear % 4 == 0))
			daysInc++; // Increment days for leap year.
	}
	int total1 = dyear * 360 + dmonth * 30 + dDay;
	int total2 = Ryear * 360 + Rmonth * 30 + Rday;
	int diff = total2 - total1;
	int years = diff / 360;
	int months = (diff - years * 360) / 30;
	int days = diff - years * 360 - months * 30 + daysInc;
	if (days<0)
	{
		return 0;
	}
	return (days * 5);	
}
/// Add specified number of days to date
string borrowingrecord::dayafteraddingdays(int day, int month, int year, int add)
{
	// Maximum days in the month
	int nMaxDays(MaxDayInMonth[month] + (month == 2 && isleapyear(year) ? 1 : 0));
	// Initialize the Year, Month, Days
	int nYear(year);
	int nMonth(month);
	int nDays(day + add);
	// Iterate till it becomes a valid day of a month
	while (nDays > nMaxDays) {
		// Subtract the max number of days of current month
		nDays -= nMaxDays;
		++nMonth;
		//  next year
		if (nMonth > 12) {
			nMonth = 1; // January
			++nYear;
		}

		// Update the max days of the new month
		nMaxDays = MaxDayInMonth[nMonth] + (nMonth == 2 && isleapyear(nYear) ? 1 : 0);
	}
	
	// Construct date
	string date = std::to_string(nDays) + "/" + std::to_string(nMonth) + "/" + std::to_string(nYear);
	return date;
}

borrowingrecord borrowingrecord::setsubscriber(string subscriber_ID, string Type, string Name, string Address, string Phone, string Email)
{
	subscriber.setsubscriber(subscriber_ID, Type, Name, Address, Phone, Email);
	return *this;
}
void borrowingrecord::setborrowdate(int itemid , string date)
{
	string data = getsubscriberid()+","+std::to_string(itemid);
	this->borrow_dates[data] = date;
}
string borrowingrecord::getborrowdate(int item_id)
{
	string data = getsubscriberid() + "," + std::to_string(item_id);
	return this->borrow_dates[data];
}

string borrowingrecord::getreturndate(int item_id)
{
	string data = getsubscriberid() + "," + std::to_string(item_id);
	auto it=this->returndates.find(data);
	if (it!=returndates.end())
	{
		return this->returndates[data];
	}
	return "----";
}
void borrowingrecord::setreturndate(int itemid,string date)
{	
	string data = getsubscriberid() + "," + std::to_string(itemid);
	this->returndates[data] = date;
}
int borrowingrecord::findbook(string title, string author)
{

	for (auto it=lib.begin();it!=lib.end(); it++)
	{
		if (it->findbook(title, author) != 0)
		{
		         	
				time_t t = time(NULL);//to use system date 
				struct tm toget;
				localtime_s(&toget, &t);
				int day, month, year;
				day = toget.tm_mday;
				month = toget.tm_mon + 1;
				year = toget.tm_year + 1900;
				string date = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
				setreturndate((it->findbook(title, author)),date);
				int x = finecalcculation(it->findbook(title, author));
				setfine(it->findbook(title, author), x);
				cout << "FINE IS " << x << "Rs\n";
				return it->findbook(title, author);	
			break;
		}
	}
	return 0;
}
int borrowingrecord::finddigitalmedia(string title, string author)
{
	for (auto it=lib.begin();it!=lib.end();it++)
	{
		if (it->finddigitalmedia(title, author) != 0)
		{
			if (getreturndate((it->finddigitalmedia(title, author))) == "----")
			{
				time_t t = time(NULL);//to use system date 
				struct tm toget;
				localtime_s(&toget, &t);
				int day, month, year;
				day = toget.tm_mday;
				month = toget.tm_mon + 1;
				year = toget.tm_year + 1900;
				string date = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
				setreturndate((it->finddigitalmedia(title, author)),date);
				int x = finecalcculation(it->finddigitalmedia(title, author));
				setfine(it->finddigitalmedia(title, author), x);
				cout << "FINE IS " << x << "Rs\n";
				return it->finddigitalmedia(title, author);
			}
			else
			{
				cout << "THIS DIGITAL MEDIA IS ALREADY RETURN\n";
				return it->finddigitalmedia(title, author);
			}
			break;
		}
	}
	return 0;
}
int borrowingrecord::findarticle(string title, string author)
{
	for (auto it = lib.begin(); it != lib.end(); it++)
	{
		if (it->findarticle(title, author) != 0)
		{
				time_t t = time(NULL);//to use system date 
				struct tm toget;
				localtime_s(&toget, &t);
				int day, month, year;
				day = toget.tm_mday;
				month = toget.tm_mon + 1;
				year = toget.tm_year + 1900;
				string date = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
				setreturndate((it->findarticle(title, author)),date);
				int x = finecalcculation(it->findarticle(title, author));
				cout << "FINE IS " << x << "Rs\n";
				setfine((it->findarticle(title, author)), x);
				return it->findarticle(title, author);
			    break;
		}
	}
	return 0;
}
