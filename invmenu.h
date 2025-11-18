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

/**
 * @brief Displays the Inventory Menu and handles user navigation.
 * @param books Reference to the vector of book records.
 */
void invMenu(vector<bookType>& books);

/**
 * @brief Searches for a book by ISBN.
 * @param books Constant reference to the book vector.
 * @return Index of the book if found, otherwise -1.
 */
int lookUpBook(const vector<bookType>& books);

/**
 * @brief Prints all stored details of a single book.
 * @param books Constant reference to the book vector.
 * @param index Index of the selected book.
 */
void printBookDetails(const vector<bookType>& books, int index);

/**
 * @brief Adds a new book to the inventory.
 * @param books Reference to the vector of book records.
 */
void addBook(vector<bookType>& books);

/**
 * @brief Edits an existing book in the inventory.
 * @param books Reference to the vector of book records.
 */
void editBook(vector<bookType>& books);

/**
 * @brief Deletes a book from the inventory.
 * @param books Reference to the vector of book records.
 */
void deleteBook(vector<bookType>& books);

/**
 * @brief Pauses program execution until user presses Enter.
 */
void pause();

#endif

