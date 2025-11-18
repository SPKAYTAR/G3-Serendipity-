/*********************************************************************
* CS1B – G4: Serendipity
*  Partner A: Kayden Tarvaran (1250210) — 
*  Date: 2025‑011‑17
*  Purpose: Complete the Inventory features Edit Book and Delete Book using either a std::vector<bookType> or a raw array bookType books[] 
*  with a num_records counter. Document the project with Doxygen and demo your work in class.
*  Build:   g++ -std=c++20 mainmenu.cpp bookType.cpp cashier.cpp invmenu.cpp reports.cpp -o serendipity
***********************************************************************/
#include <iostream>
#include <iomanip>
#include <cctype>
#include <vector>
#include <limits>
#include <sstream>
using namespace std;

#include "invmenu.h"
#include "bookType.h"

const int DATABASE_SIZE = 20;

// ========================= INV MENU ========================= //

void invMenu(vector<bookType>& books){
    string input;
    char c;

    do {
        c = '0';
        cout << "\033[H\033[J" << flush;

        cout << setfill('*') << setw(80) << "*" << endl; 
        cout << setfill(' ');
        cout << "*" << setw(78) << " " << "*" << endl;
        cout << left << "*  " << setw(76) << "Serendipity Booksellers" << "*" << endl;
        cout << left << "*  " << setw(76) << "Inventory Database" << "*" << endl;
        cout << "*" << setw(78) << " " << "*" << endl;
        cout << left << "*  " << setw(76) << "------------------------------" << "*" << endl;
        cout << left << "*  " << setw(76) << "1. Look Up a Book" << "*" << endl;
        cout << left << "*  " << setw(76) << "2. Add a Book" << "*" << endl;
        cout << left << "*  " << setw(76) << "3. Edit a Book's Record" << "*" << endl;
        cout << left << "*  " << setw(76) << "4. Delete a Book" << "*" << endl;
        cout << left << "*  " << setw(76) << "5. Return to Main Menu" << "*" << endl;
        cout << left << "*  " << setw(76) << "------------------------------" << "*" << endl;
        cout << left << "*  " << setw(76) << "Enter choice:" << "*" << endl;
        cout << setfill('*') << setw(80) << "*" << endl;

        cout << "\x1B[2A";
        cout << "\x1B[16C";

        getline(cin, input);
        if (input.length() == 1 && isdigit(input[0]))
            c = input[0];

        switch(c){

            case '1': {
                if (books.size() == 0){
                    cout << "\x1B[2J\x1B[H";
                    cout << "No books in database. Press Enter.";
                    pause();
                    break;
                }
                int loc = lookUpBook(books);
                printBookDetails(books, loc);
                break;
            }

            case '2': {
                addBook(books);
                break;
            }

            case '3': {
                editBook(books);
                break;
            }

            case '4': {
                deleteBook(books);
                break;
            }

            case '5':
                break;

            default:
                cout << "\x1B[2J\x1B[H";
                cout << "Invalid choice. Press Enter.";
                pause();
        }

    } while (c != '5');
}


// ========================= LOOK UP BOOK ========================= //

