/*********************************************************************
* CS1B – G2: Serendipity
*  Partner A: Sean Hanabusa (ID) — role: Cashier.cpp
*  Partner B: Kayden Tarvaran (ID) — role: invmenu.cpp, main.cpp, reports.cpp
*  Date: 2025‑09‑18
*  Purpose: Menu navigation and validation practice: loop Main/Inventory/Reports, call function stubs, and print a two-decimal cashier test receipt
*  Build:   g++ -std=c++20 mainmenu.cpp cashier.cpp invmenu.cpp reports.cpp -o serendipity
***********************************************************************/


#include <iostream>
#include <iomanip>
#include <cctype>
#include <vector>
#include <limits>
using namespace std;
#include "invmenu.h"

void invMenu(){
    string input;
    char c;
    do{
	 c = '0';
    cout << "\x1B[2J\x1B[H";
    cout << "==============================\n";
    cout << "Serendipity Booksellers\n";
    cout << "Inventory Database\n";
    cout << "------------------------------\n";
    cout << "1. Look Up a Book\n";
    cout << "2. Add a Book\n";
    cout << "3. Edit a Book's Record\n";
    cout << "4. Delete a Book\n";
    cout << "5. Return to the Main Menu\n";
    cout << "------------------------------\n";
    cout << "Enter choice: ";

    getline(cin, input);

    if (input.length() == 1 && isdigit(input[0])) {
    c = input[0];
    
    }

    switch(c){

        case '1': {
            lookUpBook();
            break;
        }
        case '2': {
            addBook();
            break;
        } 
        case '3': {
            editBook();
            break;
        }
        case '4': {
            deleteBook();
            break;
        }
        case '5': {
            break;
        }
        default: {
            cout << "\x1B[2J\x1B[H";
            cout << "Invalid entry, enter a value 1 -> 5, press enter to continue.";
            pause();
            break;
        }
                
    }
}while( c != '5');
    
    
}

void lookUpBook(){
    cout << "\x1B[2J\x1B[H";
    cout << "=== Look Up a Book ===\n";
    cout << "[stub] Feature not implemented yet, Press enter to continue\n\n";
    pause();
}

void addBook(){
    cout << "\x1B[2J\x1B[H";
    cout << "=== Add a Book ===\n";
    cout << "[stub] Feature not implemented yet. Press Enter to continue.\n\n";
    pause();
}

void editBook(){
    cout << "\x1B[2J\x1B[H";
    cout << "=== Edit a Book's Record ===\n";
    cout << "[stub] Feature not implemented yet. Press Enter to continue.\n\n";
    pause();
}

void deleteBook(){
    cout << "\x1B[2J\x1B[H";
    cout << "=== Delete a Book ===\n";
    cout << "[stub] Feature not implemented yet. Press Enter to continue.\n\n";
    pause();
}

void pause(){
  cin.get();
}
