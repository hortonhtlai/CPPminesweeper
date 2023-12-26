#include <string>
#include <iostream>
#include "field.h"

using namespace std;

class InputHandler {
    public:
        InputHandler(int fieldHeight, int fieldWidth, Field *gameArea);
        bool getInput();
    
    private:
        int fieldHeight;
        int fieldWidth;
        Field *gameArea;
};