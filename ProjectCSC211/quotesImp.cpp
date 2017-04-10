#include<string>
#include"Quotes.h"
#include"Quote.h"
#include<iostream>
using namespace std;

Quotes::Quotes(int n)
{
	_numQuotes = n;
	(_allQuotes) = new Quote[n];
}


Quotes::Quotes(const Quotes & original)
{
	_numQuotes = original._numQuotes;
	_allQuotes = new Quote[_numQuotes];
	for (int i = 0; i< _numQuotes; i++)
		_allQuotes[i] = original._allQuotes[i];
}


void Quotes:: operator =  (const Quotes & original)
{
_numQuotes = original._numQuotes;
for (int i = 0; i< _numQuotes; i++)
	_allQuotes[i] = original._allQuotes[i];
}


Quotes::~Quotes()
{
	delete[] _allQuotes;
}



void Quotes::addQuote(Quote oneQuote, int counter)
{
	_allQuotes[counter] = oneQuote;
}



void Quotes::printAllQuotes(int counter) const
{
	int i;
	for (i = 0; i < counter; i++)
	{
		_allQuotes[i].printAll();
	}}


string Quotes::searchAuthor(string authorToSearch, int numOfQuotes,int& numOfSearches) 
{
	int count = 0;
	string correspondingQuotes = "";
	
	
		while (_allQuotes[count].getAuthor() <= authorToSearch && count<numOfQuotes)
		{
			if (_allQuotes[count].getAuthor() == authorToSearch)
			{
				correspondingQuotes += _allQuotes[count].returnQuote();
				correspondingQuotes += "\n\n";
				
			}
			if (_allQuotes[count].getAuthor() != authorToSearch)
				numOfSearches++;
			count++;
		}

	if (correspondingQuotes == "")
		return "\t\t\tAUTHOR NOT FOUND";
	else 
		return correspondingQuotes;
}


string Quotes::searchTheme(string themeToSearch, int numOfQuotes,int& numOfSearches) const
{
	int count=0;
	string correspondingQuotes = "";
	while (_allQuotes[count].getTheme() <= themeToSearch && count < numOfQuotes)
	{
		if (_allQuotes[count].getTheme() == themeToSearch)
		{
			correspondingQuotes += _allQuotes[count].returnQuote();
			correspondingQuotes += "\n\n";
		}
		if (_allQuotes[count].getAuthor() != themeToSearch)
			numOfSearches++;
		count++;
	}
	if (correspondingQuotes == "")
		return "\t\t\tTHEME NOT FOUND";
	else
		return correspondingQuotes;
}


void Quotes::swapQ(Quote & qFirst, Quote & qSecond){
	Quote temp;
	temp = qFirst;
	qFirst = qSecond;
	qSecond = temp;
}

void Quotes::sortByAuthor(int numOfQuotes){

	int index, smallestIndex, location;
	Quote temp;

	for (index = 0; index < numOfQuotes; index++)
	{
		smallestIndex = index;
		for (location = index + 1; location < numOfQuotes; location++)
		{
			if (_allQuotes[location].getAuthor() <= _allQuotes[smallestIndex].getAuthor())
				smallestIndex = location;
		}
		swapQ(_allQuotes[smallestIndex], _allQuotes[index]);
	}}

void Quotes::sortByTheme(int numOfQuotes)
{
	int index, smallestIndex, location;
	Quote temp;

	for (index = 0; index < numOfQuotes; index++)
	{
		smallestIndex = index;
		for (location = index + 1; location < numOfQuotes; location++)
		{
			if (_allQuotes[location].getTheme() <= _allQuotes[smallestIndex].getTheme())
				smallestIndex = location;
		}
		swapQ(_allQuotes[smallestIndex], _allQuotes[index]);
	}}





