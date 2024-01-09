
#include "field.h"
#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

Field::Field(int fieldHeight, int fieldWidth, int bombRate) {
    gameArea = vector<vector<char>>(fieldHeight, vector<char>(fieldWidth, '?'));

    srand(312312312);

    hiddenTiles = fieldHeight * fieldWidth;

    for (int rowNum = 0; rowNum < fieldHeight; rowNum++) {
        for (int colNum = 0; colNum < fieldWidth; colNum++) {
            double randNum = (double) rand() / (double) RAND_MAX;
            if (randNum < (double) bombRate / 100.0) {
                bombTiles.insert(pair<int, int>(rowNum, colNum));
            }
        }
    }
};

void Field::displayField() {
    cout << endl;
    for (unsigned int rowNum = 0; rowNum < gameArea.size(); rowNum++) {
        for (unsigned int colNum = 0; colNum < gameArea[0].size(); colNum++) {
            cout << gameArea[rowNum][colNum] << " ";
        }
        cout << endl;
    }
};

bool Field::mark(int rowNum, int colNum) {
    if (gameArea[rowNum][colNum] == '?') {
        gameArea[rowNum][colNum] = '*';
    }
    return false;
};

bool Field::unmark(int rowNum, int colNum) {
    if (gameArea[rowNum][colNum] == '*') {
        gameArea[rowNum][colNum] = '?';
    }
    return false;
};

bool Field::reveal(int rowNum, int colNum) {
    if (bombTiles.find(pair<int, int>(rowNum, colNum)) != bombTiles.end()) {
        return true;
    }

    if (gameArea[rowNum][colNum] != '?') {
        return false;
    }

    stack<pair<int, int>> tileStack;
    tileStack.push(pair<int, int>(rowNum, colNum));

    while (!tileStack.empty()) {
        pair<int, int> currTile = tileStack.top();
        tileStack.pop();
        int currRow = currTile.first;
        int currCol = currTile.second;

        if (currRow >= 0 && currRow < (int) gameArea.size() && currCol >= 0 && currCol < (int) gameArea[0].size() && gameArea[currRow][currCol] == '?') {
            gameArea[currRow][currCol] = '0' + getAdjBombNum(currRow, currCol);
            hiddenTiles--;
            if (gameArea[currRow][currCol] == '0') {
                tileStack.push(pair<int, int>(currRow - 1, currCol));
                tileStack.push(pair<int, int>(currRow + 1, currCol));
                tileStack.push(pair<int, int>(currRow, currCol - 1));
                tileStack.push(pair<int, int>(currRow, currCol + 1));
            }
        }
    }
    return false;
};

int Field::getAdjBombNum(int currRow, int currCol) {
    int count = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) continue;
            if (currRow + i < 0 || currRow + i >= (int) gameArea.size() || currCol + j < 0 || currCol + j >= (int) gameArea[0].size()) continue;
            if (bombTiles.find(pair<int, int>(currRow + i, currCol + j)) != bombTiles.end()) count++;
        }
    }
    return count;
};

bool Field::gameWon() {
    return hiddenTiles == (int) bombTiles.size();
}