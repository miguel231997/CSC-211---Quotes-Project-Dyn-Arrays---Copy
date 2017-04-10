//

#include<iostream>
#include<string>
#include"Author.h"
#include"Quote.h"
#include"quotes.h"
#include<fstream>
#include<iomanip>
using namespace std;


void main(int argc,char* argv[])
{
	const int MAXQUOTES = 500;
	system("color a5");
	string line;
	int birthYear, deathYear;
	char dash;
	string author;
	string theme;
	string authorToSearch = "";
	string themeToSearch = "";
	int numOfSearches = 0;
	//Count keeps track of the number of quotes we have in the array
	int counter = 0;
	

	int j = 0;
	

	//Variables used in the menu
	string replay = "y";
	string name;//Name used to greet the user
	string Menu; //Character for menu contour
	string choice; 


	ifstream inQuotes;
	inQuotes.open(argv[1]);

	//First Quotes array that will be ordered by Author
	Quotes allQuotes(MAXQUOTES);

	//Check to see if file doesn't open : return error message
	if (!inQuotes.is_open())
	{
		cout << "File could not be opened!!!"<<endl<<endl;
		return;
	}

	

	//Menu shown to the user : 
	//He enters a character for the menu borders, and then choose from the options
	
	cout << "\nChoose any character to use for the menu's borders: "; 
	cin >> Menu; 
	cout << "\n";


	//Loop that reads all quotes, author information and themes from the text file inQuotes into the array of quote allQuotes.
	while (!inQuotes.eof() && counter < MAXQUOTES)
	{
		//Reads A whole quote and its information
		getline(inQuotes, line);
		getline(inQuotes, theme);
		getline(inQuotes, author, '(');
		inQuotes >> birthYear;
		inQuotes >> dash;
		inQuotes >> deathYear;
		inQuotes.ignore();
		inQuotes.ignore();
		//Stores the author information in oneAuthor
		Author oneAuthor(author, birthYear, deathYear);
		//Stores oneAuthor and the quote and theme in oneQuote
		Quote oneQuote(oneAuthor, line,theme);
		//allQuotes is an array of multiple oneQuote(s)
		allQuotes.addQuote(oneQuote, counter);
		counter++;
	}


	//Copy the Arrray and create an array that will be ordered by theme
	Quotes allQuotesByTheme(allQuotes);

	allQuotes.sortByAuthor(counter);			// First Array gets sorted by Author
	allQuotesByTheme.sortByTheme(counter);	   // Second Array gets sorted by Theme

	
	
	
	while (replay[0] == 'y' || replay[0] == 'Y')
	{
		string toPrint = "";
		numOfSearches = 0;
		j = 0;
		cout << setw(56) << setfill(Menu[0]) << right << "\n"; //Fill the 56 spaces with the chosen character stored in Menu
		cout << Menu[0] << "      \t\tWelcome," << name << "!" << setfill(' ') << setw(30 - name.length()) << Menu[0] << endl;
		cout << Menu[0] << "\t\t\t\t\t\t      " << Menu[0] << "\n";



		cout << Menu[0] << " Please choose from the following options:           " << Menu[0] << "\n";// Prompts the user to choose one
																								// of the following options
		cout << Menu[0] << setw(54) << setfill(' ') << Menu[0] << "\n";
		cout << Menu[0] << "\t  1.   Search By Author!\t\t      " << Menu[0] << "\n"//Proposition number 1
			<< Menu[0] << "\t  2.   Search by Theme!\t\t\t      " << Menu[0] << "\n"//Proposition number 2
			<< Menu[0] << "\t  3.   Print out all Quotes Ordered By Author " << Menu[0] << "\n"//Proposition number 3
			<< Menu[0] << "\t  4.   Print out all Quotes Ordered By Theme  " << Menu[0] << "\n"//Proposition number 4
			<< Menu[0] << "\t  5.   Exit   \t\t\t\t      " << Menu[0] << "\n";//Proposition number 5
		cout << Menu[0] << setw(54) << setfill(' ') << Menu[0] << "\n";//Fill the 
																 //56 spaces with the chosen character stored in Menu


		cout << setw(56) << setfill(Menu[0]) << right << "\n";
		cin >> choice; //Affects the user's input (1,2,3,or 4) to the variable Choice
		cin.ignore();


		

		//Search by Author full name
		if (choice[0] == '1')
		{

			cout <<endl<< "Enter the name of the author: ";
			getline(cin, authorToSearch);
			cout << endl << endl;
			authorToSearch = authorToSearch + ' ';
			cout << "------------------------------------------------------" << endl << endl;
			toPrint = allQuotes.searchAuthor(authorToSearch, counter, numOfSearches);
			cout << toPrint;
			if (toPrint != "\t\t\tAUTHOR NOT FOUND")
				cout << endl << endl << "\t  Number of elements it went through to find your author: " << numOfSearches << endl;
			
			
		}

		//Search by theme
		//Goes through all the quotes in the array allQuotes, prints all the ones corresponding to the theme searched
		else if (choice[0] == '2')
		{
			cout << "Enter the theme: ";
			getline(cin, themeToSearch);
			cout << endl << endl;
			cout << "------------------------------------------------------" << endl << endl;
			toPrint=allQuotesByTheme.searchTheme(themeToSearch, counter,numOfSearches);
			cout << toPrint;
			if (toPrint!= "\t\t\tTHEME NOT FOUND")
				cout << endl <<endl<< "\t  Number of elements it went through to find your theme: " << numOfSearches << endl;
			
		}

		//Print all quotes ordered by author name (authors,quotes, and themes)
		else if (choice[0] == '3')
		{
			cout << endl << endl;
			cout << endl << "ALL QUOTES :" << endl<<endl << "-------------------------------------------------" << endl << endl;
			allQuotes.printAllQuotes(counter);
		}

		//Print all quotes ordered by author Theme (authors,quotes, and themes)
		else if (choice[0] == '4')
		{
			cout << endl << endl;
			cout << endl << "ALL QUOTES :" << endl << endl << "-------------------------------------------------" << endl << endl;
			allQuotesByTheme.printAllQuotes(counter);
		}


		//If user wants to exit the program
		else if (choice[0] == '5')
		{
			cout << endl<<"We hope you found what you were looking for"<<endl<<" Thank you for using our service!!" << endl << endl;
			return;
		}

		//If user enters anything else than 1,2,3,4, or 5
		else
		{	
			cout << endl << endl << "There was an error in the option you chose.";	
		}

		//After every use, user can go back to the main menu or just exit the program
		cout << endl <<endl<< "------------------------------------------------------" << endl << endl << "Do you want to go back to the main menu?\n\n Enter y for yes, n for no: ";
		cin >> replay;
		while (!(replay[0] == 'y' || replay[0] == 'Y' || replay[0] == 'n' || replay[0] == 'N'))
		{
			cout << endl << "Incorrect input, try again ('y' or 'n'): ";//If the input is not y or n, asks for another input
			cin >> replay;
		}}
	cout<<endl<<endl<<"Thank you for using this service!" << endl << endl;
	return;
}