#include <iostream>
#include "field.h"
#include "InputHandler.h"

using namespace std;

int main()
{
    int fieldWidth = 10;
    int fieldHeight = 10;
    int bombRate = 10;

    Field gameArea = Field(fieldHeight, fieldWidth, bombRate);
    InputHandler inputHandler = InputHandler(fieldHeight, fieldWidth, &gameArea);

    bool gameEnded = false;

    while (!gameEnded) {
        gameArea.displayField();
        gameEnded = inputHandler.getInput();
        gameEnded = gameEnded || gameArea.gameWon();
    };

    gameArea.displayField();
    if (gameArea.gameWon()) {
        cout << "You Won" << endl;
    } else {
        cout << "You hit a bomb" << endl;
    }
};