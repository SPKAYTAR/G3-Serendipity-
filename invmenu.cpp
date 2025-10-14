/*********************************************************************
* CS1B – G3: Serendipity
*  Partner A: Sean Hanabusa (ID) — role: Cashier.cpp
*  Partner B: Kayden Tarvaran (ID) — role: invmenu.cpp, main.cpp, reports.cpp
*  Date: 2025‑09‑18
*  Purpose: Design and implement menu-driven input with validation for an inventory system.
*  Build:   g++ -std=c++20 mainmenu.cpp bookType.cpp cashier.cpp invmenu.cpp reports.cpp -o serendipity
***********************************************************************/


#include <iostream>
#include <iomanip>
#include <cctype>
#include <vector>
#include <limits>
using namespace std;
#include "invmenu.h"
#include "bookType.h"

const int DATABASE_SIZE = 20;
vector<bookType> database;


void invMenu(){
    string input;
    char c;
    do{
	 c = '0';
    cout << "\033[H\033[J" << flush;


    cout << setfill('*') << setw(80) << "*" << endl; 
    cout << setfill(' ');

    cout << "*" << setw(78) << " " << "*" << endl;
    cout << left << "*  " << setw(76) << "Serendipity Booksellers" << "*" << endl;
    cout << left << "*  " << setw(76) << "Inventory Database" << "*" << endl;
    cout << "*" << setw(78) << " " << "*" << endl;
    cout << left << "*  " << setw(76) << "------------------------------" << "*" << endl;
    cout << left << "*  " << setw(76) << "1. Look Up a Book" << "*" << endl;
    cout << left << "*  " << setw(76) << "2. Add a Book" << "*" << endl;
    cout << left << "*  " << setw(76) << "3. Edit a Book's Record" << "*" << endl;
    cout << left << "*  " << setw(76) << "4. Delete a Book" << "*" << endl;
    cout << left << "*  " << setw(76) << "5. Return to the Main Menu" << "*" << endl;
    cout << left << "*  " << setw(76) << "------------------------------" << "*" << endl;
    cout << left << "*  " << setw(76) << "Enter choice:" << "*" << endl;
    cout << setfill('*') << setw(80) << "*" << endl; 

    cout << "\x1B[2A";       
    cout << "\x1B[16C";

    getline(cin, input);

    if (input.length() == 1 && isdigit(input[0])) {
    c = input[0];
    
    }

    switch(c){

        case '1': {
            lookUpBook();
            break;
        }
        case '2': {
            addBook();
            break;
        } 
        case '3': {
            editBook();
            break;
        }
        case '4': {
            deleteBook();
            break;
        }
        case '5': {
            break;
        }
        default: {
            cout << "\x1B[2J\x1B[H";
            cout << "Invalid entry, enter a value 1 -> 5, press enter to continue.";
            pause();
            break;
        }
                
    }
}while( c != '5');
    
    
}

void lookUpBook(){
	string target; 
	string title;
	string isbn;
	vector<int> bookLocations;
	int choice;
	bookLocations.reserve(20);
    cout << "\x1B[2J\x1B[H";
    cout << "=== Look Up Book ===\n";
    cout << "Enter Book Title or ISBN:";
	cin >> target;
	for (char &c : target){
    	c = tolower(c);
    }
	for(int i = 0; i < database.size(); i++){
		title = database[i].getTitle();
		isbn = database[i].getISBN();
		for (char &c : title){
            c = tolower(c);
        }
		for (char &c : isbn){
            c = tolower(c);
        }
		if (title.find(target) != string::npos || title.find(target) != string::npos){
            bookLocations.push_back(i);
        }
	}
	
	if(bookLocations.size() == 0)
	{
		cout << "\x1B[2J\x1B[H";
    	cout << "=== Look Up a Book ===\n";
		cout << "item not in inventory" << endl;
		pause();
	}
	else{
		do
		{
		for(int i=0; i < bookLocations.size(); i++)
		{
			cout << "\x1B[2J\x1B[H";
    		cout << "=== Look Up a Book ===\n";
			cout << "Matching Books:" << endl;
			cout << i << ". " << (database[bookLocations[i]].getTitle()).substr(0,30) << endl;
		}
			cout << "Enter Choice(-1 to Exit): ";
			cin >> choice;
			if (choice == -1)
			{
				break;
			}
			else if(choice < 0 || choice >= bookLocations.size()){
				cout << "Enter Valid Choice (0-" << bookLocations.size()-1 << ")" << endl;
				pause();
			}
			else
			{
				cout << "\x1B[2J\x1B[H";
    			cout << "=== Look Up a Book ===\n";
				database[bookLocations[choice]].print();
			}
		} while(choice < 0 || choice >=bookLocations.size());
	}
    pause();
	return();
}

