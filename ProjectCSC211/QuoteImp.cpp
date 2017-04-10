#include"Quote.h"
#include<iostream>
using namespace std;


Quote::Quote()
{
	_firstQuote = "";
	_theme = "";
	_author=Author();
}
Quote::Quote(Author author,string firstQuote,string theme) 
{
	_firstQuote = firstQuote;
	_author = author;
	_theme = theme;
}


void Quote::printAll() const
{
	cout << _firstQuote << endl;
	cout << _theme << endl;
	_author.display();
}

string Quote::returnQuote() const
{
	return _firstQuote;
}
string Quote::getAuthor() const
{
	return _author.getAuthorName();

}

string Quote::getTheme() const
{
	return _theme;
}