int lookUpBook(const vector<bookType>& books){
    string target, title, isbn;
    vector<int> matches;
    int choice;

    cout << "\x1B[2J\x1B[H";
    cout << setfill('*') << setw(80) << "*" << endl;
    cout << setfill(' ');
    cout << left << "*  " << setw(76) << "SERENDIPITY BOOKSELLERS" << "*" << endl;
    cout << left << "*  " << setw(76) << "LOOK UP BOOK" << "*" << endl;
    cout << left << "*  " << setw(76) << "----------------------------------------" << "*" << endl;
    cout << left << "*  " << setw(76) << "Enter Book Title or ISBN:" << "*" << endl;
    cout << setfill('*') << setw(80) << "*" << endl;

    cout << "\x1B[2A";
    cout << "\x1B[34C";

    getline(cin, target);
    if (target.empty()) return -1;

    for (char &c : target) c = tolower(c);

    for (int i = 0; i < (int)books.size(); i++){
        title = books[i].getTitle();
        isbn  = books[i].getISBN();

        for (char &c : title) c = tolower(c);
        for (char &c : isbn)  c = tolower(c);

        if (title.find(target) != string::npos || isbn.find(target) != string::npos)
            matches.push_back(i);
    }

    if (matches.empty()){
        cout << "\x1B[2J\x1B[H";
        cout << "Item not found. Press Enter.";
        pause();
        return -1;
    }

    bool bad = false;

    while (true){
        cout << "\x1B[2J\x1B[H";
        cout << setfill('*') << setw(80) << "*" << endl;
        cout << setfill(' ');
        cout << left << "*  " << setw(76) << "Matching Books:" << "*" << endl;

        for (int i = 0; i < matches.size(); i++){
            string shortTitle = books[matches[i]].getTitle().substr(0, 50);
            cout << left << "*     " << setw(73)
                 << (to_string(i) + ". " + shortTitle) << "*" << endl;
        }

        cout << left << "*  " << setw(76)
             << "Enter Choice (-1 to Exit):" << "*" << endl;

        cout << setfill('*') << setw(80) << "*" << endl;
        cout << setfill(' ');

        if (bad){
            cout << "Invalid input.\n";
            bad = false;
        }

        cout << "\x1B[2A";
        cout << "\x1B[35C";

        if (!(cin >> choice)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            bad = true;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        if (choice == -1) return -1;
        if (choice < 0 || choice >= matches.size()){
            bad = true;
            continue;
        }

        return matches[choice];
    }
}


// ========================= PRINT BOOK ========================= //

void printBookDetails(const vector<bookType>& books, int index){
    if (index < 0 || index >= (int)books.size()){
        cout << "\x1B[2J\x1B[H";
        cout << "No book selected. Press Enter.";
        pause();
        return;
    }

    const auto& b = books[index];

    cout << "\x1B[2J\x1B[H";
    cout << setfill('*') << setw(80) << "*" << endl;
    cout << setfill(' ');
    cout << left << "*  " << setw(76) << "BOOK DETAILS" << "*" << endl;
    cout << left << "*  " << setw(76) << ("Title: " + b.getTitle()) << "*" << endl;
    cout << left << "*  " << setw(76) << ("Author: " + b.getAuthor()) << "*" << endl;
    cout << left << "*  " << setw(76) << ("ISBN: " + b.getISBN()) << "*" << endl;
    cout << left << "*  " << setw(76) << ("Publisher: " + b.getPub()) << "*" << endl;
    cout << left << "*  " << setw(76) << ("Date Added: " + b.getDateAdded()) << "*" << endl;

    ostringstream q, w, r;
    q << "Quantity: " << b.getQtyOnHand();
    w << fixed << setprecision(2) << "Wholesale: $" << b.getWholesale();
    r << fixed << setprecision(2) << "Retail: $" << b.getRetail();

    cout << left << "*  " << setw(76) << q.str() << "*" << endl;
    cout << left << "*  " << setw(76) << w.str() << "*" << endl;
    cout << left << "*  " << setw(76) << r.str() << "*" << endl;

    cout << setfill('*') << setw(80) << "*" << endl;
    cout << "Press Enter.";
    pause();
}


// ========================= ADD BOOK ========================= //

void addBook(vector<bookType>& books){
    if (books.size() >= DATABASE_SIZE){
        cout << "\x1B[2J\x1B[H";
        cout << "DATABASE FULL. Press Enter.";
        pause();
        return;
    }

    string title="--EMPTY", isbn="--EMPTY", author="--EMPTY",
           publisher="--EMPTY", dateAdded="--EMPTY";
    int qty=0;
    float wholesale=0, retail=0;

    string input;
    char c='0';

    do {
        cout << "\x1B[2J\x1B[H";

        cout << setfill('*') << setw(80) << "*" << endl;
        cout << setfill(' ');

        cout << left << "*  " << setw(76) << "ADD BOOK" << "*" << endl;
        cout << "*  " << setw(76)
             << ("CURRENT BOOK COUNT: " + to_string(books.size()))
             << "*" << endl;

        cout << left << "*  <1> Title                 > " << setw(48) << title     << "*" << endl;
        cout << left << "*  <2> ISBN                  > " << setw(48) << isbn      << "*" << endl;
        cout << left << "*  <3> Author                > " << setw(48) << author    << "*" << endl;
        cout << left << "*  <4> Publisher             > " << setw(48) << publisher << "*" << endl;
        cout << left << "*  <5> Date Added            > " << setw(48) << dateAdded << "*" << endl;
        cout << left << "*  <6> Quantity on Hand      > " << setw(48) << qty       << "*" << endl;
        cout << left << "*  <7> Wholesale Cost        > $" << setw(47) << wholesale << "*" << endl;
        cout << left << "*  <8> Retail Price          > $" << setw(47) << retail    << "*" << endl;
        cout << left << "*  <9> SAVE"                     << setw(68) << " "        << "*" << endl;
        cout << left << "*  <0> CANCEL"                   << setw(66) << " "        << "*" << endl;


        cout << setfill('*') << setw(80) << "*" << endl;
        cout << setfill(' ');

        cout << "Choice (0–9): ";
        getline(cin,input);

        if (input.length() == 1 && isdigit(input[0]))
            c = input[0];
        else {
            cout << "Invalid. Press Enter.";
            pause();
            continue;
        }

        switch(c){

            case '1':
                cout << "Enter Title: ";
                getline(cin, title);
                title = title.substr(0, 37);
                break;


            case '2': {
                cout << "Enter ISBN: ";
                getline(cin,isbn);
                if (isbn.length()>13) isbn=isbn.substr(0,13);

                for (auto &b : books){
                    if (b.getISBN() == isbn){
                        cout << "ERROR: Duplicate ISBN.\nPress Enter.";
                        pause();
                        isbn="--EMPTY";
                        break;
                    }
                }
                break;
            }

            case '3':
                cout << "Enter Author: ";
                getline(cin,author);
                author = author.substr(0, 37);
                break;

            case '4':
                cout << "Enter Publisher: ";
                getline(cin,publisher);
                publisher = publisher.substr(0, 37);
                break;

            case '5':
                cout << "Enter Date Added: ";
                getline(cin,dateAdded);
                dateAdded = dateAdded.substr(0, 9);
                break;

            case '6':
                cout << "Quantity: ";
                while (!(cin >> qty)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Invalid. Enter number: ";
                }
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                break;

            case '7':
                cout << "Wholesale: ";
                while (!(cin >> wholesale)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Invalid. Enter number: ";
                }
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                break;

            case '8':
                cout << "Retail: ";
                while (!(cin >> retail)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Invalid. Enter number: ";
                }
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                break;

            case '9':
            if (bookType::getBookCount() < DATABASE_SIZE)
            {
                books.emplace_back(isbn, title, author, publisher, dateAdded, qty, wholesale, retail);
                title = "--EMPTY";
                isbn = "--EMPTY";
                author = "--EMPTY";
                publisher = "--EMPTY";
                dateAdded = "--EMPTY";
                qty = 0;
                wholesale = 0.0f;
                retail = 0.0f;
           
            }
            else
            {
                cout << "\nDatabase full! Cannot save new book.";
                pause();
            }
        break;

            case '0':
                return;
        }

    } while (c != '0');
}


// ========================= EDIT / DELETE STUB ========================= //

void editBook(vector<bookType>& books){
    if (books.size() == 0){
        cout << "\x1B[2J\x1B[H";
        cout << "No books in database. Press Enter.";
        pause();
        return;
    }

    // Step 1 — Select book
    int index = lookUpBook(books);
    if (index < 0) return;

    // Grab reference to book
    bookType &bk = books[index];

    // Load current values
    string title      = bk.getTitle();
    string isbn       = bk.getISBN();
    string author     = bk.getAuthor();
    string publisher  = bk.getPub();
    string dateAdded  = bk.getDateAdded();
    int qty           = bk.getQtyOnHand();
    float wholesale   = bk.getWholesale();
    float retail      = bk.getRetail();

    string input;
    char c = '0';

    // Step 2 — Menu loop
    do {
        cout << "\x1B[2J\x1B[H";

        cout << setfill('*') << setw(80) << "*" << endl;
        cout << setfill(' ');

        cout << left << "*  " << setw(76) << "EDIT BOOK" << "*" << endl;
        cout << "*  " << setw(76)
             << ("EDITING: " + title.substr(0,40)) 
             << "*" << endl;

        cout << left << "*  <1> Title                 > " << setw(48) << title     << "*" << endl;
        cout << left << "*  <2> ISBN                  > " << setw(48) << isbn      << "*" << endl;
        cout << left << "*  <3> Author                > " << setw(48) << author    << "*" << endl;
        cout << left << "*  <4> Publisher             > " << setw(48) << publisher << "*" << endl;
        cout << left << "*  <5> Date Added            > " << setw(48) << dateAdded << "*" << endl;
        cout << left << "*  <6> Quantity on Hand      > " << setw(48) << qty       << "*" << endl;
        cout << left << "*  <7> Wholesale Cost        > $" << setw(47) << wholesale << "*" << endl;
        cout << left << "*  <8> Retail Price          > $" << setw(47) << retail    << "*" << endl;
        cout << left << "*  <9> SAVE CHANGES"            << setw(60) << " "         << "*" << endl;
        cout << left << "*  <0> CANCEL"                  << setw(66) << " "         << "*" << endl;

        cout << setfill('*') << setw(80) << "*" << endl;
        cout << setfill(' ');

        cout << "Choice (0–9): ";
        getline(cin, input);

        if (input.length() == 1 && isdigit(input[0]))
            c = input[0];
        else {
            cout << "Invalid. Press Enter.";
            pause();
            
        }

        switch(c)
        {
            case '1':
                cout << "Enter Title: ";
                getline(cin, title);
                break;

            case '2': {
                cout << "Enter ISBN: ";
                string newISBN;
                getline(cin, newISBN);
                if (newISBN.length() > 13) newISBN = newISBN.substr(0,13);

                bool dup = false;
                for (int i = 0; i < books.size(); i++){
                    if (i == index) continue;  // allow same book
                    if (books[i].getISBN() == newISBN){
                        dup = true;
                        break;
                    }
                }

                if (dup){
                    cout << "ERROR: Duplicate ISBN.\nPress Enter.";
                    pause();
                } else {
                    isbn = newISBN;
                }
                break;
            }

            case '3':
                cout << "Enter Author: ";
                getline(cin, author);
                break;

            case '4':
                cout << "Enter Publisher: ";
                getline(cin, publisher);
                break;

            case '5':
                cout << "Enter Date Added: ";
                getline(cin, dateAdded);
                break;

            case '6':
                cout << "Quantity: ";
                while (!(cin >> qty)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Invalid. Enter number: ";
                }
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                break;

            case '7':
                cout << "Wholesale: ";
                while (!(cin >> wholesale)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Invalid. Enter number: ";
                }
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                break;

            case '8':
                cout << "Retail: ";
                while (!(cin >> retail)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Invalid. Enter number: ";
                }
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                break;

            case '9': {
                // SAVE CHANGES
                bk.setTitle(title);
                bk.setISBN(isbn);
                bk.setAuthor(author);
                bk.setPub(publisher);
                bk.setDateAdded(dateAdded);
                bk.setQtyOnHand(qty);
                bk.setWholesale(wholesale);
                bk.setRetail(retail);

                cout << "Book updated. Press Enter.";
                pause();
                return;
            }

            case '0':
                return;
        }

    } while (c != '0');
}


void deleteBook(vector<bookType>& books){

    char c = '0';

    do {
    if (books.size() == 0){
        cout << "\x1B[2J\x1B[H";
        cout << "No books in database. Press Enter.";
        pause();
        return;
    }

    // Step 1 — Select book using lookup
    int index = lookUpBook(books);

    string choice;
    if(index >= 0){
    // Step 2 — Confirm delete
    cout << "\x1B[2J\x1B[H";
    cout << "Are you sure you want to delete:\n";
    cout << "  \"" << books[index].getTitle() << "\"\n";
    cout << "(Y/N): ";

    
    getline(cin, choice);

    if (choice.length() > 0 && (choice[0] == 'Y' || choice[0] == 'y')){
        // Step 3 — Delete book
        books.erase(books.begin() + index);

        cout << "\nBook deleted. Press Enter.";
        pause();
        
    }
    else{
        cout << "\nDeletion cancelled. Press Enter.";
        pause();
        
    }
    }
    
    cout << "Edit another? (y/n)\n";
    getline(cin, choice);
    if (choice.length() > 0 && (choice[0] == 'Y' || choice[0] == 'y')){
        
    }
    else{
        c = 'E';

    }

} while (c != 'E' );
return;
}



// ========================= PAUSE ========================= //

void pause(){
    cin.get();
}
