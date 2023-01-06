// project.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include"articles.h"
#include"books.h"
#include"digitalmedia.h"
#include"contents.h"
#include"subscribers.h"
#include"borrowingrecord.h"
#include"library.h"
#include<map>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void loadborrowfile();
void loadsubscriberfile();
void loadlibrraryfile();
void loaditemsfile();
void updatebookinborrow(books);
void updatedigitalinborrow(digitalmedia);
void updatearticleinborrow(articles);
void increase(int);
void deletebookinborrow(int);
void deletearticleinborrow(int);
void deletedigitalmediainborrow(int);
void uniquekey(int itemid);
void edilibraryinborrow(string, string, string, string);
void deletelibraryinborrow(string, string);
void saveinfile();
string isValidPublisher(string pub);
string isValidProductionYear(string);
string isValidCopies(string);
string isValidAuthor(string auth);
string isValidSubscriberType(string stype);
string isValidSubscriberName(string sname);
string isValidSubscriberPhone(string pNo);
string isValidSubscriberEmail(string semail);
string isValidLibraryId(string id);
string isValidSubscriberid(string id);
int global_iteamid = 1;
vector<library> lib;
vector<subscribers>sub;
vector<borrowingrecord> borrow;
int main()
{
    loadlibrraryfile();
    loaditemsfile();
    loadsubscriberfile();
    loadborrowfile();
    int choice;
    do
    {
        cout << "press 1 to add library \n";
        cout << "press 2 to add subscriber \n";
        cout << "press 3 to add book item \n";
        cout << "press 4 to add article item \n";
        cout << "press 5 to add digital media item \n";
        cout << "press 6 to edit library\n";
        cout << "press 7 to edit subscriber\n";
        cout << "press 8 to edit book\n";
        cout << "press 9 to edit article\n";
        cout << "press 10 to edit digital media\n";
        cout << "press 11 to delete library\n";
        cout << "press 12 to delete subscriber\n";
        cout << "press 13 to delete book\n";
        cout << "press 14 to delete article\n";
        cout << "press 15 to delete digital media\n";
        cout << "press 16 to borrow item\n";
        cout << "press 17 to return borrow item\n";
        cout << "press 18 to view overdue borrowed items\n";
        cout << "press 19 to end\n";
        cin >> choice;
        if (choice == 1)
        {
            cin.ignore();
            string libraryid,
                name;
            cout << "Please enter the Library information in the following format \n LIBRARY_ID,LIBRARY_NAME\nEnter Input :";
            getline(cin, libraryid, ',');
            getline(cin, name, '\n');
            libraryid = isValidLibraryId(libraryid);
            bool x = 0;
            for (auto it : lib)
            {
                if (it.getlibraryid() == libraryid)
                {
                    x = 1;
                    break;
                }
            }
            if (x == 0)
            {
                lib.emplace_back(libraryid, name);
            }
            else
            {
                cout << "ALREADY LIBRARY EXIST WITH GIVEN ID\n";

            }

        }
        if (choice == 2)
        {

            cin.ignore();
            cout << "Please enter the Subscriber information in the following format \n SUBSCRIBER_ID,SUBSCRIBER_TYPE,SUBSCRIBER_NAME,SUBSCRIBER_ADDRESS,SUBSCRIBER_PHONE_NO,SUBSCRIBER_EMAIL\nEnter Input :";
            string subscriber_ID, Type, Name, Address, Phone, Email;
            getline(cin, subscriber_ID, ',');
            getline(cin, Type, ',');
            getline(cin, Name, ',');
            getline(cin, Address, ',');
            getline(cin, Phone, ',');
            getline(cin, Email, '\n');
            subscriber_ID = isValidSubscriberid(subscriber_ID);
            bool x = 0;
            for (auto it : sub)
            {
                if (it.getsubsriberid() == subscriber_ID)
                {
                    x = 1;
                    break;
                }
            }
            if (x == 0)
            {
                sub.emplace_back(subscriber_ID, Type, Name, Address, Phone, Email);
            }
            else
            {
                cout << "ALREADY SUBSCRIBER EXIST WITH THIS " << subscriber_ID << " ID\n";
            }

        }
        if (choice == 3)
        {
            cin.ignore();
            string libraryid, name;
            string title, author, publisher, status,
                production_year, copies;
            cout << "Please enter the BOOK ITEM  information in the following format \n LIBRARY_ID,LIBRARY_NAME,BOOK_TITLE,BOOK_AUTHOR,BOOK_PUBLISHER,BOOK_STATUS,BOOK_PRODUCTION_YEAR,BOOK_COPIES\nEnter Input :";
            getline(cin, libraryid, ',');
            getline(cin, name, ',');
            getline(cin, title, ',');
            getline(cin, author, ',');
            getline(cin, publisher, ',');
            getline(cin, status, ',');
            getline(cin, production_year, ',');
            getline(cin, copies, '\n');
            libraryid = isValidLibraryId(libraryid);
            author = isValidAuthor(author);
            publisher = isValidPublisher(publisher);
            production_year = isValidProductionYear(production_year);
            copies = isValidCopies(copies);
            auto it = find(lib.begin(), lib.end(), library(libraryid, name));
            if (it != lib.end())
            {
                it->setbook({ title, author, publisher, stoi(production_year, nullptr, 10), stoi(copies, nullptr, 10), status,global_iteamid });
                global_iteamid += 1;
            }
            else
            {
                cout << "NO LIBRARY FOUND WITH THIS " << libraryid << " ID FIRST ADD LIBRARY THAN BOOK\n";
            }
        }
        if (choice == 4)
        {
            cin.ignore();
            string libraryid, name;
            string title, author, publisher, status,
                production_year, copies;
            cout << "Please enter the ARTICLE ITEM  information in the following format \nLIBRARY_ID,LIBRARY_NAME,ARTICLE_TITLE,ARTICLE_AUTHOR,ARTICLE_PUBLISHER,ARTICLE_STATUS,ARTICLE_PRODUCTION_YEAR,ARTICLE_COPIES\nEnter Input :";
            getline(cin, libraryid, ',');
            getline(cin, name, ',');
            getline(cin, title, ',');
            getline(cin, author, ',');
            getline(cin, publisher, ',');
            getline(cin, status, ',');
            getline(cin, production_year, ',');
            getline(cin, copies, '\n');
            libraryid = isValidLibraryId(libraryid);
            author = isValidAuthor(author);
            publisher = isValidPublisher(publisher);
            production_year = isValidProductionYear(production_year);
            copies = isValidCopies(copies);
            auto it = find(lib.begin(), lib.end(), library(libraryid, name));
            if (it != lib.end())
            {
                it->setarticle({ title, author, publisher, status, stoi(production_year, nullptr, 10), stoi(copies, nullptr, 10),global_iteamid });
                global_iteamid += 1;
            }
            else
            {
                cout << "NO LIBRARY FOUND WITH THIS " << libraryid << " ID FIRST ADD LIBRARY THAN ARTICLE\n";
            }
        }
        if (choice == 5)
        {
            cin.ignore();
            string libraryid, name;
            string title, author, publisher, status,
                production_year, copies;
            cout << "Please enter the DIGITALMEDIA ITEM  information in the following format \nLIBRARY_ID,LIBRARY_NAME,DIGITALMEDIA_TITLE,DIGITALMEDIA_AUTHOR,DIGITALMEDIA_PUBLISHER,DIGITALMEDIA_STATUS,DIGITALMEDIA_PRODUCTION_YEAR,DIGITALMEDIA_COPIES\nEnter Input :";
            getline(cin, libraryid, ',');
            getline(cin, name, ',');
            getline(cin, title, ',');
            getline(cin, author, ',');
            getline(cin, publisher, ',');
            getline(cin, status, ',');
            getline(cin, production_year, ',');
            getline(cin, copies, '\n');
            libraryid = isValidLibraryId(libraryid);
            author = isValidAuthor(author);
            publisher = isValidPublisher(publisher);
            production_year = isValidProductionYear(production_year);
            copies = isValidCopies(copies);
            auto it = find(lib.begin(), lib.end(), library(libraryid, name));
            if (it != lib.end())
            {
                it->setdigitalmedia({ title, author, publisher, stoi(production_year, nullptr, 10), status, stoi(copies, nullptr, 10),global_iteamid });
                global_iteamid += 1;
            }
            else
            {
                cout << "NO LIBRARY FOUND WITH THIS " << libraryid << " ID FIRST ADD LIBRARY THAN DIGITALMEDIA\n";
            }
        }
        if (choice == 6)
        {
            cin.ignore();
            string libraryid,
                name;
            cout << "Please enter the Library information in the following format \n LIBRARY_ID,LIBRARY_NAME\nEnter Input :";
            getline(cin, libraryid, ',');
            getline(cin, name, '\n');
            libraryid = isValidLibraryId(libraryid);
            bool x = 0;
            auto it = find(lib.begin(), lib.end(), library(libraryid, name));
            if (it != lib.end())
            {
                string id, n;
                cout << "YOUR ENTERED LIBRARY IS FOUND ENTER INFORMATION IN FOLLOWING FORMAT\n";
                cout << "LIBRARY_ID,LIBRARY_NAME\nEnter Input :";
                getline(cin, id, ','); getline(cin, n, '\n');
                id = isValidLibraryId(id);
                it->setlibrary(id, n);
                edilibraryinborrow(libraryid, name, id, n);
            }
            else
            {
                cout << "NO LIBRARY EXIST WITH GIVEN INFO\n";
            }
        }
        if (choice == 7)
        {
            cin.ignore();
            cout << "ENTER SUBSCRIBER INFORMATION IN THE FOLLOWING FORMAT \n SUBSCRIBER_ID,SUBSCRIBER_NAME\nEnter Input :";
            string subscriber_id, name;
            getline(cin, subscriber_id, ','); getline(cin, name, '\n');
            subscriber_id = isValidLibraryId(subscriber_id);
            name = isValidSubscriberName(name);
            auto it = find(sub.begin(), sub.end(), subscribers(subscriber_id, name));
            if (it != sub.end())
            {
                cout << "Your entered subscriber is found now enter information in the following format to edit \n SUBSCRIBER_ID,SUBSCRIBER_TYPE,SUBSCRIBER_NAME,SUBSCRIBER_ADDRESS,SUBSCRIBER_PHONE_NO,SUBSCRIBER_EMAIL\nEnter Input :";
                string subscriber_ID, Type, Name, Address, Phone, Email;
                getline(cin, subscriber_ID, ',');
                getline(cin, Type, ',');
                getline(cin, Name, ',');
                getline(cin, Address, ',');
                getline(cin, Phone, ',');
                getline(cin, Email, '\n');
                subscriber_ID = isValidSubscriberid(subscriber_ID);
                Type = isValidSubscriberType(Type);
                Name = isValidSubscriberName(Name);
                Phone = isValidSubscriberPhone(Phone);
                Email = isValidSubscriberEmail(Email);
                bool x = 0;
                for (auto it = sub.begin(); it != sub.end(); it++)
                {
                    if (it->getsubsriberid() == subscriber_ID && it->getsubsriberid() != subscriber_id)
                    {
                        x = 1;
                        break;
                    }
                }
                if (x == 0)
                {

                    it->setsubscriber(subscriber_ID, Type, Name, Address, Phone, Email);
                    for (auto it2 = borrow.begin(); it2 != borrow.end(); it2++)
                    {
                        if (!(_stricmp(name.c_str(), it2->getsubscribername().c_str())) && !(_stricmp(subscriber_id.c_str(), it2->getsubscriberid().c_str())))
                        {
                            it2->setsubscriber(subscriber_ID, Type, Name, Address, Phone, Email);
                        }
                    }
                }
                else
                {
                    cout << "ALREADY SUBSCRIBER EXIST WITH THIS " << subscriber_ID << " ID\n";
                }
            }
            else
            {
                cout << "NO SUBSCRIBER EXIST WITH THIS " << subscriber_id << " ID\n";
            }
        }
        if (choice == 8)
        {
            cin.ignore();
            string author, bookname;
            bool flag = 0;
            cout << "enter book name and authorin following format\n";
            cout << "BOOK Title,BOOK AUTHOR\n";
            getline(cin, bookname, ','); getline(cin, author, '\n');
            author = isValidAuthor(author);
            for (auto it = lib.begin(); it != lib.end(); it++)
            {
                if (it->findbook(bookname, author) != 0)
                {
                    flag = 1;
                    int itemid = it->findbook(bookname, author);
                    cout << "Your entered book is found \n";
                    string title, author, publisher, status,
                        production_year, copies;
                    cout << "Please enter the BOOK ITEM  information in the following format \n BOOK_TITLE,BOOK_AUTHOR,BOOK_PUBLISHER,BOOK_STATUS,BOOK_PRODUCTION_YEAR,BOOK_COPIES\nEnter Input :";
                    getline(cin, title, ',');
                    getline(cin, author, ',');
                    getline(cin, publisher, ',');
                    getline(cin, status, ',');
                    getline(cin, production_year, ',');
                    getline(cin, copies, '\n');
                    author = isValidAuthor(author);
                    publisher = isValidPublisher(publisher);
                    production_year = isValidProductionYear(production_year);
                    copies = isValidCopies(copies);
                    it->editbook({ title,author,publisher,stoi(production_year,nullptr,10),stoi(copies,nullptr,10),status,itemid });
                    updatebookinborrow({ title,author,publisher,stoi(production_year,nullptr,10),stoi(copies,nullptr,10),status,itemid });
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "NO BOOK EXIST WITH GIVEN INFO\n";
            }
        }
        if (choice == 9)
        {
            cin.ignore();
            bool flag = 0;
            string author, bookname;
            cout << "enter Article name and author in following format\n";
            cout << "Article Title,Article AUTHOR\n";
            getline(cin, bookname, ','); getline(cin, author, '\n');
            author = isValidAuthor(author);
            for (auto it = lib.begin(); it != lib.end(); it++)
            {
                if (it->findarticle(bookname, author) != 0)
                {
                    flag = 1;
                    int itemid = it->findarticle(bookname, author);
                    cout << "Your entered Article is found \n";
                    string title, author, publisher, status,
                        production_year, copies;
                    cout << "Please enter the ARTICLE ITEM  information in the following format \nARTICLE_TITLE,ARTICLE_AUTHOR,ARTICLE_PUBLISHER,ARTICLE_STATUS,ARTICLE_PRODUCTION_YEAR,ARTICLE_COPIES\nEnter Input :";
                    getline(cin, title, ',');
                    getline(cin, author, ',');
                    getline(cin, publisher, ',');
                    getline(cin, status, ',');
                    getline(cin, production_year, ',');
                    getline(cin, copies, '\n');
                    author = isValidAuthor(author);
                    publisher = isValidPublisher(publisher);
                    production_year = isValidProductionYear(production_year);
                    copies = isValidCopies(copies);
                    it->editarticle({ title,author,publisher,status,stoi(production_year,nullptr,10),stoi(copies,nullptr,10),itemid });
                    updatearticleinborrow({ title,author,publisher,status,stoi(production_year,nullptr,10),stoi(copies,nullptr,10),itemid });
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "NO ARTICLE EXIST WITH GIVEN INFO\n";
            }
        }
        if (choice == 10)
        {
            cin.ignore();
            bool flag = 0;
            string author, bookname;
            cout << "enter DIGITAL MEDIA name and author in following format\n";
            cout << "DIGITALMEDIA Title,DIGITAL MEDIA AUTHOR\n";
            getline(cin, bookname, ','); getline(cin, author, '\n');
            author = isValidAuthor(author);
            for (auto it = lib.begin(); it != lib.end(); it++)
            {
                if (it->finddigitalmedia(bookname, author) != 0)
                {
                    flag = 1;
                    int itemid = it->finddigitalmedia(bookname, author);
                    cout << "Your entered DIGITAL MEDIA is found \n";
                    string title, author, publisher, status,
                        production_year, copies;
                    cout << "Please enter the DIGITAL MEDIA ITEM  information in the following format \DIGITAL_TITLE,DIGITAL_AUTHOR,DIGITAL_PUBLISHER,DIGITAL_STATUS,DIGITAL_PRODUCTION_YEAR,DIGITAL_COPIES\nEnter Input :";
                    getline(cin, title, ',');
                    getline(cin, author, ',');
                    getline(cin, publisher, ',');
                    getline(cin, status, ',');
                    getline(cin, production_year, ',');
                    getline(cin, copies, '\n');
                    author = isValidAuthor(author);
                    publisher = isValidPublisher(publisher);
                    production_year = isValidProductionYear(production_year);
                    copies = isValidCopies(copies);
                    it->editdigital({ title,author,publisher,stoi(production_year,nullptr,10),status,stoi(copies,nullptr,10),itemid });
                    updatedigitalinborrow({ title,author,publisher,stoi(production_year,nullptr,10),status,stoi(copies,nullptr,10),itemid });
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "NO DIGITAL MEDIA ITEM EXIST WITH GIVEN INFO\n";
            }
        }
        if (choice == 11)
        {
            cin.ignore();
            string libraryid,
                name;
            cout << "Please enter the Library information in the following format \n LIBRARY_ID,LIBRARY_NAME\nEnter Input :";
            getline(cin, libraryid, ',');
            getline(cin, name, '\n');
            libraryid = isValidLibraryId(libraryid);
            bool x = 0;
            auto it = find(lib.begin(), lib.end(), library(libraryid, name));
            if (it != lib.end())
            {
                lib.erase(it);
                deletelibraryinborrow(libraryid, name);
            }
            else
            {
                cout << "NO LIBRARY EXIST WITH GIVEN INFO\n";
            }
            saveinfile();
            global_iteamid = 1;
            lib.clear();
            sub.clear();
            borrow.clear();
            loadlibrraryfile();
            loaditemsfile();
            loadsubscriberfile();
            loadborrowfile();
        }
        if (choice == 12)
        {
            cin.ignore();
            cout << "ENTER SUBSCRIBER INFORMATION IN THE FOLLOWING FORMAT \n SUBSCRIBER_ID,SUBSCRIBER_NAME\nEnter Input :";
            string subscriber_id, name;
            getline(cin, subscriber_id, ','); getline(cin, name, '\n');
            subscriber_id = isValidSubscriberid(subscriber_id);
            name = isValidSubscriberName(name);
            auto it = find(sub.begin(), sub.end(), subscribers(subscriber_id, name));
            if (it != sub.end())
            {
                for (auto it2 = borrow.begin(); it2 != borrow.end(); it2++)
                {
                    if (!(_stricmp(name.c_str(), it2->getsubscribername().c_str())) && !(_stricmp(subscriber_id.c_str(), it2->getsubscriberid().c_str())))
                    {
                        borrow.erase(it2);
                        break;
                    }
                }
                sub.erase(it);
            }
            else
            {
                cout << "no subscriber exist with given id name\n";
            }
        }
        if (choice == 13)
        {
            cin.ignore();
            string author, bookname;
            bool flag = 0;
            cout << "enter book name and authorin following format\n";
            cout << "BOOK Title,BOOK AUTHOR\n";
            getline(cin, bookname, ','); getline(cin, author, '\n');
            isValidAuthor(author);
            for (auto it = lib.begin(); it != lib.end(); it++)
            {
                if (it->findbook(bookname, author) != 0)
                {
                    flag = 1;
                    int item_id = it->findbook(bookname, author);
                    it->deletecontentitem(item_id);
                    deletebookinborrow(item_id);
                    global_iteamid = global_iteamid - 1;
                    uniquekey(item_id);
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "NO BOOK EXIST WITH GIVEN INFO\n";
            }
        }
        if (choice == 14)
        {
            cin.ignore();
            string author, bookname;
            bool flag = 0;
            cout << "enter Article name and author in following format\n";
            cout << "Article Title,Article AUTHOR\n";
            getline(cin, bookname, ','); getline(cin, author, '\n');
            author = isValidAuthor(author);
            for (auto it = lib.begin(); it != lib.end(); it++)
            {
                if (it->findarticle(bookname, author) != 0)
                {
                    flag = 1;
                    int item_id = it->findarticle(bookname, author);
                    it->deletecontentitem(item_id);
                    deletearticleinborrow(item_id);
                    global_iteamid = global_iteamid - 1;
                    uniquekey(item_id);
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "NO ARTICLE EXIST WITH GIVEN INFO\n";
            }
        }
        if (choice == 15)
        {
            cin.ignore();
            string author, bookname;
            bool flag = 0;
            cout << "enter DigitalMEDIA name and author in following format\n";
            cout << "DigitalMEDIA Title,DIGITALMEDIA AUTHOR\n";
            getline(cin, bookname, ','); getline(cin, author, '\n');
            author = isValidAuthor(author);
            for (auto it = lib.begin(); it != lib.end(); it++)
            {
                if (it->finddigitalmedia(bookname, author) != 0)
                {
                    flag = 1;
                    int item_id = it->finddigitalmedia(bookname, author);
                    it->deletecontentitem(item_id);
                    deletedigitalmediainborrow(item_id);
                    global_iteamid = global_iteamid - 1;
                    uniquekey(item_id);
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "NO DIGITAL EXIST WITH GIVEN INFO\n";
            }
        }
        if (choice == 16)
        {
            cin.ignore();
            cout << "TO SEE ITEM LIST FIRST ENTER SUBSCRIBER INFORMATION IN THE FOLLOWING FORMAT \n SUBSCRIBER_ID,SUBSCRIBER_NAME\nEnter Input :";
            string subscriber_ID, Name;
            getline(cin, subscriber_ID, ',');
            getline(cin, Name, '\n');
            subscriber_ID = isValidSubscriberid(subscriber_ID);
            auto it = find(sub.begin(), sub.end(), subscribers(subscriber_ID, Name));
            sort(lib.begin(), lib.end());
            map<int, library> search;
            int i = 1;
            if (it != sub.end())
            {
                string data;
                for (auto it2 : lib)

                {

                    stringstream sub2;
                    sub2 << it2.sptostring();
                    while (getline(sub2, data, '\n'))
                    {
                        stringstream sub3;
                        sub3 << data;
                        string title, catagory,
                            author,
                            publisher,
                            status,
                            production_year,
                            copies,
                            item_id;
                        getline(sub3, item_id, ','); getline(sub3, catagory, ',');	getline(sub3, title, ',');	getline(sub3, author, ',');	getline(sub3, publisher, ','), getline(sub3, production_year, ',');	getline(sub3, status, ',');	getline(sub3, copies, '\n');
                        if (catagory == "book")
                        {
                            search[i] = library(it2.getlibraryid(), it2.getlibrartname(), { title, author, publisher, stoi(production_year, nullptr, 10), stoi(copies, nullptr, 10), status, stoi(item_id, nullptr, 10) });
                            i = i + 1;
                        }
                        if (catagory == "article")
                        {
                            search[i] = library(it2.getlibraryid(), it2.getlibrartname(), { title, author, publisher, status, stoi(production_year, nullptr, 10), stoi(copies, nullptr, 10), stoi(item_id, nullptr, 10) });
                            i = i + 1;
                        }
                        if (catagory == "digital media")
                        {
                            search[i] = library(it2.getlibraryid(), it2.getlibrartname(), { title, author, publisher, stoi(production_year, nullptr, 10), status, stoi(copies, nullptr, 10), stoi(item_id, nullptr, 10) });
                            i = i + 1;
                        }

                    }


                }
                int y = 0;
                cout << setw(12) << left << "Sr" << setw(19) << left << "LibraryID" << setw(12) << left << "Item ID" << setw(17) << left << "Category" << setw(31) << left << " Title" << setw(15) << left << " Author" << setw(19) << left << " Publisher" << setw(18) << left << "ProductionYear" << setw(19) << left << " Status" << "Copies\n";
                for (auto it2 : lib)
                {
                    it2.sortinfo();
                    stringstream sub;
                    sub << it2.tostring();
                    while (getline(sub, data, '\n'))
                    {
                        y = y + 1;
                        cout << setw(12) << left << y << setw(19) << left << it2.getlibraryid() << data << endl;
                    }

                }
                string choice;
                cout << "enter choices seperated by comma\n";
                getline(cin, choice, '\n');
                choice += ',';
                stringstream alpha;
                alpha << choice;
                borrowingrecord cu;
                auto it = find(sub.begin(), sub.end(), subscribers(subscriber_ID, Name));
                while (getline(alpha, choice, ','))
                {
                    auto it5 = search.find(stoi(choice, nullptr, 10));
                    if (it5 != search.end())
                    {
                        bool y = 0;
                        it5->second;
                        auto it6 = find(lib.begin(), lib.end(), library(it5->second.getlibraryid(), it5->second.getlibrartname()));
                        bool x = it6->equal(it5->second.sptostring());
                        if (x == 1)
                        {

                            search.at(stoi(choice, nullptr, 10)).equal(search.at(stoi(choice, nullptr, 10)).sptostring());
                            cu.set({ it->getsubsriberid(),it->getsubsriberTYPE(),it->getsubscriberNAME(),it->getsubscriberaddress(),it->getsubscriberPHONE(),it->getsubscriberEMAIL() }, search.at(stoi(choice, nullptr, 10)));
                        }
                        else if (x == 0)
                        {
                            cout << "sorry there is no copy of this :" << choice << "Sr\n";
                        }

                    }
                    else
                    {
                        cout << "this " << choice << "choice is not in Sr\n";
                    }
                }
                borrow.push_back(cu);
            }

            else
            {
                cout << "NO SUBSCRIBER EXIST WITH THIS" << subscriber_ID << " ID\n";

            }
        }
        if (choice == 17)
        {
            cin.ignore();
            saveinfile();
            global_iteamid = 1;
            lib.clear();
            sub.clear();
            borrow.clear();
            loadlibrraryfile();
            loaditemsfile();
            loadsubscriberfile();
            loadborrowfile();
            stringstream sub2;
            cout << "ENTER INFORMATION IN THE FOLLOWING FORMAT \n SUBSCRIBER_ID,SUBSCRIBER_NAME\nEnter Input :";
            string subscriber_id, name;
            getline(cin, subscriber_id, ','); getline(cin, name, '\n');
            subscriber_id = isValidSubscriberid(subscriber_id);
            name = isValidSubscriberName(name);
            auto it = find(sub.begin(), sub.end(), subscribers(subscriber_id, name));
            bool x = 0;
            if (it != sub.end())
            {
                char ch;
                cout << "Press A for return Article\n";
                cout << "Press B for return BOOK\n";
                cout << "Press D for return digitalmedia item\n";
                cin.get(ch);
                cin.ignore();
                if (toupper(ch) == 'A')
                {
                    int update = 0;
                    string author, bookname;
                    cout << "enter Article Title and Article author in following format\n";
                    cout << "Article Title,Article AUTHOR\n";
                    getline(cin, bookname, ','); getline(cin, author, '\n');
                    author = isValidAuthor(author);
                    for (auto it = borrow.begin(); it != borrow.end(); it++)
                    {
                        if (it->getsubscriberid() == subscriber_id && !(_stricmp(it->getsubscribername().c_str(), name.c_str())))
                        {

                            int x = it->findarticle(bookname, author);
                            if (x == 0)
                            {
                                cout << "THIS SUBSCRIBER DO NOT BORROW GIVEN ARTCLE\n";
                            }
                            if (x != 0)
                            {
                                update = x;
                            }

                            break;
                        }
                    }

                    if (update != 0) { increase(update); };
                }
                if (toupper(ch) == 'B')
                {
                    int update = 0;
                    string author, bookname;
                    cout << "enter book name and authorin following format\n";
                    cout << "BOOK Title,BOOK AUTHOR\n";
                    getline(cin, bookname, ','); getline(cin, author, '\n');
                    author = isValidAuthor(author);
                    for (auto it = borrow.begin(); it != borrow.end(); it++)
                    {
                        if (it->getsubscriberid() == subscriber_id && !(_stricmp(it->getsubscribername().c_str(), name.c_str())))
                        {

                            int x = it->findbook(bookname, author);
                            if (x == 0)
                            {
                                cout << "THIS SUBSCRIBER DO NOT BORROW GIVEN BOOK\n";
                            }
                            if (x != 0)
                            {
                                update = x;
                            }

                            break;
                        }
                    }

                    if (update != 0) { increase(update); };

                }
                if (toupper(ch) == 'D')
                {
                    int update = 0;
                    string author, bookname;
                    cout << "enter Digital media Title and author in following format\n";
                    cout << "DIGITAL MEDIA Title ,DIGITAL MEDIA AUTHOR\n";
                    getline(cin, bookname, ','); getline(cin, author, '\n');
                    author = isValidAuthor(author);
                    for (auto it = borrow.begin(); it != borrow.end(); it++)
                    {
                        if (it->getsubscriberid() == subscriber_id && !(_stricmp(it->getsubscribername().c_str(), name.c_str())))
                        {

                            int x = it->finddigitalmedia(bookname, author);
                            if (x == 0)
                            {
                                cout << "THIS SUBSCRIBER DO NOT BORROW GIVEN DIGITALMEDIA\n";
                            }
                            if (x != 0)
                            {
                                update = x;
                            }
                            break;
                        }
                    }
                    if (update != 0) { increase(update); };


                }

            }
            else
            {
                cout << "NO SUBSCRIBER EXIST WITH GIVEN NAME ID\n";
            }
        }
        if (choice == 18)
        {
            cin.ignore();
            cout << "subscriber id" << "subscriber name" << "content id\n";
            string data;
            for (auto it = borrow.begin(); it != borrow.end(); it++)
            {
                string libraryid, librartname, itemid;
                stringstream sub;
                sub << it->getlibrarysptostring();
                while (getline(sub, data, '\n'))
                {
                    stringstream sub2;
                    sub2 << data;
                    getline(sub2, libraryid, ','); getline(sub2, librartname, ','); getline(sub2, itemid, ',');
                    if (it->getreturndate(stoi(itemid, nullptr, 10)) == "----")
                    {

                        if (it->finecalcculationforadminview(stoi(itemid, nullptr, 10)) != 0)
                        {
                            cout << setw(10) << left << it->getsubscriberid() << setw(10) << left << it->getsubscribername() << setw(10) << left << itemid << "\n";
                        }
                    }
                }

            }
        }
        if (!(choice >= 1 && choice <= 19))
        {
            cout << "ENTER CHOICES BETWEEN 1 to 19\n";
        }
    } while (choice != 19);
    fstream file;
    file.open("library.CSV", ios::out);
    file << "Library ID" << "," << "Name" << endl;
    cout << setw(20) << left << "Library ID" << "Name" << endl;
    sort(lib.begin(), lib.end());
    for (auto it : lib)
    {

        file << it.sptostring_library() << endl;
        cout << it.tostring_library() << endl;
    }
    file.close();
    fstream file2;
    fstream file3;
    file3.open("items.CSV", ios::out);
    file3 << "Item ID" << "," << "LibraryID" << "," << "Category" << "," << "Title" << "," << "Author" << "," "Publisher" << "," "Production_Year" << "," << "Status" << "," << " Copies\n";
    cout << setw(17) << left << "Item ID" << setw(19) << left << "LibraryID" << setw(18) << left << "Category" << setw(35) << left << "Title" << setw(16) << left << "Author" << setw(19) << left << "Publisher" << setw(20) << left << "Production_Year" << setw(16) << left << "Status" << " Copies\n";
    string data;
    sort(lib.begin(), lib.end());
    for (auto it = lib.begin(); it != lib.end(); it++)
    {
        it->sortinfo();
        stringstream sub;
        sub << it->sptostring();
        while (getline(sub, data, '\n'))
        {
            string Item_ID, Category, Title, Author, Publisher, prod_Year, Status, Copies;
            stringstream sub2;
            sub2 << data;
            getline(sub2, Item_ID, ','); getline(sub2, Category, ','); getline(sub2, Title, ','); getline(sub2, Author, ','); getline(sub2, Publisher, ','); getline(sub2, prod_Year, ','); getline(sub2, Status, ','); getline(sub2, Copies);
            cout << setw(17) << left << Item_ID << setw(19) << left << it->getlibraryid() << setw(18) << left << Category << setw(35) << left << Title << setw(16) << left << Author << setw(19) << left << Publisher << setw(20) << left << prod_Year << setw(18) << left << Status << Copies << "\n";
            file3 << Item_ID << "," << it->getlibraryid() << "," << Category << "," << Title << "," << Author << "," << Publisher << "," << prod_Year << "," << Status << "," << Copies << "\n";
        }

    }
    file3.close();
    fstream file4;
    file4.open("subscribers.CSV", ios::out);
    file4 << "Subscriber ID" << "," << "Type" << "," "Name" << "," << "Address" << "," << "Phone" << "," << "Email\n";
    cout << setw(23) << left << "Subscriber ID" << setw(14) << left << "Type" << setw(30) << left << "Name" << setw(30) << left << "Address" << setw(20) << left << "Phone" << "Email\n";
    sort(sub.begin(), sub.end());
    for (auto it : sub)
    {
        file4 << it.sptostring();
        cout << it.tostring() << endl;
    }
    file4.close();
    fstream file5;
    file5.open("borrowing.CSV", ios::out);
    file5 << "SUBSCRIBER ID" << "," << "Borrow Date" << "," << "content id" << "," << "Return Date" << "," << "Fee\n";
    cout << setw(20) << left << "SUBSCRIBER ID" << "Borrow Date" << "content id" << "Return Date" << "Fee\n";
    for (auto it : borrow)
    {
        file5 << it.sptostring();
        cout << it.tostring();
    }
    file5.close();
}
void increase(int itemid)
{
    for (auto it = lib.begin(); it != lib.end(); it++)
    {
        it->increscopies(itemid);
    }
}
void  updatebookinborrow(books that)
{
    for (auto it = borrow.begin(); it != borrow.end(); it++)
    {
        it->editbook(that);
    }
}
void  updatearticleinborrow(articles that)
{
    for (auto it = borrow.begin(); it != borrow.end(); it++)
    {
        it->editarticle(that);
    }
}
void  updatedigitalinborrow(digitalmedia that)
{
    for (auto it = borrow.begin(); it != borrow.end(); it++)
    {
        it->editdigitalmedia(that);
    }
}
void deletebookinborrow(int itemid)
{
    for (auto it = borrow.begin(); it != borrow.end(); it++)
    {
        it->deleteitem(itemid);
    }
}
void deletearticleinborrow(int itemid)
{
    for (auto it = borrow.begin(); it != borrow.end(); it++)
    {
        it->deleteitem(itemid);
    }
}
void deletedigitalmediainborrow(int itemid)
{
    for (auto it = borrow.begin(); it != borrow.end(); it++)
    {
        it->deleteitem(itemid);
    }
}
void uniquekey(int itemid)
{
    for (auto it = lib.begin(); it != lib.end(); it++)
    {
        it->uniquekey(itemid);

    }
    for (auto it = borrow.begin(); it != borrow.end(); it++)
    {
        it->uniquekey(itemid);
    }
}
void edilibraryinborrow(string findid, string findname, string replaceid, string replacename)
{
    for (auto it = borrow.begin(); it != borrow.end(); it++)
    {
        it->editlibray(findid, findname, replaceid, replacename);
    }
}
void deletelibraryinborrow(string itemid, string name)
{
    for (auto it = borrow.begin(); it != borrow.end(); it++)
    {
        it->deletelibrary(itemid, name);
    }
}
void loadlibrraryfile()
{
    fstream file;
    string record;
    file.open("library.CSV", ios::in);
    if (!(file.fail()))
    {
        bool x = 0;
        getline(file, record, '\n');
        while (file)
        {
            if (x == 1)
            {
                string id, name;
                stringstream data;
                data << record;
                getline(data, id, ','); getline(data, name);
                lib.emplace_back(id, name);
            }
            x = 1;
            getline(file, record, '\n');
        }
    }
    file.close();
}
void loaditemsfile()
{
    fstream file;
    string record;
    file.open("items.CSV", ios::in);
    if (!(file.fail()))
    {
        bool x = 0;
        getline(file, record, '\n');
        while (file)
        {
            if (x == 1)
            {
                global_iteamid = global_iteamid + 1;
                stringstream sub;
                sub << record;
                string ItemID, Library_ID, Category, Title, Author, Publisher, prod_Year, Status, Copies;
                getline(sub, ItemID, ','); getline(sub, Library_ID, ','); getline(sub, Category, ','); getline(sub, Title, ','); getline(sub, Author, ','); getline(sub, Publisher, ','); getline(sub, prod_Year, ','); getline(sub, Status, ','); getline(sub, Copies, '\n');
                for (auto it = lib.begin(); it != lib.end(); it++)
                {
                    if (it->getlibraryid() == Library_ID)
                    {
                        if (Category == "book")
                        {
                            it->setbook({ Title,Author,Publisher,stoi(prod_Year,nullptr,10),stoi(Copies,nullptr,10),Status,stoi(ItemID,nullptr,10) });
                        }
                        if (Category == "article")
                        {

                            it->setarticle({ Title,Author,Publisher,Status,stoi(prod_Year,nullptr,10),stoi(Copies,nullptr,10),stoi(ItemID,nullptr,10) });
                        }
                        if (Category == "digital media")
                        {

                            it->setdigitalmedia({ Title,Author,Publisher,stoi(prod_Year,nullptr,10),Status,stoi(Copies,nullptr,10),stoi(ItemID,nullptr,10) });
                        }
                    }
                }

            }
            x = 1;
            getline(file, record, '\n');
        }
    }
    file.close();
}
void loadsubscriberfile()
{
    string record;
    fstream file;
    file.open("subscribers.CSV", ios::in);
    if (!(file.fail()))
    {
        bool x = 0;
        getline(file, record, '\n');
        while (file)
        {
            if (x == 1)
            {
                string SubscriberID, Type, Name, Address, Phone, Email;
                stringstream sub2;
                sub2 << record;
                getline(sub2, SubscriberID, ','); getline(sub2, Type, ','); getline(sub2, Name, ','); getline(sub2, Address, ','); getline(sub2, Phone, ','); getline(sub2, Email);
                sub.push_back({ SubscriberID,Type,Name,Address,Phone,Email });
            }
            x = 1;
            getline(file, record, '\n');
        }
    }

}
void loadborrowfile()
{
    string record;
    fstream file;
    file.open("borrowing.CSV", ios::in);
    if (!(file.fail()))
    {
        getline(file, record, '\n');
        bool x = 0;
        while (file)
        {
            if (x == 1)
            {

                string libraryid, libraryname;
                string subscriberID, BorrowDate, contentID, ReturnDate, Fee, subscribername;
                stringstream sub2;
                string iteminfo;
                sub2 << record;
                getline(sub2, subscriberID, ','); getline(sub2, BorrowDate, ','); getline(sub2, contentID, ','); getline(sub2, ReturnDate, ','); getline(sub2, Fee);
                for (auto it = lib.begin(); it != lib.end(); it++)
                {
                    if (it->getnameonid(stoi(contentID, nullptr, 10)) != "")
                    {
                        libraryid = it->getlibraryid();
                        libraryname = it->getlibrartname();
                        iteminfo = it->getnameonid(stoi(contentID, nullptr, 10));
                    }
                }
                stringstream all;
                all << iteminfo;
                string item_id, catagory, title, author, publisher, production_year, status, copies;
                getline(all, item_id, ','); getline(all, catagory, ','); getline(all, title, ','); getline(all, author, ','); getline(all, publisher, ','); getline(all, production_year, ','); getline(all, status, ','); getline(all, copies);
                bool flag = 0;
                for (auto it = borrow.begin(); it != borrow.end(); it++)
                {
                    if (it->getsubscriberid() == subscriberID)
                    {
                        flag = 1;
                        if (catagory == "book")
                        {
                            it->setlibrary({ libraryid,libraryname,{ title, author, publisher, stoi(production_year, nullptr, 10), stoi(copies, nullptr, 10), status, stoi(item_id, nullptr, 10) } });
                            it->setborrowdate(stoi(item_id, nullptr, 10), BorrowDate);
                            it->setreturndate(stoi(item_id, nullptr, 10), ReturnDate);
                            it->setfine(stoi(item_id, nullptr, 10), stoi(Fee, nullptr, 10));
                        }
                        if (catagory == "article")
                        {
                            it->setlibrary({ libraryid,libraryname,{ title,author,publisher,status,stoi(production_year,nullptr,10),stoi(copies,nullptr,10),stoi(item_id,nullptr,10) } });
                            it->setborrowdate(stoi(item_id, nullptr, 10), BorrowDate);
                            it->setreturndate(stoi(item_id, nullptr, 10), ReturnDate);
                            it->setfine(stoi(item_id, nullptr, 10), stoi(Fee, nullptr, 10));
                        }
                        if (catagory == "digital media")
                        {
                            it->setlibrary({ libraryid,libraryname,{ title,author,publisher,stoi(production_year,nullptr,10),status,stoi(copies,nullptr,10),stoi(item_id,nullptr,10) } });
                            it->setborrowdate(stoi(item_id, nullptr, 10), BorrowDate);
                            it->setreturndate(stoi(item_id, nullptr, 10), ReturnDate);
                            it->setfine(stoi(item_id, nullptr, 10), stoi(Fee, nullptr, 10));
                        }

                    }
                }
                if (flag == 0)
                {
                    for (auto it = sub.begin(); it != sub.end(); it++)
                    {
                        if (it->getsubsriberid() == subscriberID)
                        {
                            subscribername = it->getsubscriberNAME();
                        }
                    }
                    auto it = find(sub.begin(), sub.end(), subscribers(subscriberID, subscribername));
                    if (catagory == "book")
                    {
                        subscribers s{ it->getsubsriberid(),it->getsubsriberTYPE(),it->getsubscriberNAME(),it->getsubscriberaddress(),it->getsubscriberPHONE(),it->getsubscriberEMAIL() };
                        library l{ libraryid,libraryname,{ title, author, publisher, stoi(production_year, nullptr, 10), stoi(copies, nullptr, 10), status, stoi(item_id, nullptr, 10) } };
                        borrow.emplace_back(l, s, item_id, BorrowDate, ReturnDate, Fee);
                    }
                    if (catagory == "article")
                    {
                        subscribers s{ it->getsubsriberid(),it->getsubsriberTYPE(),it->getsubscriberNAME(),it->getsubscriberaddress(),it->getsubscriberPHONE(),it->getsubscriberEMAIL() };
                        library l{ libraryid,libraryname,{ title,author,publisher,status,stoi(production_year,nullptr,10),stoi(copies,nullptr,10),stoi(item_id,nullptr,10) } };
                        borrow.emplace_back(l, s, item_id, BorrowDate, ReturnDate, Fee);

                    }
                    if (catagory == "digital media")
                    {
                        subscribers s{ it->getsubsriberid(),it->getsubsriberTYPE(),it->getsubscriberNAME(),it->getsubscriberaddress(),it->getsubscriberPHONE(),it->getsubscriberEMAIL() };
                        library l{ libraryid,libraryname,{ title,author,publisher,stoi(production_year,nullptr,10),status,stoi(copies,nullptr,10),stoi(item_id,nullptr,10) } };
                        borrow.emplace_back(l, s, item_id, BorrowDate, ReturnDate, Fee);

                    }
                }

            }
            x = 1;
            getline(file, record, '\n');
        }
    }

}
void saveinfile()
{
    fstream file;
    file.open("library.CSV", ios::out);
    file << "Library ID" << "," << "Name" << endl;
    sort(lib.begin(), lib.end());
    for (auto it : lib)
    {

        file << it.sptostring_library() << endl;
    }
    file.close();
    fstream file2;
    fstream file3;
    file3.open("items.CSV", ios::out);
    file3 << "Item ID" << "," << "LibraryID" << "," << "Category" << "," << "Title" << "," << "Author" << "," "Publisher" << "," "Production_Year" << "," << "Status" << "," << " Copies\n";
    string data;
    sort(lib.begin(), lib.end());
    for (auto it = lib.begin(); it != lib.end(); it++)
    {
        it->sortinfo();
        stringstream sub;
        sub << it->sptostring();
        while (getline(sub, data, '\n'))
        {
            string Item_ID, Category, Title, Author, Publisher, prod_Year, Status, Copies;
            stringstream sub2;
            sub2 << data;
            getline(sub2, Item_ID, ','); getline(sub2, Category, ','); getline(sub2, Title, ','); getline(sub2, Author, ','); getline(sub2, Publisher, ','); getline(sub2, prod_Year, ','); getline(sub2, Status, ','); getline(sub2, Copies);
            file3 << Item_ID << "," << it->getlibraryid() << "," << Category << "," << Title << "," << Author << "," << Publisher << "," << prod_Year << "," << Status << "," << Copies << "\n";
        }

    }
    file3.close();
    fstream file4;
    file4.open("subscribers.CSV", ios::out);
    file4 << "Subscriber ID" << "," << "Type" << "," "Name" << "," << "Address" << "," << "Phone" << "," << "Email\n";
    sort(sub.begin(), sub.end());
    for (auto it : sub)
    {
        file4 << it.sptostring();

    }
    file4.close();
    fstream file5;
    file5.open("borrowing.CSV", ios::out);
    file5 << "SUBSCRIBER ID" << "," << "Borrow Date" << "," << "content id" << "," << "Return Date" << "," << "Fee\n";
    for (auto it : borrow)
    {
        file5 << it.sptostring();

    }
    file5.close();
}
string isValidLibraryId(string id)
{
Libraryid:
    for (int i = 0; i < id.length(); i++)
    {
        if (!(isdigit(id[i])))
        {
            cout << "Error! Library id must contain only digits. Please try again...\n";
            cout << "Enter Library id: ";
            cin >> id;
            cin.ignore();
            goto Libraryid;
        }
    }

    return id;
}
string isValidSubscriberid(string id)
{
Subscriber:
    for (int i = 0; i < id.length(); i++)
    {
        if (!(isdigit(id[i])))
        {
            cout << "Error! Subscriber id must contain only digits. Please try again...\n";
            cout << "Enter Subscriber id: ";
            cin >> id;
            cin.ignore();
            goto Subscriber;
        }
    }

    return id;
}
string isValidSubscriberType(string stype)
{
sstype:
    if (stype == "regular" || stype == "Regular" || stype == "REGULAR" || stype == "golden" || stype == "Golden" || stype == "GOLDEN") {
        return stype;
    }
    else {
        cout << "Error! Subscriber type should be 'Golden' or 'Regular'. Please try again....\n";
        cout << "Enter Subscriber type: ";
        getline(cin, stype, '\n');
        goto sstype;
    }

}
string isValidSubscriberName(string sname) {
Subscribername:
    if (sname.length() > 30)
    {
        cout << "Error! Subscriber name length should be of 30 or less. Please try again....\n";
        cout << "Enter Subscriber name: ";
        getline(cin, sname, '\n');
        goto Subscribername;
    }
    for (int i = 0; i < sname.length(); i++)
    {
        if (!(isalpha(sname[i]) || sname[i] == 32))
        {
            cout << "Error! Subscriber name should consisit alphabet or space. Please try again....\n";
            cout << "Enter Subcsriber name: ";
            getline(cin, sname, '\n');
            goto Subscribername;
        }
    }
    return sname;

}

string isValidSubscriberPhone(string pNo) {
SubscriberPhone:
    if (pNo.length() == 11)
    {
        for (int i = 0; i < pNo.length(); i++)
        {
            if (!(isdigit(pNo[i])))
            {
                cout << "Error! Phone no must contain only digits. Please try again...\n";
                cout << "Enter Subscriber Phone no: ";
                getline(cin, pNo, '\n');
                goto SubscriberPhone;
            }
        }

    }
    else
    {
        cout << "Error! Subscriber Phone no length should be of 11. Please try again....\n";
        cout << "Enter Subscriber Phone no: ";
        getline(cin, pNo, '\n');
        goto SubscriberPhone;
    }

    return pNo;
}
string isValidSubscriberEmail(string semail)
{
email:
    size_t x = semail.find('@');
    if (x != string::npos)
    {
        string key;
        key = semail.substr(x + 1);
        if (!(key == "gmail.com" || key == "hotmail.com" || key == "yahoo.com"))
        {
            cout << "Error! email must contain 'gmail.com' or 'hotmail.com' or 'yahoo.com' as domain Please try again...\n";
            cout << "Enter email: ";
            getline(cin, semail, '\n');
            goto email;
        }
    }
    else {
        cout << "Error! email must contain domain Please try again...\n";
        cout << "Enter email: ";
        getline(cin, semail, '\n');
        goto email;
    }
    return semail;
}
string isValidAuthor(string auth) {
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
string isValidPublisher(string pub) {

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
string isValidProductionYear(string year) {
    int pyear;
    bool flag = 0;
    while (flag == 0)
    {
        try
        {
            pyear = stoi(year, nullptr, 10);
            flag = 1;
        }
        catch (invalid_argument ch)
        {
            cout << "entered numeric value for year\n";
            cin >> year;
            cin.ignore();
        }
    }
proyear:
    if (pyear > 2020 || pyear < 1800)
    {
        cout << "Error! Production year must be greater than 1800 and less or equal to 2020. Please try again....\n";
        cout << "Enter Production year: ";
        cin >> pyear;
        cin.ignore();
        goto proyear;
    }
    return std::to_string(pyear);
}
string isValidCopies(string copies)
{
    int copy;
    bool flag = 0;
    while (flag == 0)
    {
        try
        {
            copy = stoi(copies, nullptr, 10);
            flag = 1;
        }
        catch (invalid_argument ch)
        {
            cout << "entered numeric value for copies\n";
            cin >> copies;
            cin.ignore();
        }
    }
copies:
    if (copy < 0)
    {
        cout << "Error! No of copies must not be less than 0 or  Please try again....\n";
        cout << "Enter No of copies: ";
        cin >> copy;
        cin.ignore();
        goto copies;
    }

    return std::to_string(copy);
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


