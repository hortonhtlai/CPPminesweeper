#include <string>
#include <iostream>

using namespace std;

class InputHandler {
    public:
        InputHandler(int fieldHeight, int fieldWidth);
        bool getInput();
    
    private:
        int fieldHeight;
        int fieldWidth;
};