#include <iostream>
#include <map>
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
    map<double, vector<string>> leaderboard;

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

        cout << endl << "Name for leaderboard?" << endl;
        string name;
        cin >> name;
        leaderboard[duration].push_back(name);
        cout << endl << "Leaderboard by Survival Time" << endl;
        for (auto iter = leaderboard.rbegin(); iter != leaderboard.rend(); iter++) {
            cout << iter->first << " s" << endl;
            for (string &name : iter->second) {
                cout << name << " ";
            }
            cout << endl;
        }

        cout << endl << "Play again? (Y/N)" << endl;
        string answer;
        cin >> answer;
        if (answer != "Y") {
            wantToPlay = false;
        }
    }
};