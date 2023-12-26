#include <iostream>
#include "field.h"

int main()
{
    int fieldWidth = 10;
    int fieldHeight = 10;
    int bombRate = 30;

    Field gameArea = Field(fieldHeight, fieldWidth, bombRate);

    bool gameEnded = false;

    while (!gameEnded) {
        gameArea.displayField();
    };
};