void addBook()
{
    if (bookType::getBookCount() >= 20)
    {
        cout << "\033[H\033[J" << flush;

        cout << "DATABASE FULL (20 BOOKS). Cannot add more.\n";
        pause();
        return;
    }

    database.reserve(20);

    string title = "--EMPTY";
    string isbn = "--EMPTY";
    string author = "--EMPTY";
    string publisher = "--EMPTY";
    string dateAdded = "--EMPTY";
    int qty = 0;
    float wholesale = 0.0f;
    float retail = 0.0f;

    char c = '0';
    string input;

    do
    {
        cout << "\x1B[2J\x1B[H";
        cout << setfill('*') << setw(80) << "*" << endl;
        cout << setfill(' ');
        cout << left << "*  " << setfill(' ') << setw(25) << "" << setw(51) << "SERENDIPITY BOOKSELLERS" << "*" << endl;
        cout << left << "*  " <<setfill(' ') << setw(33) << "" << setw(43) << "ADD BOOK" << "*" << endl;
        cout << left << "*  " << setw(76) << " " << "*" << endl;

        
        cout << left << "*  " << setfill(' ') << setw(27) << "" << setw(41) << "DATABASE SIZE: 20   CURRENT BOOK COUNT: " <<setw(8) << bookType::getBookCount() << "*" << endl;
        cout << left << "*  " << setw(76) << " " << "*" << endl;
        cout << "*  " << right << setw(76) << "--PENDING VALUES            " << "*" << endl;

        
        cout << left << "*  <1> Enter Book Title              > " << setw(40) << title << "*" << endl;
        cout << left << "*  <2> Enter ISBN                    > " << setw(40) << isbn << "*" << endl;
        cout << left << "*  <3> Enter Author                  > " << setw(40) << author << "*" << endl;
        cout << left << "*  <4> Enter Publisher               > " << setw(40) << publisher << "*" << endl;
        cout << left << "*  <5> Enter Date Added (mm/dd/yyyy) > " << setw(40) << dateAdded << "*" << endl;
        cout << left << "*  <6> Enter Quantity on Hand        > " << setw(40) << qty << "*" << endl;
        cout << left << "*  <7> Enter Wholesale Cost          > $" << setw(39) << fixed << setprecision(2) << wholesale << "*" << endl;
        cout << left << "*  <8> Enter Retail Price            > $" << setw(39) << fixed << setprecision(2) << retail << "*" << endl;
        cout << left << "*  <9> Save Book to Database" << setw(51) << " " << "*" << endl;
        cout << left << "*  <0> Return to Inventory Menu" << setw(48) << " " << "*" << endl;
        cout << left << "*  " << setw(76) << " " << "*" << endl;

        cout << setfill('*') << setw(80) << "*" << endl;
        cout << setfill(' ');
        cout << "Choice(0-9): ";
        getline(cin, input);

        

        if (input.length() == 1 && isdigit(input[0]))
            c = input[0];
        else
            c = '0';

        switch (c){
    case '1':
    {
        cout << "Enter Book Title: ";
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, title);
        if (title.length() > 37)
            title = title.substr(0, 37);
        break;
    }

    case '2':
    {
        cout << "Enter ISBN: ";
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, isbn);
        if (isbn.length() > 13)
            isbn = isbn.substr(0, 13);
        break;
    }

    case '3':
    {
        cout << "Enter Author: ";
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, author);
        if (author.length() > 37)
            author = author.substr(0, 37);
        break;
    }

    case '4':
    {
        cout << "Enter Publisher: ";
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, publisher);
        if (publisher.length() > 37)
            publisher = publisher.substr(0, 37);
        break;
    }

    case '5':
    {
        cout << "Enter Date Added (mm/dd/yyyy): ";
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, dateAdded);
        if (dateAdded.length() > 8)
            dateAdded = dateAdded.substr(0, 8);
        break;
    }

    case '6':
    {
        cout << "Enter Quantity on Hand: ";
        while (!(cin >> qty))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    }

    case '7':
    {
        cout << "Enter Wholesale Cost: ";
        while (!(cin >> wholesale))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    }

    case '8':
    {
        cout << "Enter Retail Price: ";
        while (!(cin >> retail))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    }

    case '9':
    {
        if (bookType::getBookCount() < 20)
        {
            database.emplace_back(isbn, title, author, publisher, dateAdded, qty, wholesale, retail);
            cout << "\nBook saved successfully!";
            c = '0';
            pause();
        }
        else
        {
            cout << "\nDatabase full! Cannot save new book.";
            pause();
        }
        break;
    }

    case '0':
    {
        break;
    }

    default:
    {
        cout << "Invalid entry. Enter 0–9.";
        pause();
        break;
    }
}
} while (c != '0');
}


void editBook(){
    cout << "\x1B[2J\x1B[H";
    cout << "=== Edit a Book's Record ===\n";
    cout << "[stub] Feature not implemented yet. Press Enter to continue.\n\n";
    pause();
}

void deleteBook(){
    cout << "\x1B[2J\x1B[H";
    cout << "=== Delete a Book ===\n";
    cout << "[stub] Feature not implemented yet. Press Enter to continue.\n\n";
    pause();
}

void pause(){
  cin.get();
}
