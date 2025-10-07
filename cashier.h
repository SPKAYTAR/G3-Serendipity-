/*********************************************************************
* CS1B – G2: Serendipity
*  Partner A: Sean Hanabusa (ID) — role: Cashier.cpp
*  Partner B: Kayden Tarvaran (ID) — role: invmenu.cpp, main.cpp, reports.cpp
*  Date: 2025‑09‑18
*  Purpose: Menu navigation and validation practice: loop Main/Inventory/Reports, call function stubs, and print a two-decimal cashier test receipt
*  Build:   g++ -std=c++20 mainmenu.cpp cashier.cpp invmenu.cpp reports.cpp -o serendipity
***********************************************************************/
#ifndef CASHIER_H
#define CASHIER_H
#include <iostream>
#include <iomanip>
#include <cctype>
#include <vector>
#include <limits>
#include <string>
using namespace std;  

struct bookType {
  string date;
  int    quantity;
  string isbn;
  string title;
  double price;
};

bookType getBookInfo();
void displayCashier(const bookType& book, double subtotal, double tax, double total);
void cashier();

#endif