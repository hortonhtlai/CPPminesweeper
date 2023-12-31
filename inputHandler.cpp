#include "InputHandler.h"
#include <string>
#include <iostream>
#include "field.h"

using namespace std;

InputHandler::InputHandler(int fieldHeight, int fieldWidth, Field *gameArea) {
    this->fieldHeight = fieldHeight;
    this->fieldWidth = fieldWidth;
    this->gameArea = gameArea;
};

bool InputHandler::getInput(clock_t &lastMove, int interval) {
    string action;
    int rowNum;
    int colNum;

    cout << endl << "Choose an action (mark, unmark, reveal): ";
    cin >> action;
    cout << "Enter a row number: ";
    cin >> rowNum;
    cout << "Enter a col number: ";
    cin >> colNum;
    cout << endl;

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

    rowNum = rowNum - 1;
    colNum = colNum - 1;

    if (action == "mark") 
    {
        return gameArea->mark(rowNum, colNum);
    } 
    else if (action == "unmark") 
    {
        return gameArea->unmark(rowNum, colNum);
    } 
    else if (action == "reveal") 
    {
        if ((clock() - lastMove) / (double) CLOCKS_PER_SEC > interval) {
            cout << "You waited too long" << endl;
            return true;
        }

        bool result = gameArea->reveal(rowNum, colNum);
        if (result == false) {
            lastMove = clock();
        } else {
            cout << "You hit a bomb" << endl;
        }
        return result;
    }
    else 
    {
        cout << "action is invalid" << endl;
        return false;
    }
};