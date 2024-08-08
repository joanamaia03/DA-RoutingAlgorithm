#ifndef DA_PROJECT_MENU_H
#define DA_PROJECT_MENU_H

#include <iostream>
#include <string>
#include "data_structures/reader.h"
#include "data_structures/Graph.h"
using namespace std;

///This class is responsible for reading the user's inputs and allowing them to access all of its functionality.
class menu {
public:
    ///default constructor
    ///
    ///O(1) complexity.
    menu();
    ///Has the function of building the main menu
    ///
    ///O(1) complexity.
    void mainMenu();
    ///Has the function of showing the user the main menu
    ///
    ///O(1) complexity.
    static void mainMenuDisplay();
    ///Has the function of reading menu inputs that are integers
    ///
    ///O(1) complexity.
    static int readInteger(const string& x);
private:
    Reader reader;
};


#endif //DA_PROJECT_MENU_H
