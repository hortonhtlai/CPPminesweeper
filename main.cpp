#include <iostream>
#include "field.h"
#include "InputHandler.h"

using namespace std;

int main(int argc, char **argv)
{
    int fieldWidth = 10;
    int fieldHeight = 10;
    int bombRate = 10;
    int interval = 30;
    bool wantToPlay = true;

    while (wantToPlay) {
        Field gameArea = Field(fieldHeight, fieldWidth, bombRate);
        InputHandler inputHandler = InputHandler(fieldHeight, fieldWidth, &gameArea);

        bool gameEnded = false;

        clock_t start = clock();
        clock_t lastMove = start;
        double duration;

        while (!gameEnded) {
            gameArea.displayField();
            gameEnded = inputHandler.getInput(lastMove, interval);
            gameEnded = gameEnded || gameArea.gameWon();
        };

        duration = (clock() - start) / (double) CLOCKS_PER_SEC;

        if (gameArea.gameWon()) {
            cout << "You won" << endl;
        } else {
            cout << "You lost" << endl;
        }
        cout << "You survived for " << duration << " s" << endl;

        cout << "Play again? (Y/N)" << endl;
        string answer;
        cin >> answer;
        if (answer != "Y") {
            wantToPlay = false;
        }
    }
};