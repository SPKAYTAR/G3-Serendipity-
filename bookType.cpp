/*********************************************************************
* CS1B – G3: Serendipity
*  Partner A: Sean Hanabusa (ID) — role: Cashier.cpp
*  Partner B: Kayden Tarvaran (ID) — role: invmenu.cpp, main.cpp, reports.cpp
*  Date: 2025‑09‑18
*  Purpose: Design and implement menu-driven input with validation for an inventory system.
*  Build:   g++ -std=c++20 mainmenu.cpp cashier.cpp invmenu.cpp reports.cpp -o serendipity
***********************************************************************/

#include "bookType.h"

int bookType::bookCount = 0;

bookType::bookType()
{
    isbn = "";
    bookTitle = "";
    author = "";
    publisher = "";
    dateAdded = "";
    qtyOnHand = 0;
    wholesale = 0.0f;
    retail = 0.0f;

    ++bookCount;
}

bookType::bookType(const string &i, const string &t, const string &a, const string &p, const string &d, int q, float w, float r)
{
    isbn = i;
    bookTitle = t;
    author = a;
    publisher = p;
    dateAdded = d;
    qtyOnHand = q;
    wholesale = w;
    retail = r;

    ++bookCount;
}

bookType::~bookType()
{
    --bookCount;
}

// Setters
void bookType::setISBN(const string &i) { 
    isbn = i; 
}
void bookType::setTitle(const string &t) { 
    bookTitle = t; 
}
void bookType::setAuthor(const string &a) { 
    author = a; 
}
void bookType::setPub(const string &p) { 
    publisher = p; 
}
void bookType::setDateAdded(const string &d) { 
    dateAdded = d; 
}
void bookType::setQtyOnHand(int q) { 
    qtyOnHand = q; 
}
void bookType::setWholesale(float w) { 
    wholesale = w; 
}
void bookType::setRetail(float r) { 
    retail = r; 
}

// Getters
string bookType::getISBN() const { 
    return isbn; 
}
string bookType::getTitle() const { 
    return bookTitle; 
}
string bookType::getAuthor() const { 
    return author; 
}
string bookType::getPub() const { 
    return publisher; 
}
string bookType::getDateAdded() const { 
    return dateAdded; 
}
int bookType::getQtyOnHand() const { 
    return qtyOnHand; 
}
float bookType::getWholesale() const { 
    return wholesale; 
}
float bookType::getRetail() const {
    return retail; 
}
int bookType::getBookCount() {
    return bookCount; 
    }

// Other
void bookType::print() const
{
    cout << "Title: " << bookTitle << endl;
    cout << "Author: " << author << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Date Added: " << dateAdded << endl;
    cout << "Quantity: " << qtyOnHand << endl;
    cout << "Wholesale: $" << wholesale << endl;
    cout << "Retail: $" << retail << endl;
}

bool bookType::equals(const bookType &b) const
{
    return isbn == b.isbn;
}