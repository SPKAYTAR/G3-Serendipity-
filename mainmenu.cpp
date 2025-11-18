/*********************************************************************
* CS1B – G2: Serendipity
*  Partner A: Sean Hanabusa (ID) — role: Cashier.cpp
*  Partner B: Kayden Tarvaran (ID) — role: invmenu.cpp, main.cpp, reports.cpp
*  Date: 2025‑09‑18
*  Purpose: Menu navigation and validation practice: loop Main/Inventory/Reports, call function stubs, and print a two-decimal cashier test receipt
*  Build:   g++ -std=c++20 mainmenu.cpp bookType.cpp cashier.cpp invmenu.cpp reports.cpp -o serendipity
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
#include "bookType.h"

int main() {

    vector<bookType> database;

    char c;
    string input;

    do {
        c = '0';
        cout << "\033[H\033[J" << flush;

        cout << setfill('*') << setw(80) << "*" << endl;
        cout << setfill(' ');

        cout << "*" << setw(78) << " " << "*" << endl;
        cout << left << "*  " << setw(76) << "Serendipity Booksellers" << "*" << endl;
        cout << left << "*  " << setw(76) << "Main Menu" << "*" << endl;
        cout << "*" << setw(78) << " " << "*" << endl;
        cout << left << "*  " << setw(76) << "------------------------------" << "*" << endl;
        cout << left << "*  " << setw(76) << "1. Cashier Module" << "*" << endl;
        cout << left << "*  " << setw(76) << "2. Inventory Menu" << "*" << endl;
        cout << left << "*  " << setw(76) << "3. Report Module" << "*" << endl;
        cout << left << "*  " << setw(76) << "4. Exit" << "*" << endl;
        cout << left << "*  " << setw(76) << "------------------------------" << "*" << endl;
        cout << left << "*  " << setw(76) << "Enter choice:" << "*" << endl;
        cout << setfill('*') << setw(80) << "*" << endl;

        cout << "\x1B[2A";
        cout << "\x1B[16C";

        getline(cin, input);

        if (input.length() == 1 && isdigit(input[0])) {
            c = input[0];
        }

        switch(c) {

            case '1':
                cashier();
                break;

            case '2':
                invMenu(database);
                break;

            case '3':
                reports();
                break;

            case '4':
                break;

            default:
                cout << "\x1B[2J\x1B[H";
                cout << "Invalid entry, enter a value 1 -> 4, press enter to continue.";
                cin.get();
                break;
        }

    } while (c != '4');

    return 0;
}
