#ifndef QUOTES
#define QUOTES
#include"Quote.h"
#include<iostream>
#include<string>

class Quotes{

public:

	Quotes(int);
	//Constructor
	//Function: Initializes an instance of Quotes to default values if parameter is entered

	Quotes(const Quotes & original);
	//Copy constructor
	//Function: user defined copy constructor to create an instance as a copy of another instance of the quotes class
	//Parameters: A constant instance of the quotes class sent by reference

	void operator =  (const Quotes &);
	//Function: Overloads opeator "=" so there is a version of it that can be used with quotes instances
	//Parameters: same parameter as the copy constructor

	~Quotes();
	//Function: User defined destructor, frees the memory occupied by the quote arrays after main is over
		
	void addQuote(Quote,int ); 
	//Function: Add quote to the array of Quote
	//Parameters : one quote instance and integer that decides the position in the array to which the quote is assigned


	void printAllQuotes(int) const;
	//Function: Loop that prints out all the quotes currently in the array _allQuotes
	//Parameter : counter is the number of quote instances in the array _allQuotes
	//every quote instance of the array (_allQuotes[i]) calls the Quote member function .printAll()


	string searchAuthor(string,int,int &);
	//Function: Returns all the quotes corresponding to an author search
	//Parameters : string is author's full name being searched for, int is the number of quotes in the array 
	                              //to stop the function from going through the whole array in certain cases

	string searchTheme(string, int,int&) const;
	//Function: Returns all the quotes corresponding to a theme search
	//Parameters: String is the theme being searched for
				//Integer is the number of quotes in the array

	void sortByAuthor(int);
	//Function: Sort the array in a quotes instance alphabetically by author first name
	//Parameters: The number of quotes in the array to sort for the loop 

	void sortByTheme(int);
	//Function: Sort the array in a quotes instance alphabetically by theme 
	//Parameters: The number of quotes in the array to sort for the loop 

private:
	int _numQuotes;  // Contains the amount of max spots in the array
	Quote * _allQuotes; // An array of quote instances
	void swapQ(Quote & qFirst, Quote & qSecond);  // Function used to swap for the sorting

};
#endif