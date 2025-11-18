/*********************************************************************
* CS1B – G4: Serendipity
*  Partner A: Kayden Tarvaran (1250210) — 
*  Date: 2025‑011‑17
*  Purpose: Complete the Inventory features Edit Book and Delete Book using either a std::vector<bookType> or a raw array bookType books[] 
*  with a num_records counter. Document the project with Doxygen and demo your work in class.
*  Build:   g++ -std=c++20 mainmenu.cpp bookType.cpp cashier.cpp invmenu.cpp reports.cpp -o serendipity
***********************************************************************/
#ifndef CASHIER_H
#define CASHIER_H

#include <vector>
#include "bookType.h"

void cashier();

bookType getBookInfo();

void displayCashier(const bookType& book,
                    double subtotal,
                    double tax,
                    double total);

#endif
