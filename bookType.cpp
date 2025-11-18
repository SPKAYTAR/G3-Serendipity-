/*********************************************************************
* CS1B – G3: Serendipity
*  Partner A: Sean Hanabusa (ID) — role: Cashier.cpp
*  Partner B: Kayden Tarvaran (ID) — role: invmenu.cpp, main.cpp, reports.cpp
*  Date: 2025‑09‑18
*  Purpose: Design and implement menu-driven input with validation for an inventory system.
*  Build:   g++ -std=c++20 mainmenu.cpp bookType.cpp cashier.cpp invmenu.cpp reports.cpp -o serendipity
***********************************************************************/

/**
 * @file bookType.cpp
 * @brief Implementation for the bookType class.
 */

#include "bookType.h"

int bookType::bookCount = 0;

/**
 * @brief Default constructor.
 * @post All fields initialized to empty/zero and bookCount incremented.
 */
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

/**
 * @brief Fully initializing constructor.
 * 
 * @param i ISBN
 * @param t Title
 * @param a Author
 * @param p Publisher
 * @param d Date added
 * @param q Quantity on hand (must be >= 0)
 * @param w Wholesale cost (must be >= 0)
 * @param r Retail cost (must be >= 0)
 *
 * @pre q >= 0, w >= 0.0, r >= 0.0
 * @post All fields copied and object count incremented.
 */
bookType::bookType(const string &i, const string &t, const string &a,
                   const string &p, const string &d,
                   int q, float w, float r)
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

/**
 * @brief Destructor.
 * @post bookCount decremented.
 */
bookType::~bookType()
{
    bookCount--;
}

// ========================== SETTERS =========================== //

/** @brief Sets ISBN. */
void bookType::setISBN(const string &i) {
    isbn = i;
}

/** @brief Sets title. */
void bookType::setTitle(const string &t) {
    bookTitle = t;
}

/** @brief Sets author. */
void bookType::setAuthor(const string &a) {
    author = a;
}

/** @brief Sets publisher. */
void bookType::setPub(const string &p) {
    publisher = p;
}

/** @brief Sets date added. */
void bookType::setDateAdded(const string &d) {
    dateAdded = d;
}

/**
 * @brief Sets quantity on hand.
 * @param q must be >= 0
 * @pre q >= 0
 * @post qtyOnHand updated.
 */
void bookType::setQtyOnHand(int q) {
    qtyOnHand = q;
}

/**
 * @brief Sets wholesale price.
 * @param w must be >= 0
 * @pre w >= 0
 * @post wholesale updated.
 */
void bookType::setWholesale(float w) {
    wholesale = w;
}

/**
 * @brief Sets retail price.
 * @param r must be >= 0
 * @pre r >= 0
 * @post retail updated.
 */
void bookType::setRetail(float r) {
    retail = r;
}

// ========================== GETTERS =========================== //

/** @return ISBN string. */
string bookType::getISBN() const {
    return isbn;
}

/** @return Book title. */
string bookType::getTitle() const {
    return bookTitle;
}

/** @return Author name. */
string bookType::getAuthor() const {
    return author;
}

/** @return Publisher name. */
string bookType::getPub() const {
    return publisher;
}

/** @return Date book was added. */
string bookType::getDateAdded() const {
    return dateAdded;
}

/** @return Quantity in stock. */
int bookType::getQtyOnHand() const {
    return qtyOnHand;
}

/** @return Wholesale cost. */
float bookType::getWholesale() const {
    return wholesale;
}

/** @return Retail price. */
float bookType::getRetail() const {
    return retail;
}

/**
 * @brief Returns global object count.
 * @return number of active bookType objects.
 */
int bookType::getBookCount() {
    return bookCount;
}

// ====================== OTHER METHODS ====================== //

/**
 * @brief Prints all book fields (debugging).
 */
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

/**
 * @brief Checks if two books are equal by ISBN.
 * @param b Another bookType
 * @return true if ISBN is identical.
 */
bool bookType::equals(const bookType &b) const
{
    return isbn == b.isbn;
}
