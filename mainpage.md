/**


@mainpage G4 — Serendipity Booksellers

# Overview
Serendipity Booksellers is a menu-driven C++ program used to practice 
navigation, validation, and modular design. It simulates a small bookstore 
system with three modules: Cashier, Inventory, and Reports.  
G4 extends the project by completing the Inventory module with **Edit Book** 
and **Delete Book** functionality and full Doxygen documentation.

# Features Implemented
- Menu navigation across Main, Cashier, Inventory, and Reports.
- Inventory stored using `std::vector<bookType>`.
- Partial, case-insensitive search by Title or ISBN.
- Edit Book with staged changes and input validation.
- Delete Book with confirmation and automatic vector compaction.
- Duplicate ISBN protection (blocked and reset immediately).
- Full cancel paths in search, edit, and delete flows.

# Inventory Rules (Contracts)
- Quantity must be **≥ 0**.  
- Wholesale and retail prices must be **≥ 0.0**.  
- ISBN stored as a **string** to preserve leading zeros.  
- **Duplicate ISBNs are not allowed.**  
  If a duplicate is entered during editing, the program warns the user and 
  resets the field. The user must enter a unique ISBN before saving.  
- No changes are applied until the user selects **Save**.  
- Cancel always discards staged edits.

# Edit Book
1. Search using `lookUpBook`.  
2. Show the selected record.  
3. Menu options allow editing:  
   Title, ISBN, Author, Publisher, Date Added, Quantity, Wholesale, Retail.  
4. Validate inputs after each change.  
5. Save applies all staged changes; Cancel discards them.  
6. After finishing, the user can edit another book or return to Inventory.

# Delete Book
1. Search using `lookUpBook`.  
2. Print full book details.  
3. Ask for delete confirmation.  
4. If confirmed, remove the book using `vector.erase()` and compact the list.  
5. After deletion, the user may delete another or return to Inventory.

# Search (lookUpBook)
- Case-insensitive matching.  
- Matches on both Title and ISBN (partial allowed).  
- Displays all matches and lets the user select an index.  
- Returns **-1** for cancel or no results.

# Data Structure
This project uses:  
**`std::vector<bookType>`**  
- No fixed capacity.  
- Gaps removed automatically using `erase()`.  
- Passed by reference to all Inventory functions.  
- No global variables.

# Build Instructions
Compile the program with:
