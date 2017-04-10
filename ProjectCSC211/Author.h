#ifndef AUTHOR
#define AUTHOR

#include<string>
using namespace std;

class Author{

public:
	Author();
	//Function : default constructor

	Author(string name, int dob, int dod); 
	//Function: Sets the author instance by giving it an author name, a date of birth and a date of death

	void display() const;
	//Function: displays the name of the author with their date of birth and the name of death in parentheses
	//string returnAuthorName() const;

	string getAuthorName() const;
	//Function: Returns the name of the author as a string
	
	
private:

	string _name;
	int _dob;
	int _dod;
};
#endif