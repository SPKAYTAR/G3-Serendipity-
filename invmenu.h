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
 * @file invmenu.h
 * @brief Declarations for the Inventory module in Serendipity Booksellers.
 *
 * This module provides functions for:
 * - Searching for books (lookUpBook)
 * - Displaying book details
 * - Adding, editing, and deleting books
 * - Handling user input and menu navigation
 *
 * Duplicate ISBNs are blocked during add/edit operations.
 */

/**
 * @brief Displays the Inventory Menu and handles user navigation.
 * @param books Reference to the vector of book records.
 * @post Menu loops until the user chooses to return to the main menu.
 */
void invMenu(vector<bookType>& books);

/**
 * @brief Searches for a book by partial, case-insensitive title or ISBN.
 * @param books Constant reference to the vector of book records.
 * @return Index of the selected book in the vector, or -1 if canceled or not found.
 * @post No modification to the vector.
 */
int lookUpBook(const vector<bookType>& books);

/**
 * @brief Prints the full details of a single book.
 * @param books Constant reference to the vector of book records.
 * @param index Index of the selected book in the vector.
 * @pre index >= 0 and < books.size()
 * @post No modification to the vector.
 */
void printBookDetails(const vector<bookType>& books, int index);

/**
 * @brief Adds a new book to the inventory.
 * @param books Reference to the vector of book records.
 * @pre ISBN must be unique in the vector.
 * @post A new book is appended to the vector if there is space.
 */
void addBook(vector<bookType>& books);

/**
 * @brief Edits an existing book in the inventory using a menu-driven interface.
 * @param books Reference to the vector of book records.
 * @pre books.size() > 0
 * @post Updates are applied only after the user chooses "Save"; cancel discards changes.
 *       ISBN duplicates are blocked and reset automatically.
 */
void editBook(vector<bookType>& books);

/**
 * @brief Deletes a book from the inventory after user confirmation.
 * @param books Reference to the vector of book records.
 * @pre books.size() > 0
 * @post Selected book is removed from the vector and the vector is compacted.
 */
void deleteBook(vector<bookType>& books);

/**
 * @brief Pauses program execution until the user presses Enter.
 * @post Execution resumes after Enter is pressed.
 */
void pause();

#endif // INVMENU_H
