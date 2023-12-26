#ifndef FIELD
#define FIELD

#include <vector>
#include <set>

using namespace std;

class Field {
    public:
        Field(int fieldWidth, int fieldHeight, int bombRate);
        void displayField();
        bool mark(int rowNum, int colNum);
        bool unmark(int rowNum, int colNum);
        bool reveal(int rowNum, int colNum);
        bool gameWon();
    
    private:
        vector<vector<char>> gameArea;
        set<pair<int, int>> bombTiles;
        int getAdjBombNum(int currRow, int currCol);
        int hiddenTiles;
};

#endif