#include"Author.h"
#include<string>
#include<iostream>
using namespace std;


Author::Author()
{
	_name = "";
	_dob = 0;
	_dod = 0;
}

Author::Author(string name, int dob, int dod)
{
	_name = name;
	_dob = dob;
	_dod = dod;
}
void Author::display() const
{
	cout << _name << " (" << _dob << " - " << _dod << ")" << endl<<endl;
}

string Author::getAuthorName() const
{
	return _name;
}

