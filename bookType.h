/*********************************************************************
* CS1B – G4: Serendipity
*  Partner A: Kayden Tarvaran (1250210) — 
*  Date: 2025‑011‑17
*  Purpose: Complete the Inventory features Edit Book and Delete Book using either a std::vector<bookType> or a raw array bookType books[] 
*  with a num_records counter. Document the project with Doxygen and demo your work in class.
*  Build:   g++ -std=c++20 mainmenu.cpp bookType.cpp cashier.cpp invmenu.cpp reports.cpp -o serendipity
***********************************************************************/

#ifndef BOOKTYPE_H
#define BOOKTYPE_H

#include <string>
#include <iostream>
using namespace std;

/**
 * @class bookType
 * @brief Represents a single book record in the Serendipity inventory.
 *
 * @details
 * Stores ISBN, title, author, publisher, date added, quantity,
 * wholesale cost, and retail price.  
 *
 * **Class Invariants:**
 * - ISBN is a string up to 13 characters (preserve leading zeros).
 * - qtyOnHand ≥ 0  
 * - wholesale ≥ 0.0  
 * - retail ≥ 0.0  
 * - bookCount tracks how many bookType objects exist.
 *
 * This class provides full getters/setters with validation and is
 * used by the Inventory Database (Add/Edit/Delete).
 */
class bookType
{
private:
    string isbn;        ///< ISBN (max 13 chars)
    string bookTitle;   ///< Book title string
    string author;      ///< Author name
    string publisher;   ///< Publisher name
    string dateAdded;   ///< Date book was added to inventory
    int qtyOnHand;      ///< Quantity currently in stock (>= 0)
    float wholesale;    ///< Wholesale cost per unit (>= 0.0)
    float retail;       ///< Retail price per unit (>= 0.0)

    static int bookCount;   ///< Tracks total number of books created

public:

    /**
     * @brief Default constructor.
     * @post All fields set to default values; bookCount incremented.
     */
    bookType();

    /**
     * @brief Full constructor for initializing a book record.
     * @param isbn Book ISBN (string, leading zeros allowed).
     * @param title Book title.
     * @param author Author name.
     * @param publisher Publisher name.
     * @param dateAdded Date added to inventory.
     * @param qty Stock quantity (must be >= 0).
     * @param wholesale Wholesale cost (>= 0.0).
     * @param retail Retail price (>= 0.0).
     *
     * @pre qty >= 0, wholesale >= 0.0, retail >= 0.0
     * @post Object created with given fields; bookCount incremented.
     */
    bookType(const string &isbn, const string &title,
             const string &author, const string &publisher,
             const string &dateAdded, int qty,
             float wholesale, float retail);

    /**
     * @brief Destructor.
     * @post bookCount decremented.
     */
    ~bookType();

    /** @brief Sets ISBN. @pre none @post isbn updated. */
    void setISBN(const string &);

    /** @brief Sets book title. @pre none @post title updated. */
    void setTitle(const string &);

    /** @brief Sets author. @pre none @post author updated. */
    void setAuthor(const string &);

    /** @brief Sets publisher. @pre none @post publisher updated. */
    void setPub(const string &);

    /** @brief Sets date added. @pre none @post date updated. */
    void setDateAdded(const string &);

    /**
     * @brief Sets quantity in stock.
     * @param qty must be >= 0
     * @pre qty >= 0
     * @post qtyOnHand updated
     */
    void setQtyOnHand(int qty);

    /**
     * @brief Sets wholesale price.
     * @param wholesale must be >= 0.0
     * @pre wholesale >= 0.0
     * @post wholesale updated
     */
    void setWholesale(float wholesale);

    /**
     * @brief Sets retail price.
     * @param retail must be >= 0.0
     * @pre retail >= 0.0
     * @post retail updated
     */
    void setRetail(float retail);

    /** @return Current ISBN. */
    string getISBN() const;

    /** @return Current title. */
    string getTitle() const;

    /** @return Current author. */
    string getAuthor() const;

    /** @return Current publisher. */
    string getPub() const;

    /** @return Current date added. */
    string getDateAdded() const;

    /** @return Quantity in stock. */
    int getQtyOnHand() const;

    /** @return Wholesale cost. */
    float getWholesale() const;

    /** @return Retail price. */
    float getRetail() const;

    /**
     * @brief Gets total number of bookType objects created.
     * @return bookCount value.
     */
    static int getBookCount();

    /**
     * @brief Prints the book fields (for debugging/demo).
     * @post Outputs formatted fields to stdout.
     */
    void print() const;

    /**
     * @brief Compares two books for equality.
     * @param b Another bookType object.
     * @return true if all fields match; false otherwise.
     */
    bool equals(const bookType &b) const;
};

#endif
