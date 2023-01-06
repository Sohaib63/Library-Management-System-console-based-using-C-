#include "contents.h"
#include"library.h"
#include"articles.h"
#include"books.h"
#include<iostream>
#include"digitalmedia.h"
#include<vector>
#include<algorithm>
contents::contents()
{}
contents::contents(articles a)
{
	article.push_back(a);
}
contents::contents(books b)
{
	book.push_back(b);
}
contents::contents(digitalmedia d)
{
	digital.push_back(d);
}
contents::contents(articles a, books b, digitalmedia d)
{
	article.push_back(a);
	book.push_back(b);
	digital.push_back(d);
}
contents& contents::setarticle(articles a)
{
	article.push_back(a);
	return *this;
}
void contents::editdigitalmedia(digitalmedia that)
{
	for (auto it = digital.begin(); it != digital.end(); it++)
	{
		if (it->getdigitalmediaitemid() == that.getdigitalmediaitemid())
		{
			
			it->setdigitalmedia(that.getdigitalmediatitle(), that.getdigitalmediaauthor(), that.getdigitalmediapublisher(), that.getdigitalmediaprodyear(), that.getdigitalmediastatus(), that.getdigitalmediacopies(), that.getdigitalmediaitemid());
			break;
		}

	}
}
void contents::editarticles(articles that)
{
	for (auto it = article.begin(); it != article.end(); it++)
	{
		if (it->getarticleitemid() == that.getarticleitemid())
		{
			//string t, string a, string p, string s, int prd, int c, int id
			it->setarticle(that.getarticletitle(), that.getarticleauthor(), that.getarticlepublisher(), that.getarticlestatus(), that.getarticleprodyear(), that.getarticlecopies(), that.getarticleitemid());
			break;
		}

	}
}
void contents::editbook(books that)
{
	for (auto it = book.begin(); it != book.end(); it++)
	{
		if (it->getbookitemid()==that.getbookitemid())
		{
		 it->setbook(that.getbooktitle(), that.getbookauthor(), that.getbookpublisher(), that.getbookprodyear(), that.getbookcopies(), that.getbookstatus(), that.getbookitemid());
		 break;
		}

	}
}
bool contents::editcopies(articles a)
{
	auto it = find(article.begin(), article.end(), a);
	if (it != article.end())
	{
		return (it->copiesdecrement());
	}
	return false;
}
bool contents::editcopies(books b)
{

	auto it = find(book.begin(), book.end(), b);
	if (it != book.end())
	{
		return (it->copiesdecrement());

	}
	return false;
}
bool contents::editcopies(digitalmedia d)
{
	auto it = find(digital.begin(), digital.end(), d);
	if (it != digital.end())
	{
		return (it->copiesdecrement());

	}
	return false;
}
contents& contents::setbook(books b)
{

	book.push_back(b);
	return *this;
}
contents& contents::setdigitalmedia(digitalmedia d)
{
	digital.push_back(d);
	return *this;
}
string contents::tostring() const
{ 
	string data;
	for (auto it : this->book)
	{
		data += it.books::tostring();
		data += '\n';

	}
	for (auto it : this->article)
	{
		data += it.articles::tostring();
		data += '\n';

	}
	for (auto it : this->digital)
	{
		data += it.digitalmedia::tostring();
		data += '\n';

	}
	return data;
}
void contents::uniquekey(int itemid)
{
	for (auto it=book.begin();it!=book.end();it++)
	{
		if (it->getbookitemid()>itemid)
		{
			it->decreaseoneinitemid();
		}
	}
	for (auto it = article.begin(); it != article.end(); it++)
	{
		if (it->getarticleitemid() > itemid)
		{
			it->decreaseoneinitemid();
		}
	}
	for (auto it = digital.begin(); it != digital.end(); it++)
	{
		if (it->getdigitalmediaitemid() > itemid)
		{
			it->decreaseoneinitemid();
		}
	}
}
void contents::deleteitem(int item_id)
{
	for (auto it = article.begin(); it != article.end(); it++)
	{
		if (it->getarticleitemid() == item_id)
		{
			article.erase(it);
			break;

		}
	}
	for (auto it = book.begin(); it != book.end(); it++)
	{
		if (it->getbookitemid() == item_id)
		{
			book.erase(it);
			break;

		}
	}
	for (auto it = digital.begin(); it != digital.end(); it++)
	{
		if (it->getdigitalmediaitemid() == item_id)
		{
			digital.erase(it);
			break;

		}
	}
}
void contents::increasecopies(int itemid)
{
	
	for (auto it=this->book.begin();it!=book.end();it++)
	{
		if (it->getbookitemid()==itemid)
		{
			it->incresebookcopies(itemid);
			
		}
		
	}
	for (auto it = this->article.begin(); it != article.end(); it++)
	{
		if (it->getarticleitemid()==itemid)
		{
			it->increasecopies(itemid);
		}
		
	}
	for (auto it = this->digital.begin(); it != digital.end(); it++)
	{
		if (it->getdigitalmediaitemid()==itemid)
		{

			it->incresecopies(itemid);
		}
	}

}
string contents::getnameonid(int itemid)
{
	for (auto it=book.begin();it!=book.end();it++)
	{
		if (it->getbookitemid()==itemid)
		{
			return it->sptostring();

		}
	}
	for (auto it = article.begin(); it != article.end(); it++)
	{
		if (it->getarticleitemid() == itemid)
		{
			return it->sptostring();

		}
	}
	for (auto it = digital.begin(); it != digital.end(); it++)
	{
		if (it->getdigitalmediaitemid() == itemid)
		{
			return it->sptostring();

		}
	}
	return "";
}
void contents::sort()
{
	std::sort(book.begin(),book.end());
	std::sort(digital.begin(),digital.end());
	std::sort(article.begin(),article.end());
}
string contents::sptostring() const
{
	
	string data;
	for (auto it : this->book)
	{
		data += it.books::sptostring();
		data += '\n';

	}
	for (auto it : this->article)
	{
		data += it.articles::sptostring();
		data += '\n';

	}
	for (auto it : this->digital)
	{
		data += it.digitalmedia::sptostring();
		data += '\n';

	}
	return data;


}
int contents::findbook(string name, string author)
{

	auto it = find(book.begin(), book.end(), books(name, author));

	if (it != book.end())
	{
		return it->getbookitemid();
	}
	return 0;
}
int contents::finddigitalmedia(string name, string author)
{
	auto it = find(digital.begin(), digital.end(), digitalmedia(name, author));
	if (it != digital.end())
	{
		return it->getdigitalmediaitemid();
	}
	return 0;
}
int contents::findarticle(string name, string author)
{

	auto it = find(article.begin(), article.end(), articles(name, author));
	if (it != article.end())
	{
		return it->getarticleitemid();
	}
	return 0;
}