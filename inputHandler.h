#include <string>
#include <iostream>
#include "field.h"

using namespace std;

class InputHandler {
    public:
        InputHandler(int fieldHeight, int fieldWidth, Field *gameArea);
        bool getInput(clock_t &lastMove, int interval);
    
    private:
        int fieldHeight;
        int fieldWidth;
        Field *gameArea;
};