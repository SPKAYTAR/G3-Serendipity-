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
#include "reports.h"
#include "invmenu.h"



void reports(){
    string input;
    char c;
    do{
		  c = '0';
        cout << "\x1B[2J\x1B[H";
        cout << "==============================\n";
        cout << "Serendipity Booksellers\n";
        cout << "Reports\n";
        cout << "------------------------------\n";
        cout << "1. Listing report\n";
        cout << "2. Wholesale report\n";
        cout << "3. Retail report\n";
        cout << "4. Quantity report\n";
        cout << "5. Cost report\n";
        cout << "6. Age report\n";
        cout << "7. Return to the Main Menu\n";
        cout << "------------------------------\n";
        cout << "Enter choice: ";
        
        getline(cin, input);

    if (input.length() == 1 && isdigit(input[0])) {
    c = input[0];
    
    }

        switch(c){

            case '1': {
                repListing();
                break;
            }

            case '2': {
                repWholesale();
                break;
            }

            case '3': {
                repRetail();
                break;
            }

            case '4': {
                repQty();
                break;
            }

            case '5': {
                repCost();
                break;
            }

            case '6': {
                repAge();
                break;
            }

            case '7': {
                break;
            }

            default :{
                cout << "\x1B[2J\x1B[H";
                cout << "Invalid entry, enter a value 1 -> 7, press enter to continue.";
                pause();
                break;
            }
        }
    }while( c != '7');
}
void repListing(){
    cout << "\x1B[2J\x1B[H";
    cout << "=== Inventory Listing ===\n";
    cout << "[stub] Not implemented yet. Press Enter to continue.\n\n";
    pause();
}

void repWholesale(){
    cout << "\x1B[2J\x1B[H";
    cout << "=== Inventory Wholesale Value ===\n";
    cout << "[stub] Not implemented yet. Press Enter to continue.\n\n";
    pause();
}

void repRetail(){
    cout << "\x1B[2J\x1B[H";
    cout << "=== Inventory Retail Value ===\n";
    cout << "[stub] Not implemented yet. Press Enter to continue.\n\n";
    pause();
}

void repQty(){
    cout << "\x1B[2J\x1B[H";
    cout << "=== Listing by Quantity ===\n";
    cout << "[stub] Not implemented yet. Press Enter to continue.\n\n";
    pause();
}

void repCost(){
    cout << "\x1B[2J\x1B[H";
    cout << "=== Listing by Cost ===\n";
    cout << "[stub] Not implemented yet. Press Enter to continue.\n\n";
    pause();
}

void repAge(){
    cout << "\x1B[2J\x1B[H";
    cout << "=== Listing by Age ===\n";
    cout << "[stub] Not implemented yet. Press Enter to continue.\n\n";
    pause();
}

