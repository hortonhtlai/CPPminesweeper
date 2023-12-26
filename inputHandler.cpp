#include "inputHandler.h"
#include <string>
#include <iostream>

using namespace std;

InputHandler::InputHandler(int fieldHeight, int fieldWidth) {
    this->fieldHeight = fieldHeight;
    this->fieldWidth = fieldWidth;
};

bool InputHandler::getInput() {
    string action;
    int rowNum;
    int colNum;

    cout << "Choose an action (mark, unmark, reveal): ";
    cin >> action;
    cout << "Enter a row number: ";
    cin >> rowNum;
    cout << "Enter a col number: ";
    cin >> colNum;

    if (rowNum < 1 || rowNum > fieldHeight)
    {
        cout << "row number is invalid" << endl;
        return false;
    }

    if (colNum < 1 || colNum > fieldWidth)
    {
        cout << "col number is invalid" << endl;
        return false;
    }

    if (action == "mark") {

    } else if (action == "unmark") {

    } else if (action == "reveal") {

    } else {
        cout << "action is invalid" << endl;
    }
};