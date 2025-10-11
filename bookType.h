/*********************************************************************
* CS1B – G3: Serendipity
*  Partner A: Sean Hanabusa (ID) — role: Cashier.cpp
*  Partner B: Kayden Tarvaran (ID) — role: invmenu.cpp, main.cpp, reports.cpp
*  Date: 2025‑09‑18
*  Purpose: Design and implement menu-driven input with validation for an inventory system.
*  Build:   g++ -std=c++20 mainmenu.cpp cashier.cpp invmenu.cpp reports.cpp -o serendipity
***********************************************************************/

#ifndef BOOKTYPE_H
#define BOOKTYPE_H

#include <string>
#include <iostream>
using namespace std;

class bookType
{
private:
    string isbn;
    string bookTitle;
    string author;
    string publisher;
    string dateAdded;
    int qtyOnHand;
    float wholesale;
    float retail;

    static int bookCount;

public:
    bookType();
    bookType(const string &isbn, const string &title,
             const string &author, const string &publisher,
             const string &dateAdded, int qty,
             float wholesale, float retail);
    ~bookType();

    void setISBN(const string &);
    void setTitle(const string &);
    void setAuthor(const string &);
    void setPub(const string &);
    void setDateAdded(const string &);
    void setQtyOnHand(int);
    void setWholesale(float);
    void setRetail(float);

    string getISBN() const;
    string getTitle() const;
    string getAuthor() const;
    string getPub() const;
    string getDateAdded() const;
    int getQtyOnHand() const;
    float getWholesale() const;
    float getRetail() const;
    static int getBookCount();

    void print() const;
    bool equals(const bookType &b) const;
};

#endif