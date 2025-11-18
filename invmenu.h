/*********************************************************************
* CS1B – G4: Serendipity
*  Partner A: Kayden Tarvaran (1250210) — 
*  Date: 2025‑011‑17
*  Purpose: Complete the Inventory features Edit Book and Delete Book using either a std::vector<bookType> or a raw array bookType books[] 
*  with a num_records counter. Document the project with Doxygen and demo your work in class.
*  Build:   g++ -std=c++20 mainmenu.cpp bookType.cpp cashier.cpp invmenu.cpp reports.cpp -o serendipity
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

