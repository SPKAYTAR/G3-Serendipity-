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

#include "bookType.h"   // ← now using the real class

void displayCashier(const bookType& book, double subtotal, double tax, double total);
bookType getBookInfo();

void cashier()
{
    cout << "\033[H\033[2J" << endl;

    bookType book = getBookInfo();   // now compatible

    double subtotal = book.getQtyOnHand() * book.getRetail();
    double tax      = subtotal * 0.06;
    double total    = subtotal + tax;

    displayCashier(book, subtotal, tax, total);

    string exitString;
    cout << endl << endl << "Press ENTER to return to the main menu...";
    cin.ignore();
    getline(cin, exitString);
}

bookType getBookInfo()
{
    bookType book;

    string date, isbn, title;
    int quantity;
    double price;

    cout << "Serendipity Book Sellers" << endl;
    cout << "Cashier Module" << endl;

    cout << "Date: ";
    if (cin.peek() == '\n') cin.ignore();
    getline(cin, date);
    if (date.length() > 8) date = date.substr(0, 8);
    book.setDateAdded(date);

    cout << "Quantity: ";
    cin >> quantity;
    cin.ignore();
    book.setQtyOnHand(quantity);

    cout << "ISBN: ";
    getline(cin, isbn);
    if (isbn.length() > 13) isbn = isbn.substr(0, 13);
    book.setISBN(isbn);

    cout << "Title: ";
    getline(cin, title);
    if (title.length() > 37) title = title.substr(0, 37);
    book.setTitle(title);

    cout << "Price: $";
    cin >> price;
    cin.ignore();
    book.setRetail(price);

    return book;
}

void displayCashier(const bookType& book, double subtotal, double tax, double total)
{
    cout << setfill(' ');   // reset fill

    cout << "\033[H\033[2J" << endl;
    cout << left;

    auto oldFlags = cout.flags();
    auto oldPrecision = cout.precision();

    cout << setw(80) << string(80, '-') << endl;
    cout << setw(79) << '-' << '-' << endl;
    cout << '-' << setw(24) << "Serendipity Book Sellers" << setw(54) << string(54, ' ') << '-' << endl;
    cout << setw(79) << '-' << '-' << endl;

    cout << '-' << "Date: " << setw(8) << book.getDateAdded()
         << setw(64) << string(64, ' ') << '-' << endl;

    cout << '-' << setw(78)
         << "QTY  ISBN          TITLE                                 Price       Total"
         << '-' << endl;

    cout << setw(80) << string(80, '-') << endl;

    // ==== OUTPUT BOOK INFO ====
    cout << '-' << right << setw(3) << book.getQtyOnHand()
         << "  " << left << setw(13) << book.getISBN()
         << " " << setw(37) << book.getTitle();

    cout << fixed << setprecision(2) << showpoint
         << " $" << right << setw(7) << book.getRetail();

    double singleTotal = book.getQtyOnHand() * book.getRetail();

    cout << "    $" << setw(7) << singleTotal << " -" << endl;

    // ==== RESET FLAGS ====
    cout.flags(oldFlags);
    cout.precision(oldPrecision);

    cout << left;
    cout << setw(79) << '-' << '-' << endl;
    cout << setw(79) << '-' << '-' << endl;

    cout << fixed << setprecision(2) << showpoint;

    cout << setw(58) << '-' << setw(12) << "Subtotal"
         << "$" << setw(7) << right << subtotal << " -" << endl;

    cout << left << setw(58) << '-' << setw(12) << "Tax"
         << "$" << setw(7) << right << tax << " -" << endl;

    cout << left << setw(58) << '-' << setw(12) << "Total"
         << "$" << setw(7) << right << total << " -" << endl;

    cout << left;
    cout << setw(79) << '-' << '-' << endl;
    cout << "- " << "Thank You For Shopping At Serendipity!"
         << string(39, ' ') << '-' << endl;
}
