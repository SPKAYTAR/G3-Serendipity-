/*********************************************************************
* CS1B – G2: Serendipity
*  Partner A: Sean Hanabusa (ID) — role: Cashier.cpp
*  Partner B: Kayden Tarvaran (ID) — role: invmenu.cpp, main.cpp, reports.cpp
*  Date: 2025‑09‑18
*  Purpose: Menu navigation and validation practice: loop Main/Inventory/Reports, call function stubs, and print a two-decimal cashier test receipt
*  Build:   g++ -std=c++20 mainmenu.cpp cashier.cpp invmenu.cpp reports.cpp -o serendipity
***********************************************************************/

#ifndef INVMENU_H
#define INVMENU_H

#include <vector>
#include "bookType.h"

using namespace std;

void invMenu(vector<bookType>& books);

int lookUpBook(const vector<bookType>& books);

void printBookDetails(const vector<bookType>& books, int index);

void addBook(vector<bookType>& books);

void editBook(vector<bookType>& books);

void deleteBook(vector<bookType>& books);

void pause();

#endif
