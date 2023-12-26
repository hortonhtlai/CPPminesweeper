
#include "field.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Field::Field(int fieldHeight, int fieldWidth, int bombRate) {
    gameArea = vector<vector<char>>(fieldHeight, vector<char>(fieldWidth, '?'));

    for (int rowNum = 0; rowNum < fieldHeight; rowNum++) {
        for (int colNum = 0; colNum < fieldWidth; colNum++) {
            double randNum = rand() / RAND_MAX;
            if (randNum < bombRate) {
                bombTiles.insert(pair<int, int>(rowNum, colNum));
            }
        }
    }
};

void Field::displayField() {
    for (unsigned int rowNum = 0; rowNum < gameArea.size(); rowNum++) {
        for (unsigned int colNum = 0; colNum < gameArea[0].size(); colNum++) {
            cout << gameArea[rowNum][colNum] << " ";
        }
        cout << endl;
    }
};