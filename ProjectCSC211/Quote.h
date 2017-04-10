#ifndef QUOTE
#define QUOTE

#include<string>
#include"Author.h"
using namespace std;

class Quote
{
public:

	Quote();

	Quote(Author author,string firstQuote,string theme);
	//Function: Sets the quote instance to have an author instance, a quote and a theme

	void printAll() const;
	//Function: Prints out the quote,the theme, and the author information as well

	string getAuthor() const;
	//Function: Returns author name
	
	string getTheme() const;
	//Function: Returns the theme for a certain quote

	string returnQuote() const;
	//Function: Returns quote from quote instance

	

private:

	Author _author;
	string _firstQuote;
	string _theme;
	



};
#endif