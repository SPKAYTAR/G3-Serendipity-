/*********************************************************************
* CS1B – G2: Serendipity
*  Partner A: Sean Hanabusa (ID) — role: Cashier.cpp
*  Partner B: Kayden Tarvaran (ID) — role: invmenu.cpp, main.cpp, reports.cpp
*  Date: 2025‑09‑18
*  Purpose: Menu navigation and validation practice: loop Main/Inventory/Reports, call function stubs, and print a two-decimal cashier test receipt
*  Build:   g++ -std=c++20 mainmenu.cpp cashier.cpp invmenu.cpp reports.cpp -o serendipity
***********************************************************************/

#include <iostream>
#include <iomanip>
#include <cctype>
#include <vector>
#include <limits>
#include <string>
using namespace std;
struct bookType {
  string date;
  int quantity;
  string isbn;
  string title;
  double price;
};
void displayCashier(const bookType& book, double subtotal, double tax, double total);
bookType getBookInfo();
void cashier()
{
   cout << "\033[H\033[2J" << endl;
   bookType book = getBookInfo();


    double subtotal = book.quantity * book.price;
    double tax      = subtotal * 0.06;
    double total    = subtotal + tax;
 
    displayCashier(book, subtotal, tax, total);
    string exitString;
    cout << endl << endl << "Press ENTER to return to the main menu...";
    cin.ignore();
    getline(cin, exitString); // waits for user to press Enter
}

bookType getBookInfo()
{
    bookType book;
    cout << "Serendipity Book Sellers" << endl;
    cout << "Cashier Module" << endl;

    cout << "Date: ";
	 if (cin.peek() == '\n') cin.ignore();
    getline(cin, book.date);
	 if(book.date.length() > 8){
	 book.date = book.date.substr(0,8);
	 }
    
  
    cout << "Quantity: ";
    cin >> book.quantity;
    cin.ignore(); // clear leftover newline

    cout << "ISBN: ";
    getline(cin, book.isbn);
    book.isbn = book.isbn.substr(0, 13);

    cout << "Title: ";
    getline(cin, book.title);
	 if (book.title.length() > 37){
    book.title = book.title.substr(0, 37);
	 }

    cout << "Price: $";
    cin >> book.price;

    
    return book;
}
void displayCashier(const bookType& book, double subtotal, double tax, double total)
{
  cout << "\033[H\033[2J" << endl;
  cout << left;
  auto oldFlags = cout.flags();       // save current flags
  auto oldPrecision = cout.precision();
  cout << setw(80) << string(80, '-') << endl;
  cout << setw(79) << '-' << '-' << endl;
  cout << '-' << setw(24) << "Serendipity Book Sellers" << setw(54) << string(54, ' ') << '-' << endl;
  cout << setw(79) << '-' << '-' << endl;
  cout << '-' << "Date: " << setw(8) << book.date << setw(64) << string(64, ' ') << '-' << endl;
  cout << '-' << setw(78) << "QTY  ISBN          TITLE                                 Price       Total" << '-' << endl; 
  cout << setw(80) << string(80, '-') << endl;
  //Output book information
  cout << '-' << right << setw(3) << book.quantity << "  " << left << setw(13) << book.isbn << " " << setw(37) << book.title;
  cout << fixed << setprecision(2) << showpoint << " $" << right << setw(7) << book.price;
  double singleTotal = book.quantity * book.price;
  cout << "    $" << setw(7) << singleTotal << " -" << endl;
  //Reset flags
  cout.flags(oldFlags);
  cout.precision(oldPrecision);
  //Empty Lines after book information
  cout << left;
  cout << setw(79) << '-' << '-' << endl;
  cout << setw(79) << '-' << '-' << endl;
  cout << fixed << setprecision(2) << showpoint;
  cout << setw(58) << '-' << setw(12) << "Subtotal" << "$" << setw(7) << right << subtotal << " -" << endl;
  cout << left << setw(58) << '-' << setw(12) << "Tax" << "$" << setw(7) << right << tax << " -" << endl;
  cout << left << setw(58) << '-' << setw(12) << "Total"  << "$" << setw(7) << right << total << " -" << endl;
  cout << left;
  cout << setw(79) << '-' << '-' << endl;
  cout << "- " << "Thank You For Shopping At Serendipity!" << string(39, ' ') << '-' << endl;
  return;
}
