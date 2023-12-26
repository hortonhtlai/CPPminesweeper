#include <iostream>
#include "field.h"
#include "inputHandler.h"

int main()
{
    int fieldWidth = 10;
    int fieldHeight = 10;
    int bombRate = 30;

    Field gameArea = Field(fieldHeight, fieldWidth, bombRate);
    InputHandler inputHandler(fieldHeight, fieldWidth);

    bool gameEnded = false;

    while (!gameEnded) {
        gameArea.displayField();
        gameEnded = inputHandler.getInput();
    };
};