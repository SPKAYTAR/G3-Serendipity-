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
#include "cashier.h"

int main(){
    char c;
    string input;
    do {
		  c = '0';
        cout << "\x1B[2J\x1B[H";
        cout << "==============================\n";
        cout << "Serendipity Booksellers\n";
        cout << "Main Menu\n";
        cout << "------------------------------\n";
        cout << "1. Cashier Module\n";
        cout << "2. Inventory menu\n";
        cout << "3. Report Module\n";
        cout << "4. Exit\n";
        cout << "------------------------------\n";
        cout << "Enter choice: ";

        getline(cin, input);

    if (input.length() == 1 && isdigit(input[0])) {
    c = input[0];
    
    }   

        switch(c){

            case '1': {
                cashier();
                break;
            }

            case '2': {
                invMenu();
                break;
            }

            case '3': {
                reports();
                break;
            }

            case '4': {
                break;
            }
            default: {
                cout << "\x1B[2J\x1B[H";
                cout << "Invalid entry, enter a value 1 -> 4, press enter to continue.";
                pause();
                break;

            }
        }
    }while (c != '4');

    return 0;
}
